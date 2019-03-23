#include "krbtoolbar.h"

#include "krbtabbar.h"
#include <QVBoxLayout>
#include "kglobal.h"

KRbToolBar::KRbToolBar(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	m_rbTabBar = new KRbTabBar(this);
	m_rbTabBar->setFixedHeight(KStyle::dpiScale(30));
	mainLayout->addWidget(m_rbTabBar);

	m_rbTabWidget = new QWidget(this);
	mainLayout->addWidget(m_rbTabWidget);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);
	setLayout(mainLayout);

}
