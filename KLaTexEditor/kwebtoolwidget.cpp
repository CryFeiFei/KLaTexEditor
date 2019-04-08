#include "kwebtoolwidget.h"
#include "kglobal.h"
#include <QHBoxLayout>
#include <QComboBox>
#include "kcolorlabel.h"
#include "kcombobox.h"

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

	KColorLabel* textColorLabel = new KColorLabel(this);
	textColorLabel->setObjectName("TextColorLabel");
	textColorLabel->setToolTipPrefix(QObject::tr("TextColor"));

	KColorLabel* bgColorLabel = new KColorLabel(this);
	bgColorLabel->setObjectName("BackGroundColorLabel");
	bgColorLabel->setToolTipPrefix(QObject::tr("BackGroundColor"));

	KComboBox* fontSizeCb = new KComboBox(this);
	fontSizeCb->setObjectName("FontSizeComboBox");
	fontSizeCb->addItem("FontSize");

	KComboBox* fontTypeCb = new KComboBox(this);
	fontTypeCb->setObjectName("FontTypeComboBox");
	fontTypeCb->addItem("FontType");

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

	mainLayout->addWidget(textColorLabel);
	mainLayout->addWidget(bgColorLabel);
	mainLayout->addWidget(fontSizeCb);
	mainLayout->addWidget(fontTypeCb);
	mainLayout->addWidget(copyButton);
	mainLayout->addWidget(saveAsButton);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);

	setLayout(mainLayout);

}

KWebToolWidget::~KWebToolWidget()
{

}
