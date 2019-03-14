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
		m_movePos = e->pos();
	}

	QWidget::mousePressEvent(e);
}

void KTitleWidget::mouseMoveEvent(QMouseEvent *e)
{
	if (m_bPress && e->buttons() & Qt::LeftButton)
	{
		emit positionChanged(e->globalPos() - m_movePos);
	}

	QWidget::mouseMoveEvent(e);
}

void KTitleWidget::mouseReleaseEvent(QMouseEvent *e)
{
	if (e->buttons() & Qt::LeftButton)
		m_bPress = false;

	QWidget::mouseReleaseEvent(e);
}
