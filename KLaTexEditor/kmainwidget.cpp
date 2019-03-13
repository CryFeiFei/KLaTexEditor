#include "kmainwidget.h"
#include <QVBoxLayout>
#include <QSplitter>

KMainWidget::KMainWidget(QWidget *parent) : QWidget(parent)
{
	setObjectName("KMainWidget");

	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	// title bar
	m_titleBar = new QWidget(this);
	m_titleBar->setStyleSheet("background-color: rgb(122,122,122)");
	m_titleBar->setMinimumHeight(20);
	m_titleBar->setMaximumHeight(20);
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
	this->setLayout(mainLayout);
}
