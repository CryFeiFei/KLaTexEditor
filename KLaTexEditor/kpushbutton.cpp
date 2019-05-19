#include "kpushbutton.h"
#include "kglobal.h"

const static QString KPBStyle = QString("\
QPushButton{border : none; border-radius : 2px;background-color : rgb(80, 135, 229);}"
"QPushButton:hover{background-color: rgb(220, 220, 220);border:none;color:rgb(82, 139, 139);}"
"QPushButton:checked{background-color: rgb(255, 255, 255);border:none;color:rgb(0, 0, 0);}"
);

KPushButton::KPushButton(QWidget *parent) : QPushButton(parent)
{
	setObjectName("KPushButton");
	setStyleSheet(KPBStyle);
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
}
QSize KPushButton::sizeHint() const
{
return QSize(KStyle::dpiScale(60), size().height());
}
