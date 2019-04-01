#include "kwebtoolwidget.h"
#include "kglobal.h"
#include <QHBoxLayout>
#include <QComboBox>

///////////////////////////////////////////////////
KWebToolButton::KWebToolButton(QWidget* parent) : QPushButton(parent)
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

	QComboBox* textCb = new QComboBox(this);
	textCb->setFixedWidth(KStyle::dpiScale(60));
	QComboBox* bgCb = new QComboBox(this);
	bgCb->setFixedWidth(KStyle::dpiScale(60));
	QComboBox* fontSizeCb = new QComboBox(this);
	fontSizeCb->setFixedWidth(KStyle::dpiScale(60));
	QComboBox* fontType = new QComboBox(this);
	fontType->setFixedWidth(KStyle::dpiScale(60));

	QPushButton* copyButton = new QPushButton(this);
	QString strButtonStyleSheet = QString("\
									QPushButton{\
									border : none;\
									border-radius : 2px;\
									background-color : rgb(80, 135, 229);}");
	copyButton->setText("copy to clip");
	copyButton->setFixedWidth(KStyle::dpiScale(60));
	copyButton->setFixedHeight(KStyle::dpiScale(30));
	copyButton->setStyleSheet(strButtonStyleSheet);

	QPushButton* saveAsButton = new QPushButton(this);
	saveAsButton->setText("save as");
	saveAsButton->setFixedSize(KStyle::dpiScale(60), KStyle::dpiScale(30));
	saveAsButton->setStyleSheet(strButtonStyleSheet);

	mainLayout->addWidget(textCb);
	mainLayout->addWidget(bgCb);
	mainLayout->addWidget(fontSizeCb);
	mainLayout->addWidget(fontType);
	mainLayout->addWidget(copyButton);
	mainLayout->addWidget(saveAsButton);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);

	setLayout(mainLayout);

}

KWebToolWidget::~KWebToolWidget()
{

}
