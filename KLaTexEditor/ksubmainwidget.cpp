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
//	m_webView->setFixedWidth(300);
//	ui->verticalLayout->addWidget(m_webView);
//	ui->verticalLayout->insertWidget(1, m_webView);
	ui->webMainLayout->addWidget(m_webView);

	QFile file(":/html/resource/latex.html");
	m_webView->load(QUrl("qrc:/html/resource/latex.html"));

	m_refershTimer = new QTimer(this);

	connect(ui->textEdit, SIGNAL(textChanged()), SLOT(refershStart()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(refershFormula()));
//	connect(ui->latexPushButton, &QPushButton::clicked, this, &KSubMainWidget::refershFormula);
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

	m_strFormula = strFormat;

//	m_strFormula = strFormatA;
	strFormat.replace("\\", "\\\\");

	//delete space
//	strFormatA.remove(QRegExp("\\s"));
	strFormat.remove(QRegExp("[\r\n]"));
	qDebug()<<strFormat<<endl;
	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormat);
	qDebug()<<runJS<<endl;
	m_webView->page()->runJavaScript(runJS);
}
