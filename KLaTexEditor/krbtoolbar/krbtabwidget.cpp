#include "krbtabwidget.h"
#include "kglobal.h"
#include <QHBoxLayout>
#include "krbtoolbutton.h"

//todo scrollarea
KRbTabWidget::KRbTabWidget(QWidget *parent) : QWidget(parent)
{
	m_mainLayout = new QHBoxLayout(this);

	m_mainLayout->setMargin(0);
	m_mainLayout->setSpacing(0);
}

KRbTabWidget::~KRbTabWidget()
{

}

void KRbTabWidget::addToolWidget(QWidget *widget)
{
//	widget->setParent(this);
//	widget->setGeometry(0, 0, KStyle::dpiScale(60), KStyle::dpiScale(60));
//	m_mainLayout->addWidget(widget, Qt::AlignLeft);
}

///////////////////////////////////////////////////
/// \brief KRbStartTabWidget::init

KRbStartTabWidget::KRbStartTabWidget(QWidget* parent) : KRbTabWidget(parent)
{

}
void KRbStartTabWidget::init()
{
	QString strButtonStyleSheet = QString("QToolButton{border:none;color:rgb(0, 0, 0);}"
										  "QToolButton:hover{background-color: rgb(220, 220, 220);border:none;color:rgb(82, 139, 139);}"
										  "QToolButton:pressed{background-color: rgb(180, 180, 180);border:none;color:rgb(0, 0, 0);}");
	KRbToolButton* openButton = new KRbToolButton(this);
	openButton->setObjectName("open");
	openButton->setText("open");
	openButton->setStyleSheet(strButtonStyleSheet);
	//openButton->setIcon();
	openButton->setGeometry(KStyle::dpiScale(2), 0, KStyle::dpiScale(35), KStyle::dpiScale(60));

	KRbToolButton* saveButton = new KRbToolButton(this);
	saveButton->setObjectName("save");
	saveButton->setText("save");
	saveButton->setStyleSheet(strButtonStyleSheet);
	saveButton->setGeometry(KStyle::dpiScale(37), 0, KStyle::dpiScale(35), KStyle::dpiScale(60));

}
