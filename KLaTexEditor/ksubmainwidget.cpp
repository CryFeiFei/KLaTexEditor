#include "ksubmainwidget.h"
#include "ui_ksubmainwidget.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTimer>
#include <QSplitter>
#include <QtWebEngineWidgets/QWebEngineView>
#include "kglobal.h"

//#include "kkatex/kkatexwidget.h"
//#include "kmathjax/kmathjaxwidget.h"
#include "kcore/kformulawidget.h"


#define MATHJAX_URL "qrc:/html/resource/mathjax.html"
#define KATEX_URL "qrc:/html/resource/katex.html"
KSubMainWidget::KSubMainWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::KSubMainWidget)
{
	ui->setupUi(this);
	m_katexWidget = new KFormulaWidget(this, KATEX_URL, "Katex");
	m_mathjaxWidget = new KFormulaWidget(this, MATHJAX_URL, "MathJax");

	QSplitter* webSplitter = new QSplitter(Qt::Horizontal, ui->webWidget);
	webSplitter->addWidget(m_katexWidget);
	webSplitter->addWidget(m_mathjaxWidget);

	ui->webWidget->layout()->addWidget(webSplitter);

	QSplitter* mainSplitter = new QSplitter(Qt::Vertical, this);
	mainSplitter->addWidget(ui->webWidget);
	ui->verticalLayout->addWidget(mainSplitter);

	setMinimumWidth(KStyle::dpiScale(850));
	setMinimumHeight(KStyle::dpiScale(400));
}

KSubMainWidget::~KSubMainWidget()
{
	delete ui;
}
