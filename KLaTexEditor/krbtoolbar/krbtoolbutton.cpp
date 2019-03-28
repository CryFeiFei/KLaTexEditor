#include "krbtoolbutton.h"
#include "kglobal.h"

KRbToolButton::KRbToolButton(QWidget *parent) : QToolButton(parent)
{
	setObjectName("KRbToolButton");
	setFixedSize(KStyle::dpiScale(35), KStyle::dpiScale(60));
	setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

KRbToolButton::~KRbToolButton()
{

}
//////////////////////////////////////
KRbCheckBox::KRbCheckBox(QWidget *parent) : QCheckBox(parent)
{
	setObjectName("KRbCheckBox");
	setFixedSize(KStyle::dpiScale(70), KStyle::dpiScale(30));
}
KRbCheckBox::~KRbCheckBox()
{

}
