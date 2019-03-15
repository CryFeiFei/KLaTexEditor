#include "ksubmainwidget.h"
#include "ui_ksubmainwidget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QWebPage>
#include <QWebFrame>

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

	connect(ui->latexPushButton, SIGNAL(clicked()), this, SLOT(refershFormula()));
//	ui->latexWebView->setContent();
}

KSubMainWidget::~KSubMainWidget()
{
	delete ui;
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


	QString strFormatA = ui->textEdit->toPlainText();
	strFormatA.replace("\\", "\\\\");

	//delete space
	strFormatA.remove(QRegExp("\\s"));
	QWebFrame* webFrame =  ui->latexWebView->page()->currentFrame();
	QString jstest2 = QString("setLatexRenderByString(\"%1\")").arg(strFormatA);
//	qDebug()<<jstest2<<endl;
	webFrame->evaluateJavaScript(jstest2);
}
