#include "krbtoolbar.h"

#include "krbtabbar.h"
#include <QVBoxLayout>
#include "kglobal.h"
#include "krbtabwidget.h"
#include "krbtoolbutton.h"

KRbToolBar::KRbToolBar(QWidget *parent) : QWidget(parent)
{
	setObjectName("KRbToolBar");
	setStyleSheet("background-color: rgb(245, 245, 245)");
	setFixedHeight(KStyle::dpiScale(90));

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	m_rbTabBar = new KRbTabBar(this);
	m_rbTabBar->setFixedHeight(KStyle::dpiScale(30));
	mainLayout->addWidget(m_rbTabBar);

	m_rbTabWidget = new QStackedWidget(this);

	//start view
	KRbStartTabWidget* startTabWidget = new KRbStartTabWidget(this);
	startTabWidget->init();
//	KRbToolButton* openToolButton = new KRbToolButton();
//	startTabWidget->addToolWidget(openToolButton);
	startTabWidget->setStyleSheet("background-color:white;");
//	QWidget* startWidget = new QWidget(this);
//	startWidget->setStyleSheet("background-color:white;");

	KRbViewTabWidget* viewTabWidget = new KRbViewTabWidget(this);
	viewTabWidget->init();
//	QWidget* viewWidget = new QWidget(this);
//	viewWidget->setStyleSheet("background-color:red;");
	m_rbTabWidget->addWidget(startTabWidget);
	m_rbTabWidget->addWidget(viewTabWidget);

	connect(m_rbTabBar, SIGNAL(tabChanged(int)), m_rbTabWidget, SLOT(setCurrentIndex(int)));

	mainLayout->addWidget(m_rbTabWidget);
	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);
	setLayout(mainLayout);

}
