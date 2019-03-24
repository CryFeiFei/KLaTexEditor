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

	m_rbTabWidget = new QStackedWidget(this);

	QWidget* w1 = new QWidget(this);
	w1->setStyleSheet("background-color:white;");

	QWidget* w2 = new QWidget(this);
	w2->setStyleSheet("background-color:red;");


	m_rbTabWidget->addWidget(w1);
	m_rbTabWidget->addWidget(w2);

	connect(m_rbTabBar, SIGNAL(tabChanged(int)), m_rbTabWidget, SLOT(setCurrentIndex(int)));

	mainLayout->addWidget(m_rbTabWidget);
	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);
	setLayout(mainLayout);

}
