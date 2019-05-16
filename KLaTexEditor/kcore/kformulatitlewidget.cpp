#include "kglobal.h"
#include "kformulatitlewidget.h"
#include <QPainter>
#include <QHBoxLayout>
#include "kpushbutton.h"
KFormulaTitleWidget::KFormulaTitleWidget(QString strTitle, QWidget *parent) : m_strTitle(strTitle), QWidget(parent)
{
	m_refreshBtn = new KPushButton(this);
	m_refreshBtn->setText(tr("refresh"));

	QHBoxLayout* mainLayout = new QHBoxLayout(this);
	mainLayout->addStretch();
	mainLayout->addWidget(m_refreshBtn);
	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);
	this->setLayout(mainLayout);

	connect(m_refreshBtn, &KPushButton::clicked, this, &KFormulaTitleWidget::refresh);
}

void KFormulaTitleWidget::paintEvent(QPaintEvent *e)
{
	QPainter painter(this);

	painter.drawText(rect(), Qt::AlignCenter, m_strTitle);

	return QWidget::paintEvent(e);
}
