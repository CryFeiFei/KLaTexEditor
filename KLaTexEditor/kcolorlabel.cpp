#include "kcolorlabel.h"

#include <QPainter>
#include <QToolTip>
#include "kglobal.h"

KColorLabel::KColorLabel(QWidget *parent) : QWidget(parent)
			,m_bgColor(Qt::red)
{
	setObjectName("KColorLabel");
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
}

KColorLabel::~KColorLabel()
{

}

QColor KColorLabel::color()
{
	return m_bgColor;
}

void KColorLabel::setColor(QColor color)
{
	m_bgColor = color;
	update();
}

QString KColorLabel::toolTipPrefix()
{
	return m_strToolTipPrefix;
}

void KColorLabel::setToolTipPrefix(QString strToolTipPrefix)
{
	m_strToolTipPrefix = strToolTipPrefix;
}

bool KColorLabel::event(QEvent *e)
{
	if (e->type() == QEvent::ToolTip)
	{
		QHelpEvent *helpEvent = static_cast<QHelpEvent *>(e);
//		helpEvent->pos()
		if (rect().contains(helpEvent->pos()))
		{
			QString strToolTip = m_strToolTipPrefix + QString(":") + m_bgColor.name(QColor::HexRgb);
			QToolTip::showText(helpEvent->globalPos(), strToolTip);
		}
		else
		{
			QToolTip::hideText();
			e->ignore();
		}
		return true;
	}
	return QWidget::event(e);
}

void KColorLabel::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);
	painter.fillRect(rect(), QBrush(m_bgColor));
}

void KColorLabel::mouseReleaseEvent(QMouseEvent *event)
{
	if (rect().contains(event->pos()) && event->button() == Qt::LeftButton)
	{
		emit clicked();
		return;
	}
	return QWidget::mouseReleaseEvent(event);
}

QSize KColorLabel::sizeHint() const
{
	return QSize(KStyle::dpiScale(35), size().height());
}
