#include "kmainwidget.h"
#include <QVBoxLayout>
#include <QSplitter>
#include <ktitlewidget.h>

KMainWidget::KMainWidget(QWidget *parent) : QWidget(parent)
{
	setObjectName("KMainWidget");

	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	// title bar
	m_titleBar = new KTitleWidget(this);
	m_titleBar->setStyleSheet("background-color: rgb(122,122,122)");
	m_titleBar->setMinimumHeight(50);
	m_titleBar->setMaximumHeight(50);
	mainLayout->addWidget(m_titleBar);
//	connect(m_titleBar, SIGNAL(positionChanged(const QPoint&)), SLOT(onPositionChange(const QPoint&)));
	connect(m_titleBar, SIGNAL(positionChanged(const QPoint&)), this, SIGNAL(positionchanged(const QPoint&)));

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
	this->setLayout(mainLayout);
}

void KMainWidget::onPositionChange(const QPoint &point)
{
	this->move(point);
}
