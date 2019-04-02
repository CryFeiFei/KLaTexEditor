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

	QString strComboxStyleSheet = QString("QComboBox::drop-down{"
										  "border-style: none;}");
	QComboBox* textColorCb = new QComboBox(this);
	textColorCb->setFixedSize(KStyle::dpiScale(60), KStyle::dpiScale(30));
	textColorCb->setStyleSheet(strComboxStyleSheet);
	textColorCb->addItem("TextColor");

	QComboBox* bgCb = new QComboBox(this);
	bgCb->setFixedSize(KStyle::dpiScale(60), KStyle::dpiScale(30));
	bgCb->setStyleSheet(strComboxStyleSheet);
	bgCb->addItem("BGColor");

	QComboBox* fontSizeCb = new QComboBox(this);
	fontSizeCb->setFixedSize(KStyle::dpiScale(60), KStyle::dpiScale(30));
	fontSizeCb->setStyleSheet(strComboxStyleSheet);
	fontSizeCb->addItem("FontSize");

	QComboBox* fontType = new QComboBox(this);
	fontType->setFixedSize(KStyle::dpiScale(60), KStyle::dpiScale(30));
	fontType->setStyleSheet(strComboxStyleSheet);
	fontType->addItem("FontType");

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

	mainLayout->addWidget(textColorCb);
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
