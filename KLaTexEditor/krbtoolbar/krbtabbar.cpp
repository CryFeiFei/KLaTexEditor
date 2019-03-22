#include "krbtabbar.h"
#include <kglobal.h>
#include <QHBoxLayout>

KRbTabBar::KRbTabBar(QWidget *parent) : QWidget(parent)
{
	this->setObjectName("KRbTabBar");

	QHBoxLayout* mainLayout = new QHBoxLayout(this);

	m_miniToolWidget = new QWidget(this);
	m_miniToolWidget->setStyleSheet("background-color:red;");
	m_miniToolWidget->setMinimumWidth(KStyle::dpiScale(30));

	mainLayout->addWidget(m_miniToolWidget);

	m_tabbar = new QTabBar(this);
	m_tabbar->addTab("123");
	m_tabbar->addTab("456");

	mainLayout->addWidget(m_tabbar);
	mainLayout->setMargin(0);

	this->setLayout(mainLayout);


}

KRbTabBar::~KRbTabBar()
{

}
