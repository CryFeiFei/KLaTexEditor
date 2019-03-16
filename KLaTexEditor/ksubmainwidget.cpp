#include "ksubmainwidget.h"
#include "ui_ksubmainwidget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QWebPage>
#include <QWebFrame>
#include <QTimer>

KSubMainWidget::KSubMainWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::KSubMainWidget)
{
	ui->setupUi(this);
	ui->latexWebView->load(QUrl(":/html/resource/latex.html"));
	QFile file(":/html/resource/latex.html");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream textStream(&file);
		QString  str = textStream.readAll();
		QByteArray by = str.toUtf8();
		ui->latexWebView->setContent(by);
		file.close();
	}
	else
	{
		qDebug()<<" load html error"<<endl;
	}

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
//	QString strFormat = ui->textEdit->toPlainText();
//	QString str1 = "\\\\";
//	QString str2 = "\\\\\\\\";
//	qDebug()<<str1<<"		"<<str2<<endl;


//	QString strFormat = "c = \\\\pm\\\\sqrt{a^2 + b^2}";
//	qDebug()<<strFormat<<endl;


//	QString strFormat1 = "c = \pm\sqrt{a^2 + b^2}";
//	qDebug()<<strFormat1<<endl;
	// 文本没有变化的话，不用刷新。
	if (m_strFormula == ui->textEdit->toPlainText())
		return;

	QString strFormatA = ui->textEdit->toPlainText();
	m_strFormula = strFormatA;
	strFormatA.replace("\\", "\\\\");

	//delete space
	strFormatA.remove(QRegExp("\\s"));
	QWebFrame* webFrame =  ui->latexWebView->page()->currentFrame();
	QString jstest2 = QString("setLatexRenderByString(\"%1\")").arg(strFormatA);
//	qDebug()<<jstest2<<endl;
	webFrame->evaluateJavaScript(jstest2);
}
