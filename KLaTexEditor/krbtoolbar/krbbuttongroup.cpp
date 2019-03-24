#include "krbbuttongroup.h"
#include <QPainter>
#include <QGridLayout>
#include <QPushButton>
#include <QButtonGroup>
#include "kglobal.h"
////////////////////////////////
KRbTabButton::KRbTabButton(QWidget *parent) : QPushButton(parent)
{
	setCheckable(true);
	setFixedSize(KStyle::dpiScale(75) ,KStyle::dpiScale(30));
	QString strButtonStyleSheet = QString("QPushButton{border:none;color:rgb(0, 0, 0);}"
										  "QPushButton:hover{background-color: rgb(220, 220, 220);border:none;color:rgb(82, 139, 139);}"
										  "QPushButton:checked{background-color: rgb(255, 255, 255);border:none;color:rgb(0, 0, 0);}");
	setStyleSheet(strButtonStyleSheet);
}

KRbTabButton::~KRbTabButton()
{

}
/////////////////////////////////
KRbButtonGroup::KRbButtonGroup(QWidget *parent) : QWidget(parent)
{
	m_startButton = new KRbTabButton(this);
	m_viewButton = new KRbTabButton(this);
	m_startButton->setGeometry(0, 0, KStyle::dpiScale(75) ,KStyle::dpiScale(30));
	m_viewButton->setGeometry(KStyle::dpiScale(75), 0, KStyle::dpiScale(75) ,KStyle::dpiScale(30));
	m_startButton->setText("start");
	m_viewButton->setText("view");
	m_startButton->setObjectName("RbStartButton");
	m_viewButton->setObjectName("RbViewButton");

	QButtonGroup* buttonGroup = new QButtonGroup(this);
	buttonGroup->addButton(m_startButton, 0);
	buttonGroup->addButton(m_viewButton, 1);
	buttonGroup->setExclusive(true);

	connect(buttonGroup, SIGNAL(buttonPressed(int)), this, SIGNAL(tabChanged(int)));
}

void KRbButtonGroup::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	painter.fillRect(rect(), Qt::red);

	QWidget::paintEvent(e);
}
