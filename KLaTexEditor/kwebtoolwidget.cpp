#include "kwebtoolwidget.h"
#include "kglobal.h"
#include <QHBoxLayout>
#include <QComboBox>
#include "kcolorlabel.h"
#include "kcombobox.h"
#include "kpushbutton.h"
#include <QColorDialog>


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
	pen.setWidthF(KStyle::dpiScale(2));
	painter.setPen(pen);
	painter.drawLine(QPointF(0, sizeHint().height()), QPointF(KStyle::dpiScale(20), 0));
}

QSize KWebToolSeparate::sizeHint() const
{
	return QSize(KStyle::dpiScale(20), rect().height());
}
///////////////////////////////////////////////////
KWebToolWidget::KWebToolWidget(QWidget *parent) : QWidget(parent)
{
	QHBoxLayout* mainLayout = new QHBoxLayout(this);

	//-------------------------------------------------
	m_textColorLabel = new KColorLabel(Qt::black, this);
	m_textColorLabel->setObjectName("TextColorLabel");
	m_textColorLabel->setToolTipPrefix(QObject::tr("TextColor"));

	auto fTextColor = [this]() -> void
	{
		QColor textColor = QColorDialog::getColor(m_textColorLabel->color());
		if (textColor.isValid())
		{
			m_textColorLabel->setColor(textColor);
		}
	};
	auto fEmitTextColor = [this] () -> void
	{
		emit textColorChanged(m_textColorLabel->color());
	};
	connect(m_textColorLabel, &KColorLabel::clicked, fTextColor);
	connect(m_textColorLabel, &KColorLabel::colorChanged, fEmitTextColor);

	//-------------------------------------------------------------------
	m_bgColorLabel = new KColorLabel(this);
	m_bgColorLabel->setObjectName("BackGroundColorLabel");
	m_bgColorLabel->setToolTipPrefix(QObject::tr("BackGroundColor"));
	auto fBGColor = [this] () -> void
	{
		QColor bgColor = QColorDialog::getColor(m_bgColorLabel->color());
		if (bgColor.isValid())
		{
			m_bgColorLabel->setColor(bgColor);
		}
	};
	auto fEmitBGColor = [this] () -> void
	{
		emit bgColorChanged(m_bgColorLabel->color());
	};
	connect(m_bgColorLabel, &KColorLabel::clicked, fBGColor);
	connect(m_bgColorLabel, &KColorLabel::colorChanged, fEmitBGColor);

	//----------------------------------------------------------------

	KComboBox* fontSizeCb = new KComboBox(this);
	fontSizeCb->setObjectName("FontSizeComboBox");
	fontSizeCb->setToolTipPrefix("FontSize");
	QStringList fontSizeList;
	fontSizeList<< "tiny" << "scriptsize" << "footnotesize" <<
				"small" << "normalsize" << "large" << "Large" << "LARGE" << "huge" << "Huge";
	fontSizeCb->addItems(fontSizeList);
	fontSizeCb->setCurrentText("normalsize");
	connect(fontSizeCb, &KComboBox::currentTextChanged, this, &KWebToolWidget::fontSizeChanged);
	//------------------------------------------------------------

	KComboBox* fontTypeCb = new KComboBox(this);
	fontTypeCb->setObjectName("FontTypeComboBox");
	QStringList fontTypeList;
	fontTypeList << "normal" << "rm" << "it" << "bf"
				 <<"sf" << "tt" << "frak" << "Bbb" << "mathcal"
				<< "bold" << "boldsymbol" << "matchscr";
	fontTypeCb->addItems(fontTypeList);
	connect(fontTypeCb, &KComboBox::currentTextChanged, this, &KWebToolWidget::fontTypeChanged);
	///////////////////////////////////////////////////////////////////////////

	KPushButton* copyButton = new KPushButton(this);
	copyButton->setObjectName("CopyButton");
	copyButton->setText("Copy");
	copyButton->setToolTip("Copy to clipboard");
	connect(copyButton, &KPushButton::clicked, this, &KWebToolWidget::copyToClipboard);

	/////////////////////////////////////////////////////////////
	KPushButton* saveButton = new KPushButton(this);
	saveButton->setObjectName("SaveButton");
	saveButton->setText("Save");
	saveButton->setToolTip("Save as Image");
	connect(saveButton, &KPushButton::pressed, this, &KWebToolWidget::saveAs);

	KWebToolSeparate* sep = new KWebToolSeparate(this);
	mainLayout->addWidget(m_textColorLabel);
	mainLayout->addWidget(sep);
	mainLayout->addWidget(m_bgColorLabel);
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
