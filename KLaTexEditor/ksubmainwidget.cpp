#include "ksubmainwidget.h"
#include "ui_ksubmainwidget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTimer>
#include <QtWebEngineWidgets/QWebEngineView>

#include "kkatex/kkatexwidget.h"
#include "kmathjax/kmathjaxwidget.h"

KSubMainWidget::KSubMainWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::KSubMainWidget)
{
	ui->setupUi(this);
//	m_webView = new QWebEngineView(this);
//	ui->webMainLayout->addWidget(m_webView, 0, 0);
//	ui->katexLayout->addWidget(m_webView);
//	m_webView->load(QUrl("qrc:/html/resource/katex.html"));
	KKatexWidget* katexWidget = new KKatexWidget(this);
	ui->katexLayout->addWidget(katexWidget);

	KMathJaxWidget* kmathjaxWidget = new KMathJaxWidget(this);
	ui->mathjaxLayout->addWidget(kmathjaxWidget);
//	m_mathjaxView = new QWebEngineView(this);
//	ui->webMainLayout->addWidget(m_mathjaxView, 0, 1);
//	m_mathjaxView->load(QUrl("qrc:/html/resource/mathjax.html"));
//	ui->mathjaxLayout->addWidget(m_mathjaxView);
//	m_mathjaxView->setVisible(false);

	m_refershTimer = new QTimer(this);
	connect(ui->textEdit, SIGNAL(textChanged()), SLOT(refershStart()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(refershFormula()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(referMathJax()));

	connect(this, SIGNAL(updateFormula(QString)), katexWidget, SLOT(updateWebView(QString)));
	connect(this, SIGNAL(updateFormula(QString)), kmathjaxWidget, SLOT(updateWebView(QString)));

	ui->webMainLayout->setMargin(0);
}

KSubMainWidget::~KSubMainWidget()
{
	delete ui;
}

void KSubMainWidget::refershStart()
{
	//开始启动刷新
	if (m_refershTimer->isActive())
		return;

	m_refershTimer->start(1000);
}

void KSubMainWidget::refershFormula()
{
	QString strFormat = ui->textEdit->toPlainText();

	// 文本没有变化的话，不用刷新。
	if (m_strFormula == ui->textEdit->toPlainText())
		return;

//	m_strFormula = strFormat;
	strFormat = _dealLatexString(strFormat);

	emit updateFormula(strFormat);
//	strFormat.replace("\\", "\\\\");

//	//delete space
////	strFormatA.remove(QRegExp("\\s"));
//	strFormat.remove(QRegExp("[\r\n]"));
//	strFormat.insert(0, QString("$$"));
//	strFormat.append(QString("$$"));
//	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormat);

//	m_webView->page()->runJavaScript(runJS);
}

QString KSubMainWidget::_dealLatexString(QString &strLatex)
{
	strLatex.replace("\\", "\\\\");
	//delete space
//	strFormatA.remove(QRegExp("\\s"));
	strLatex.remove(QRegExp("[\r\n]"));
	strLatex.insert(0, QString("$$"));
	strLatex.append(QString("$$"));

	return strLatex;
}

// 这个必须控制刷新次数，要不然网页刷新有问题
void KSubMainWidget::referMathJax()
{
	QString strFormat = ui->textEdit->toPlainText();

	// 文本没有变化的话，不用刷新。
	if (m_strFormula == ui->textEdit->toPlainText())
		return;

	m_strFormula = strFormat;

	strFormat = _dealLatexString(strFormat);
	emit updateFormula(strFormat);
//	strFormat.replace("\\", "\\\\");
//	//delete space
////	strFormatA.remove(QRegExp("\\s"));
//	strFormat.remove(QRegExp("[\r\n]"));
//	strFormat.insert(0, QString("$$"));
//	strFormat.append(QString("$$"));

//	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormat);

//	m_mathjaxView->page()->runJavaScript(runJS);
}
