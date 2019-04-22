#include "kmathjaxwidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSplitter>
#include "kglobal.h"
#include "kwebtoolwidget.h"
#include "kformulatextedit.h"

KMathJaxWidget::KMathJaxWidget(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	QLabel* label = new QLabel(this);
	label->setText("mathjax");
	label->setFixedHeight(KStyle::dpiScale(20));
	m_fontSize = QString("normalsize");
	m_fontType = QString("");

	m_webView = new QWebEngineView(this);
	m_webView->load(QUrl("qrc:/html/resource/mathjax.html"));
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

	this->setMinimumWidth(KStyle::dpiScale(380));
	mainLayout->addWidget(label);
	mainLayout->addWidget(splitter);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(1);

	m_refershTimer = new QTimer(this);

	connect(m_textEdit, SIGNAL(textChanged()), SLOT(refershStart()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(refershFormula()));

	connect(webToolWidget, &KWebToolWidget::textColorChanged, this, &KMathJaxWidget::textColorChange);
//	connect(webToolWidget, &KWebToolWidget::bgColorChanged, this, todo)
	connect(webToolWidget, &KWebToolWidget::fontSizeChanged, this, &KMathJaxWidget::fontSizeChange);
	connect(webToolWidget, &KWebToolWidget::fontTypeChanged, this, &KMathJaxWidget::fontTypeChange);
//	connect(webToolWidget, &KWebToolWidget::copyToClipboard, this, todo)
	connect(webToolWidget, &KWebToolWidget::saveAs, this, &KMathJaxWidget::saveAs);
}

void KMathJaxWidget::updateWebView(QString strFormula)
{
	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormula);

	m_webView->page()->runJavaScript(runJS);
}

void KMathJaxWidget::refershStart()
{
	//开始启动刷新
	if (m_refershTimer->isActive())
		return;

	m_refershTimer->start(1000);
}

void KMathJaxWidget::refershFormula()
{
	QString strFormat = m_textEdit->toPlainText();

	// 文本没有变化的话，不用刷新。
	if (m_strFormula == m_textEdit->toPlainText())
		return;

	m_strFormula = strFormat;

	doRefersh();
//	_dealLatexString(strFormat);

//	if (!m_textColor.isEmpty())
//		strFormat = QString("\\\\color {%1}{%2}").arg(m_textColor).arg(strFormat);

//	_addOutlineString(strFormat);
//	updateWebView(strFormat);
}

void KMathJaxWidget::doRefersh()
{
	QString strFormat = m_strFormula;

	_dealLatexString(strFormat);
	_dealFontSizeTypeString(strFormat);


	if (!m_textColor.isEmpty())
		strFormat = QString("\\\\color {%1}{%2}").arg(m_textColor).arg(strFormat);

	_addOutlineString(strFormat);
	updateWebView(strFormat);
}

void KMathJaxWidget::_dealLatexString(QString &strLatex)
{
	strLatex.replace("\\", "\\\\");
	//delete space
//	strFormatA.remove(QRegExp("\\s"));
	strLatex.remove(QRegExp("[\r\n]"));
//	strLatex.insert(0, QString("$$"));
//	strLatex.append(QString("$$"));

//	return strLatex;
}

void KMathJaxWidget::_addOutlineString(QString &strLatex)
{
	strLatex.insert(0, QString("$$"));
	strLatex.append(QString("$$"));
}

void KMathJaxWidget::_dealFontSizeTypeString(QString &strLatex)
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

void KMathJaxWidget::textColorChange(const QColor &color)
{
	m_textColor = color.name(QColor::HexRgb);
	qDebug()<<m_textColor<<endl;
	doRefersh();
//	\color {#rgb}{text}
//	m_textColor = QString("\\color {#%1}{}")
}

void KMathJaxWidget::bgColorChange(const QColor &color)
{

}

void KMathJaxWidget::fontSizeChange(const QString &fs)
{
	m_fontSize = fs;
	doRefersh();
}

void KMathJaxWidget::fontTypeChange(const QString &ft)
{
	if (ft == QString("normal"))
		m_fontType = "";
	else
		m_fontType = ft;

	doRefersh();
}

void KMathJaxWidget::copyToClipboard()
{

}

void KMathJaxWidget::saveAs()
{
	QImage img(m_webView->size(), QImage::Format_ARGB32_Premultiplied);
	m_webView->render(&img);
	img.save("D:\\1.png", "png");
}
