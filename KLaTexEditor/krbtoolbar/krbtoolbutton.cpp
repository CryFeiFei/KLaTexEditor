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
	int nWidth = 30 + sz.width();
	if (nWidth < 100)
		nWidth = 100;
	return QSize(nWidth, 30);
}

KRbSeparatorWidget::KRbSeparatorWidget(QWidget* parent) : QWidget (parent)
{
	setObjectName("KRbSeparatorWidget");
	setFixedWidth(KStyle::dpiScale(7));
	setFixedHeight(KStyle::dpiScale(90));
}

KRbSeparatorWidget::~KRbSeparatorWidget()
{

}

void KRbSeparatorWidget::paintEvent(QPaintEvent* e)
{
	QPainter painter(this);
	QBrush brush;
	brush.setColor(Qt::gray);

	QPen pen;
	pen.setWidth(KStyle::dpiScale(1));
	pen.setBrush(brush);
	painter.setBrush(brush);
	painter.drawLine(KStyle::dpiScale(4), KStyle::dpiScale(1), KStyle::dpiScale(4), KStyle::dpiScale(90));
	QWidget::paintEvent(e);
}


