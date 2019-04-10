#include "kwebtoolwidget.h"
#include "kglobal.h"
#include <QHBoxLayout>
#include <QComboBox>
#include "kcolorlabel.h"
#include "kcombobox.h"
#include "kpushbutton.h"

///////////////////////////////////////////////////
KWebToolSeparate::KWebToolSeparate(QWidget* parent) : QWidget(parent)
{
	setObjectName("KWebToolSeparate");
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
}
KWebToolSeparate::~KWebToolSeparate()
{

}

void KWebToolSeparate::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	QPen pen;
	pen.setColor(Qt::black);
	pen.setWidth(KStyle::dpiScale(2));
	painter.setPen(pen);
	painter.drawLine(QPoint(0, sizeHint().height()), QPoint(KStyle::dpiScale(20), 0));
}

QSize KWebToolSeparate::sizeHint() const
{
	return QSize(KStyle::dpiScale(20), rect().height());
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

	KPushButton* copyButton = new KPushButton(this);
	copyButton->setObjectName("CopyButton");
	copyButton->setText("Copy");
	copyButton->setToolTip("Copy to clipboard");

	KPushButton* saveButton = new KPushButton(this);
	saveButton->setObjectName("SaveButton");
	saveButton->setText("Save");
	saveButton->setToolTip("Save as Image");

	KWebToolSeparate* sep = new KWebToolSeparate(this);
	mainLayout->addWidget(textColorLabel);
	mainLayout->addWidget(sep);
	mainLayout->addWidget(bgColorLabel);
	mainLayout->addWidget(fontSizeCb);
	mainLayout->addWidget(fontTypeCb);
	mainLayout->addWidget(copyButton);
	mainLayout->addWidget(saveButton);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);

	setLayout(mainLayout);
}

KWebToolWidget::~KWebToolWidget()
{

}
