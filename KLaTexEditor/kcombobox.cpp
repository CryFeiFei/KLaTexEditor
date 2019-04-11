#include "kcombobox.h"
#include "kglobal.h"

#include <QToolTip>
#include <QListView>

constexpr int ArrowSize = 24;

KComboBox::KComboBox(QWidget* parent) : QComboBox(parent)
					, m_bgColor(Qt::gray)
{
	setObjectName("KComboBox");
	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

	QListView* list = new QListView(this);
	list->setStyleSheet("QListView::item{height:30px; font-size:20px; background-color:rgb(255,255,255); color:rgb(0, 0, 0);border:none;}"
						 "QListView::item::hover{background-color:rgb(9,150,200); color:rgb(122, 122, 122); border:none;}"
						 );
	setView(list);
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
//	nMax += ArrowSize;
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
