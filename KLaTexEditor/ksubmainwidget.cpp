#include "ksubmainwidget.h"
#include "ui_ksubmainwidget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTimer>
#include <QSplitter>
#include <QtWebEngineWidgets/QWebEngineView>
#include "kglobal.h"

#include "kkatex/kkatexwidget.h"
#include "kmathjax/kmathjaxwidget.h"

KSubMainWidget::KSubMainWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::KSubMainWidget)
{
	ui->setupUi(this);
	m_katexWidget = new KKatexWidget(this);
//	ui->katexLayout->addWidget(m_katexWidget);
	m_mathjaxWidget = new KMathJaxWidget(this);
//	ui->mathjaxLayout->addWidget(m_mathjaxWidget);

	QSplitter* webSplitter = new QSplitter(ui->webWidget);
	webSplitter->addWidget(m_katexWidget);
	webSplitter->addWidget(m_mathjaxWidget);

	ui->webWidget->layout()->addWidget(webSplitter);

	QSplitter* mainSplitter = new QSplitter(Qt::Vertical, this);
	mainSplitter->addWidget(ui->webWidget);
	mainSplitter->addWidget(ui->textEdit);
	ui->verticalLayout->addWidget(mainSplitter);

	m_refershTimer = new QTimer(this);
	connect(ui->textEdit, SIGNAL(textChanged()), SLOT(refershStart()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(refershFormula()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(referMathJax()));

	connect(this, SIGNAL(updateFormula(QString)), m_katexWidget, SLOT(updateWebView(QString)));
	connect(this, SIGNAL(updateFormula(QString)), m_mathjaxWidget, SLOT(updateWebView(QString)));

	setMinimumWidth(KStyle::dpiScale(800));
//	ui->webMainLayout->setMargin(0);
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
