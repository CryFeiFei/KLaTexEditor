#include "krbtoolbutton.h"
#include "kglobal.h"

KRbToolButton::KRbToolButton(QWidget *parent) : QToolButton(parent)
{
	setObjectName("KRbToolButton");
//	setFixedSize(KStyle::dpiScale(40), KStyle::dpiScale(60));
	setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
}

KRbToolButton::~KRbToolButton()
{

}

// waibian ziji yao KStyle::dpiScale
QSize KRbToolButton::sizeHint() const
{
	QFontMetrics fm(font());
	QRect sz = fm.boundingRect(text());
	int nWidth = sz.width() > 40 ?
				sz.width() : 40;
	return QSize(nWidth, 60);
}
//////////////////////////////////////
KRbCheckBox::KRbCheckBox(QWidget *parent) : QCheckBox(parent)
{
	setObjectName("KRbCheckBox");
//	setFixedSize(KStyle::dpiScale(90), KStyle::dpiScale(30));
}
KRbCheckBox::~KRbCheckBox()
{

}

QSize KRbCheckBox::sizeHint() const
{
	QFontMetrics fm(font());
	QRect sz = fm.boundingRect(text());
	int nWidth = sz.width() > 100 ?
				sz.width() : 100;
	return QSize(nWidth, 30);
}


