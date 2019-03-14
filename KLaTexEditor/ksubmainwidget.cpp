#include "ksubmainwidget.h"
#include "ui_ksubmainwidget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

KSubMainWidget::KSubMainWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::KSubMainWidget)
{
	ui->setupUi(this);
	ui->latexWebView->load(QUrl(":/html/resource/latex.html"));
//	ui->latexWebView->setHtml(":/html/resource/latex.html");
	QFile file(":/html/resource/latex.html");
	if (file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream textStream(&file);
		QString  str = textStream.readAll();
		qDebug()<<"right"<<endl;
		qDebug()<<str<<endl;
		QByteArray by = str.toUtf8();
//		QByteArray by = textStream.readAll().toUtf8();
//		qDebug()<<textStream.readAll();
		ui->latexWebView->setContent(by);
		file.close();
	}
	else
	{
		qDebug()<<"error"<<endl;
	}
//	ui->latexWebView->setContent();
}

KSubMainWidget::~KSubMainWidget()
{
	delete ui;
}
