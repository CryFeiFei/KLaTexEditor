#include "krbtoolbar.h"

#include "krbtabbar.h"
#include <QVBoxLayout>
#include "kglobal.h"

KRbToolBar::KRbToolBar(QWidget *parent) : QWidget(parent)
{
	m_rbTabBar = new KRbTabBar(this);
	m_rbTabBar->setFixedHeight(KStyle::dpiScale(50));

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->addWidget(m_rbTabBar);

	m_rbTabWidget = new QWidget(this);
	mainLayout->addWidget(m_rbTabWidget);

	mainLayout->setMargin(0);
	this->setLayout(mainLayout);

}
