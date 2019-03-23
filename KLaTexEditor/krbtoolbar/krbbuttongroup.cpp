#include "krbbuttongroup.h"
#include <QPainter>
#include <QGridLayout>
#include <QPushButton>
#include <QButtonGroup>
#include "kglobal.h"
////////////////////////////////
//KRbTabButton::KRbTabButton(QWidget *parent) : QWidget(parent)
//{

//}

//KRbTabButton::~KRbTabButton()
//{

//}
/////////////////////////////////
KRbButtonGroup::KRbButtonGroup(QWidget *parent) : QWidget(parent)
{
//	QGridLayout* mainLayout = new QGridLayout(this);

	QWidget* widget1 = new QWidget(this);
	QPushButton* pushbutton1 = new QPushButton(this);
	QPushButton* pushbutton2 = new QPushButton(this);
	//keyianxia
	pushbutton1->setCheckable(true);
	pushbutton2->setCheckable(true);
	pushbutton1->setFixedSize(KStyle::dpiScale(75) ,KStyle::dpiScale(30));
	pushbutton2->setFixedSize(KStyle::dpiScale(75) ,KStyle::dpiScale(30));
	pushbutton1->setGeometry(0, 0, KStyle::dpiScale(75) ,KStyle::dpiScale(30));
	pushbutton2->setGeometry(KStyle::dpiScale(75), 0, KStyle::dpiScale(75) ,KStyle::dpiScale(30));
	pushbutton1->setText("start");
	pushbutton2->setText("view");
	QString strButtonStyleSheet = QString("QPushButton{border:none;color:rgb(0, 0, 0);}"
										  "QPushButton:hover{background-color: rgb(220, 220, 220);border:none;color:rgb(82, 139, 139);}"
										  "QPushButton:checked{background-color: rgb(255, 255, 255);border:none;color:rgb(0, 0, 0);}");

	pushbutton1->setStyleSheet(strButtonStyleSheet);
	pushbutton2->setStyleSheet(strButtonStyleSheet);

	QButtonGroup* buttonGroup = new QButtonGroup(this);
	buttonGroup->addButton(pushbutton1);
	buttonGroup->addButton(pushbutton2);
	buttonGroup->setExclusive(true);
}

void KRbButtonGroup::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	painter.fillRect(rect(), Qt::red);
}
