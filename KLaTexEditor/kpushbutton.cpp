#include "kpushbutton.h"
#include "kglobal.h"

static QString KPBStyle = QString("\
								QPushButton{\
								border : none;\
								border-radius : 2px;\
								background-color : rgb(80, 135, 229);}");

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
