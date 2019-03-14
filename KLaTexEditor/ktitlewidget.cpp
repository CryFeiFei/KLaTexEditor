#include "ktitlewidget.h"
#include "ui_ktitlewidget.h"
#include <QMouseEvent>

KTitleWidget::KTitleWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::KTitleWidget)
{
	setObjectName("KTitleWidget");
	setMouseTracking(true);
	ui->setupUi(this);

	setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	setStyleSheet("background-color: rgb(122,122,122)");


	connect(ui->miniButton, SIGNAL(clicked()), this, SIGNAL(miniButtonClicked()));
	connect(ui->maxButton, SIGNAL(clicked()), this, SIGNAL(maxButtonClicked()));
	connect(ui->closeButton, SIGNAL(clicked()), this, SIGNAL(closeButtonClicked()));

	setMinimumHeight(50);
	setMaximumHeight(50);
}

KTitleWidget::~KTitleWidget()
{
	delete ui;
}

void KTitleWidget::mousePressEvent(QMouseEvent* e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		m_bPress = true;
		QMouseEvent *eventMouse = (QMouseEvent*)e;
		QPoint point = this->pos();
		QPoint mousePoint = eventMouse->globalPos();
		m_movePos = mousePoint - point;
		m_parentPos = parentWidget()->pos();
	}

	QWidget::mousePressEvent(e);
}

void KTitleWidget::mouseMoveEvent(QMouseEvent *e)
{
	if (m_bPress && e->buttons() & Qt::LeftButton)
	{
		QMouseEvent *eventMouse = (QMouseEvent*)e;
		QPoint movePoint = eventMouse->globalPos() - m_movePos;
		QMargins margins =  parentWidget()->layout()->contentsMargins();
		QPoint parentMargins(margins.left(), margins.top());
		parentWidget()->move(movePoint + m_parentPos - parentMargins);
	}

	QWidget::mouseMoveEvent(e);
}

void KTitleWidget::mouseReleaseEvent(QMouseEvent *e)
{
	if (e->buttons() & Qt::LeftButton)
		m_bPress = false;

	QWidget::mouseReleaseEvent(e);
}

