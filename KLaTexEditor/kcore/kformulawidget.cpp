#include "kformulawidget.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QSplitter>
#include "kformulatextedit.h"
#include "kwebtoolwidget.h"
#include <QFileDialog>
#include <QApplication>
#include "kglobal.h"
#include <QClipboard>
#include "kformulatitlewidget.h"

//#include <QSvgRenderer>
//#include <QSvgGenerator>

KFormulaWidget::KFormulaWidget(QWidget *parent/* = nullptr*/, QString strUrl/* = QString()*/, QString strTitle/* = QString()*/)
: QWidget(parent), m_strUrl(strUrl), m_strTitle(strTitle)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	KFormulaTitleWidget* title = new KFormulaTitleWidget(strTitle, this);
	title->setFixedHeight(KStyle::dpiScale(25));

	m_fontSize = QString("normalsize");
	m_fontType = QString("");

	m_webView = new QWebEngineView(this);
	m_webView->load(QUrl(m_strUrl));
	m_webView->setMinimumSize(KStyle::dpiScale(380), KStyle::dpiScale(120));
	m_webView->setEnabled(false);
	m_webView->setContextMenuPolicy(Qt::NoContextMenu);
	m_webView->resize(KStyle::dpiScale(380), KStyle::dpiScale(280));

	KWebToolWidget* webToolWidget = new KWebToolWidget(this);
	webToolWidget->setStyleSheet("background-color:gray;");
	webToolWidget->setFixedHeight(KStyle::dpiScale(30));

	m_textEdit = new KFormulaTextEdit(this);
	QSplitter* splitter = new QSplitter(Qt::Vertical, this);
	splitter->addWidget(m_webView);
	splitter->addWidget(webToolWidget);
	splitter->addWidget(m_textEdit);
	splitter->setChildrenCollapsible(false);

	setMinimumWidth(KStyle::dpiScale(380));
	mainLayout->addWidget(title);
	mainLayout->addWidget(splitter);
	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);

	m_refershTimer = new QTimer(this);

	connect(m_textEdit, SIGNAL(textChanged()), SLOT(refershStart()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(refershFormula()));
	connect(webToolWidget, &KWebToolWidget::textColorChanged, this, &KFormulaWidget::textColorChange);
	connect(webToolWidget, &KWebToolWidget::bgColorChanged, this, &KFormulaWidget::bgColorChange);
	connect(webToolWidget, &KWebToolWidget::fontSizeChanged, this, &KFormulaWidget::fontSizeChange);
	connect(webToolWidget, &KWebToolWidget::fontTypeChanged, this, &KFormulaWidget::fontTypeChange);
	connect(webToolWidget, &KWebToolWidget::copyToClipboard, this, &KFormulaWidget::copyToClipboard);
	connect(webToolWidget, &KWebToolWidget::saveAs, this, &KFormulaWidget::saveAs);
	auto fReload = [this] ()
	{
		m_webView->reload();
		refershFormula();
	};
	connect(title, &KFormulaTitleWidget::refresh, fReload);


	m_menu = new QMenu(this);
	QAction* cp2clip = new QAction(tr("&Copy to Clipboard"), m_menu);
	m_menu->addAction(cp2clip);

	QAction* saveAs = new QAction(tr("&Save As"), m_menu);
	m_menu->addAction(saveAs);

	QAction* saveAsPdf = new QAction(tr("&Save As PDF"), m_menu);
	m_menu->addAction(saveAsPdf);

	connect(cp2clip, &QAction::triggered, this, &KFormulaWidget::copyToClipboard);
	connect(saveAs, &QAction::triggered, this, &KFormulaWidget::saveAs);
	connect(saveAsPdf, &QAction::triggered, this, &KFormulaWidget::saveAsPdf);
}

KFormulaWidget::~KFormulaWidget()
{

}

void KFormulaWidget::contextMenuEvent(QContextMenuEvent *)
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
void KFormulaWidget::updateWebView(QString strFormula)
{
	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormula);

	m_webView->page()->runJavaScript(runJS);
}

void KFormulaWidget::refershStart()
{
	//开始启动刷新
	if (m_refershTimer->isActive())
		return;

	m_refershTimer->start(1000);
}

void KFormulaWidget::refershFormula()
{
	QString strFormat = m_textEdit->toPlainText();

	// 文本没有变化的话，不用刷新。
	if (m_strFormula == m_textEdit->toPlainText())
		return;

	m_strFormula = strFormat;

	doRefersh();
}

void KFormulaWidget::doRefersh()
{
	QString strFormat = m_strFormula;

	_dealLatexString(strFormat);
	_dealFontSizeTypeString(strFormat);


	if (!m_textColor.isEmpty())
		strFormat = QString("\\\\color {%1}{%2}").arg(m_textColor).arg(strFormat);

	_addOutlineString(strFormat);
	updateWebView(strFormat);
}

void KFormulaWidget::_dealLatexString(QString &strLatex)
{
	strLatex.replace("\\", "\\\\");
	//delete space
//	strFormatA.remove(QRegExp("\\s"));
	strLatex.remove(QRegExp("[\r\n]"));
//	strLatex.insert(0, QString("$$"));
//	strLatex.append(QString("$$"));

//	return strLatex;
}

void KFormulaWidget::_addOutlineString(QString &strLatex)
{
	strLatex.insert(0, QString("$$"));
	strLatex.append(QString("$$"));
}

void KFormulaWidget::_dealFontSizeTypeString(QString &strLatex)
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

void KFormulaWidget::textColorChange(const QColor &color)
{
//	m_textColor = color.name(QColor::HexRgb);
//	qDebug()<<m_textColor<<endl;
//	doRefersh();
//	\color {#rgb}{text}
//	m_textColor = QString("\\color {#%1}{}")
	QString strColor = color.name(QColor::HexRgb);
	QString runJS = QString("changeFontColor(\"%1\")").arg(strColor);
	m_webView->page()->runJavaScript(runJS);
}

void KFormulaWidget::bgColorChange(const QColor &color)
{
	QString strColor = color.name(QColor::HexRgb);

	QString runJS = QString("changeBGColor(\"%1\")").arg(strColor);

	m_webView->page()->runJavaScript(runJS);
}

void KFormulaWidget::fontSizeChange(const QString &fs)
{
	m_fontSize = fs;
	doRefersh();
}

void KFormulaWidget::fontTypeChange(const QString &ft)
{
	if (ft == QString("normal"))
		m_fontType = "";
	else
		m_fontType = ft;

	doRefersh();
}

void KFormulaWidget::copyToClipboard()
{
	QImage img(m_webView->size(), QImage::Format_ARGB32_Premultiplied);
	qDebug()<<img.dotsPerMeterX()<<endl;
	qDebug()<<img.dotsPerMeterY()<<endl;
	m_webView->render(&img);
	QApplication::clipboard()->setImage(img);
}

void KFormulaWidget::saveAs()
{
	QImage img(m_webView->size(), QImage::Format_ARGB32_Premultiplied);
	img.setDotsPerMeterX(6000);
	img.setDotsPerMeterY(6000);
	m_webView->render(&img);
	QString filter = "Images (*.png);;Images (*.jpg)";
	QString selectedFilter;
	QString strFileName = QFileDialog::getSaveFileName(nullptr, m_strTitle, QString(), filter, &selectedFilter);

	QFileInfo fileInfo(strFileName);
	QString strSuffix = fileInfo.suffix();
	img.save(strFileName, strSuffix.toStdString().c_str());
}

void KFormulaWidget::saveAsPdf()
{
	QString filter = "PDF (*.pdf);;";
	QString selectedFilter;
	QString strFileName = QFileDialog::getSaveFileName(nullptr, m_strTitle, QString(), filter, &selectedFilter);
	m_webView->page()->printToPdf(strFileName);
}
