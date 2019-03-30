#include "kwebtoolwidget.h"
#include "kglobal.h"
#include <QHBoxLayout>

///////////////////////////////////////////////////
KWebToolButton::KWebToolButton(QWidget* parent) : QWidget(parent)
{
	setObjectName("KWebToolButton");
}
KWebToolButton::~KWebToolButton()
{

}
///////////////////////////////////////////////////
KWebToolWidget::KWebToolWidget(QWidget *parent) : QWidget(parent)
{
	QHBoxLayout* mainLayout = new QHBoxLayout(this);
}

KWebToolWidget::~KWebToolWidget()
{

}
