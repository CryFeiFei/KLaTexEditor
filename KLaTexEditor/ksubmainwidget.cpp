#include "ksubmainwidget.h"
#include "ui_ksubmainwidget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTimer>
#include <QtWebEngine>
#include <QtWebEngineWidgets/QWebEngineView>

KSubMainWidget::KSubMainWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::KSubMainWidget)
{
	ui->setupUi(this);
	m_webView = new QWebEngineView(this);
	ui->webMainLayout->addWidget(m_webView);
	ui->webMainLayout->setMargin(0);

	QFile file(":/html/resource/latex.html");
	m_webView->load(QUrl("qrc:/html/resource/latex.html"));


	m_mathjaxView = new QWebEngineView(this);
	ui->webMainLayout->addWidget(m_mathjaxView);
	m_mathjaxView->load(QUrl("qrc:/html/resource/mathjax1.html"));

	m_refershTimer = new QTimer(this);
	connect(ui->textEdit, SIGNAL(textChanged()), SLOT(refershStart()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(refershFormula()));
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

	m_strFormula = strFormat;

	strFormat.replace("\\", "\\\\");

	//delete space
//	strFormatA.remove(QRegExp("\\s"));
	strFormat.remove(QRegExp("[\r\n]"));
#ifdef QT_DEBUG
	qDebug()<<strFormat<<endl;
#endif

	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormat);

#ifdef QT_DEBUG
	qDebug()<<runJS<<endl;
#endif
	m_webView->page()->runJavaScript(runJS);
}
