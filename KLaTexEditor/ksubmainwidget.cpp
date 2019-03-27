#include "ksubmainwidget.h"
#include "ui_ksubmainwidget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTimer>
#include <QtWebEngineWidgets/QWebEngineView>

#include "kkatex/kkatexwidget.h"

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
	ui->webMainLayout->addWidget(katexWidget);

	m_mathjaxView = new QWebEngineView(this);
//	ui->webMainLayout->addWidget(m_mathjaxView, 0, 1);
	m_mathjaxView->load(QUrl("qrc:/html/resource/mathjax.html"));
	ui->mathjaxLayout->addWidget(m_mathjaxView);
//	m_mathjaxView->setVisible(false);

	m_refershTimer = new QTimer(this);
	connect(ui->textEdit, SIGNAL(textChanged()), SLOT(refershStart()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(refershFormula()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(referMathJax()));

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
//	if (m_strFormula == ui->textEdit->toPlainText())
//		return;

//	m_strFormula = strFormat;

	strFormat.replace("\\", "\\\\");

	//delete space
//	strFormatA.remove(QRegExp("\\s"));
	strFormat.remove(QRegExp("[\r\n]"));
#ifdef QT_DEBUG
	qDebug()<<strFormat<<endl;
#endif
	strFormat.insert(0, QString("$$"));
	strFormat.append(QString("$$"));
	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormat);

#ifdef QT_DEBUG
	qDebug()<<runJS<<endl;
#endif
	m_webView->page()->runJavaScript(runJS);
}

// 这个必须控制刷新次数，要不然网页刷新有问题
void KSubMainWidget::referMathJax()
{
	QString strFormat = ui->textEdit->toPlainText();

	// 文本没有变化的话，不用刷新。
	if (m_strFormula == ui->textEdit->toPlainText())
		return;

	m_strFormula = strFormat;

	strFormat.replace("\\", "\\\\");

	//delete space
//	strFormatA.remove(QRegExp("\\s"));
	strFormat.remove(QRegExp("[\r\n]"));
#ifdef QT_DEBUG
	qDebug()<<strFormat<<endl;
#endif
	strFormat.insert(0, QString("$$"));
	strFormat.append(QString("$$"));

	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormat);

#ifdef QT_DEBUG
	qDebug()<<runJS<<endl;
#endif
	m_mathjaxView->page()->runJavaScript(runJS);
}
