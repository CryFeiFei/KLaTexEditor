#include "kcombobox.h"
#include "kglobal.h"

#include <QToolTip>

#define COMBOBOX_ARROW_SIZE 24

KComboBox::KComboBox(QWidget* parent) : QComboBox(parent)
					, m_bgColor(Qt::gray)
{
	setObjectName("KComboBox");
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
	QString styleSheet = QString("QComboBox{"
											"border : none;}"
											);
	setStyleSheet(styleSheet);
}

KComboBox::~KComboBox()
{

}

QString KComboBox::toolTipPrefix()
{
	return m_strToolTipPrefix;
}

void KComboBox::setToolTipPrefix(QString strToolTipPrefix)
{
	m_strToolTipPrefix = strToolTipPrefix;
}

void KComboBox::setBackGoundColor(QColor color)
{
	m_bgColor = color;
}

QSize KComboBox::sizeHint() const
{
	int nMax = -1;
	for (int i = 0; i < count(); ++i)
	{
		QFontMetrics fm(font());
		int nWidth = fm.boundingRect(itemText(i)).width();
		nMax = std::max(nMax, nWidth);
	}

//#ifdef Q_OS_UNIX
//	nMax += COMBOBOX_ARROW_SIZE;
//#endif

	return QSize(KStyle::dpiScale(nMax), rect().height());
}

bool KComboBox::event(QEvent *e)
{
	if (e->type() == QEvent::ToolTip)
	{
		QHelpEvent *helpEvent = static_cast<QHelpEvent *>(e);
		if (rect().contains(helpEvent->pos()))
		{
			QString strPrefix = m_strToolTipPrefix;
			if (!m_strToolTipPrefix.isEmpty())
				strPrefix += QString(":");

			QString strToolTip = strPrefix + currentText();
			QToolTip::showText(helpEvent->globalPos(), strToolTip);
		}
		else
		{
			QToolTip::hideText();
			e->ignore();
		}
		return true;
	}
	return QComboBox::event(e);

}

void KComboBox::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	painter.fillRect(rect(), QBrush(m_bgColor));
	painter.drawText(rect(), Qt::AlignCenter, currentText());
}
