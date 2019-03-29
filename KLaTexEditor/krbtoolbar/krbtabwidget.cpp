#include "krbtabwidget.h"
#include "kglobal.h"
#include <QHBoxLayout>
#include "krbtoolbutton.h"

//todo scrollarea
KRbTabWidget::KRbTabWidget(QWidget *parent) : QWidget(parent)
{
	m_mainLayout = new QHBoxLayout(this);

	m_mainLayout->setMargin(0);
	m_mainLayout->setSpacing(0);
}

KRbTabWidget::~KRbTabWidget()
{

}

void KRbTabWidget::addToolWidget(QWidget *widget)
{
//	widget->setParent(this);
//	widget->setGeometry(0, 0, KStyle::dpiScale(60), KStyle::dpiScale(60));
//	m_mainLayout->addWidget(widget, Qt::AlignLeft);
}

///////////////////////////////////////////////////
/// \brief KRbStartTabWidget::init

KRbStartTabWidget::KRbStartTabWidget(QWidget* parent) : KRbTabWidget(parent)
{

}
void KRbStartTabWidget::init()
{
	QString strButtonStyleSheet = QString("QToolButton{border:none;color:rgb(0, 0, 0);}"
										  "QToolButton:hover{background-color: rgb(220, 220, 220);border:none;color:rgb(82, 139, 139);}"
										  "QToolButton:pressed{background-color: rgb(180, 180, 180);border:none;color:rgb(0, 0, 0);}");
	KRbToolButton* openButton = new KRbToolButton(this);
	openButton->setObjectName("open");
	openButton->setText("open");
	openButton->setStyleSheet(strButtonStyleSheet);
	int nOpenButtonWidth = openButton->sizeHint().width();
	//openButton->setIcon();
	openButton->setGeometry(KStyle::dpiScale(2), 0, KStyle::dpiScale(nOpenButtonWidth), KStyle::dpiScale(60));

	KRbToolButton* saveButton = new KRbToolButton(this);
	saveButton->setObjectName("save");
	saveButton->setText("save");
	saveButton->setStyleSheet(strButtonStyleSheet);
	int nSaveButtonWidth = saveButton->sizeHint().width();
	saveButton->setGeometry(KStyle::dpiScale(2 + nOpenButtonWidth), 0, KStyle::dpiScale(nSaveButtonWidth), KStyle::dpiScale(60));

}

////////////////////////////////////////////////
void KRbViewTabWidget::init()
{
	QString strButtonStyleSheet = QString("QToolButton{border:none;color:rgb(0, 0, 0);}"
										  "QToolButton:hover{background-color: rgb(220, 220, 220);border:none;color:rgb(82, 139, 139);}"
										  "QToolButton:pressed{background-color: rgb(180, 180, 180);border:none;color:rgb(0, 0, 0);}");
	KRbToolButton* formula = new KRbToolButton(this);
	formula->setObjectName("formula");
	formula->setText("formula");
	formula->setStyleSheet(strButtonStyleSheet);
	//openButton->setIcon();
	int nFormulaWidth = formula->sizeHint().width();
	formula->setGeometry(KStyle::dpiScale(2), 0, KStyle::dpiScale(nFormulaWidth), KStyle::dpiScale(60));

	KRbCheckBox* katexinline = new KRbCheckBox(this);
	katexinline->setObjectName("katexinline");
	katexinline->setText("katexinline");
	katexinline->setGeometry(KStyle::dpiScale(2 + 2 + nFormulaWidth), 0, KStyle::dpiScale(90), KStyle::dpiScale(30));

	KRbCheckBox* katexoutline = new KRbCheckBox(this);
	katexoutline->setObjectName("katexoutline");
	katexoutline->setText("katexoutline");
	katexoutline->setGeometry(KStyle::dpiScale(2 + 2 + nFormulaWidth), KStyle::dpiScale(30), KStyle::dpiScale(90), KStyle::dpiScale(30));
}
