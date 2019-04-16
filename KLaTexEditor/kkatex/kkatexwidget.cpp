#include "kkatexwidget.h"
#include "kglobal.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSplitter>
#include "kformulatextedit.h"

#include "kwebtoolwidget.h"

#include <QSvgRenderer>
#include <QSvgGenerator>

KKatexWidget::KKatexWidget(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	QLabel* label = new QLabel(this);
	label->setText("katex");
	label->setFixedHeight(KStyle::dpiScale(20));

	m_webView = new QWebEngineView(this);
	m_webView->load(QUrl("qrc:/html/resource/katex.html"));
	m_webView->setEnabled(false);
	m_webView->setContextMenuPolicy(Qt::NoContextMenu);

	m_webView->setMinimumSize(KStyle::dpiScale(380), KStyle::dpiScale(120));
	m_webView->resize(KStyle::dpiScale(380), KStyle::dpiScale(280));

	KWebToolWidget* webToolWidget = new KWebToolWidget(this);
	webToolWidget->setStyleSheet("background-color:gray;");
	webToolWidget->setFixedHeight(KStyle::dpiScale(30));

	m_textEdit = new KFormulaTextEdit(this);

	QSplitter* mainSplitter = new QSplitter(Qt::Vertical, this);
	mainSplitter->addWidget(m_webView);
	mainSplitter->addWidget(webToolWidget);
	mainSplitter->addWidget(m_textEdit);
	mainSplitter->setChildrenCollapsible(false);

	this->setMinimumWidth(KStyle::dpiScale(380));
	mainLayout->addWidget(label);
	mainLayout->addWidget(mainSplitter);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(1);

	m_refershTimer = new QTimer(this);

	connect(m_textEdit, SIGNAL(textChanged()), SLOT(refershStart()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(refershFormula()));

	connect(webToolWidget, &KWebToolWidget::textColorChanged, this, &KKatexWidget::textColorChange);
//	connect(webToolWidget, &KWebToolWidget::bgColorChanged, this, todo)
	connect(webToolWidget, &KWebToolWidget::fontSizeChanged, this, &KKatexWidget::fontSizeChange);
	connect(webToolWidget, &KWebToolWidget::fontTypeChanged, this, &KKatexWidget::fontTypeChange);
//	connect(webToolWidget, &KWebToolWidget::copyToClipboard, this, todo)
//	connect(webToolWidget, &KWebToolWidget::saveAs, this, todo)

	m_menu = new QMenu(this);
	m_menu->addAction(new QAction(tr("&Open"), m_menu));
	m_menu->addAction(new QAction(tr("&Mark"), m_menu));
	m_menu->addAction(new QAction(tr("&Quit"), m_menu));
}

void KKatexWidget::contextMenuEvent(QContextMenuEvent *)
{

//	QSvgGenerator svgg;
//	svgg.setFileName("D:\\q.svg");
//	svgg.setSize(QSize(200, 200));
//	svgg.setViewBox(QRect(0, 0, 200, 200));
//	svgg.setTitle(tr("SVG Generator Example Drawing"));
//	svgg.setDescription(tr("An SVG drawing created by the SVG Generator "
//	"Example provided with Qt."));
//	QPainter pp(&svgg);
//	m_webView->render(&pp);
	m_menu->move(cursor().pos());
	m_menu->show();
}

void KKatexWidget::updateWebView(QString strFormula)
{
	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormula);

	m_webView->page()->runJavaScript(runJS);
}

void KKatexWidget::refershStart()
{
	//开始启动刷新
	if (m_refershTimer->isActive())
		return;

	m_refershTimer->start(1000);
}

void KKatexWidget::refershFormula()
{
	QString strFormat = m_textEdit->toPlainText();

	// 文本没有变化的话，不用刷新。
	if (m_strFormula == m_textEdit->toPlainText())
		return;

	m_strFormula = strFormat;

	doRefersh();
}

void KKatexWidget::doRefersh()
{
	QString strFormat = m_strFormula;

	_dealLatexString(strFormat);
	_dealFontSizeTypeString(strFormat);


	if (!m_textColor.isEmpty())
		strFormat = QString("\\\\color {%1}{%2}").arg(m_textColor).arg(strFormat);

	_addOutlineString(strFormat);
	updateWebView(strFormat);
}

void KKatexWidget::_dealLatexString(QString &strLatex)
{
	strLatex.replace("\\", "\\\\");
	//delete space
//	strFormatA.remove(QRegExp("\\s"));
	strLatex.remove(QRegExp("[\r\n]"));
//	strLatex.insert(0, QString("$$"));
//	strLatex.append(QString("$$"));

//	return strLatex;
}

void KKatexWidget::_addOutlineString(QString &strLatex)
{
	strLatex.insert(0, QString("$$"));
	strLatex.append(QString("$$"));
}

void KKatexWidget::_dealFontSizeTypeString(QString &strLatex)
{
	QString strFontProper;
	if (!m_fontSize.isEmpty())
	{
		strFontProper = QString("\\\\") + m_fontSize + QString(" ");
	}
	if (!m_fontType.isEmpty())
	{
		strFontProper = QString("\\\\") + m_fontType + QString(" ") + strFontProper;
	}

	strLatex = strFontProper + strLatex;
}

void KKatexWidget::textColorChange(const QColor &color)
{
	m_textColor = color.name(QColor::HexRgb);
	qDebug()<<m_textColor<<endl;
	doRefersh();
//	\color {#rgb}{text}
//	m_textColor = QString("\\color {#%1}{}")
}

void KKatexWidget::bgColorChange(const QColor &color)
{

}

void KKatexWidget::fontSizeChange(const QString &fs)
{
	m_fontSize = fs;
	doRefersh();
}

void KKatexWidget::fontTypeChange(const QString &ft)
{
	if (ft == QString("normal"))
		m_fontType = "";
	else
		m_fontType = ft;

	doRefersh();
}
