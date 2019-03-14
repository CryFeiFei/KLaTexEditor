#include "kmainwidget.h"
#include <QVBoxLayout>
#include <QSplitter>
#include <ktitlewidget.h>

KMainWidget::KMainWidget(QWidget *parent) : QWidget(parent)
{
	setObjectName("KMainWidget");
	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	// title bar
	m_titleBar = new KTitleWidget(this);
	connect(m_titleBar, SIGNAL(miniButtonClicked()), this, SLOT(ShowMiniSize()));
	connect(m_titleBar, SIGNAL(maxButtonClicked()), this, SLOT(ShowMaxSize()));
	connect(m_titleBar, SIGNAL(closeButtonClicked()), this, SLOT(Close()));
	mainLayout->addWidget(m_titleBar);

	m_toolBar = new QWidget(this);
	m_toolBar->setStyleSheet("background-color: rgb(200,200,200)");
	m_toolBar->setMinimumHeight(30);
	m_toolBar->setMaximumHeight(30);
	mainLayout->addWidget(m_toolBar);

	m_Splitter = new QSplitter(this);
	m_Splitter->setStyleSheet("background-color: rgb(60,60,60)");
	mainLayout->addWidget(m_Splitter);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);
	setLayout(mainLayout);

	resize(700, 700);
}

KMainWidget::~KMainWidget()
{

}

void KMainWidget::ShowMiniSize()
{
	this->showMinimized();
}

void KMainWidget::ShowMaxSize()
{
	this->showMaximized();
}

void KMainWidget::Close()
{
	this->close();
}
