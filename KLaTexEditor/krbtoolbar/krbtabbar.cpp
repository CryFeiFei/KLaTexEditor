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
	m_miniToolWidget->setFixedWidth(KStyle::dpiScale(50));

	mainLayout->addWidget(m_miniToolWidget);

	m_buttonGroup = new KRbButtonGroup(this);

	mainLayout->addWidget(m_buttonGroup);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);

	setLayout(mainLayout);


}

KRbTabBar::~KRbTabBar()
{

}
