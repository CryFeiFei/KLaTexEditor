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

	QSplitter* webSplitter = new QSplitter(Qt::Horizontal, ui->webWidget);
	webSplitter->addWidget(m_katexWidget);
	webSplitter->addWidget(m_mathjaxWidget);

	ui->webWidget->layout()->addWidget(webSplitter);

	QSplitter* mainSplitter = new QSplitter(Qt::Vertical, this);
	mainSplitter->addWidget(ui->webWidget);
	ui->verticalLayout->addWidget(mainSplitter);

	setMinimumWidth(KStyle::dpiScale(800));
//	ui->webMainLayout->setMargin(0);
}

KSubMainWidget::~KSubMainWidget()
{
	delete ui;
}
