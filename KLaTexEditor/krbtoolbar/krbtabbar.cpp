#include "krbtabbar.h"
#include <kglobal.h>
#include <QHBoxLayout>
#include <QPushButton>
#include "krbbuttongroup.h"
//////////////////////////
//////////////////////////
KRbTabBar::KRbTabBar(QWidget *parent) : QWidget(parent)
{
	setObjectName("KRbTabBar");

	QHBoxLayout* mainLayout = new QHBoxLayout(this);

	m_miniToolWidget = new QWidget(this);
	m_miniToolWidget->setStyleSheet("background-color:black;");
	m_miniToolWidget->setFixedWidth(KStyle::dpiScale(120));
	mainLayout->addWidget(m_miniToolWidget);

	m_buttonGroup = new KRbButtonGroup(this);
	connect(m_buttonGroup, SIGNAL(tabChanged(int)), this, SIGNAL(tabChanged(int)));
	mainLayout->addWidget(m_buttonGroup);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);
	setLayout(mainLayout);


}

KRbTabBar::~KRbTabBar()
{

}
