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
/// \brief KRbViewTabWidget::init
///
#define STARTSPACE 2
#define NORMALSPACE 4
void KRbViewTabWidget::init()
{
	//todo 这里应该改成自定义layout + groupBox 这么写太挫了
	QString strButtonStyleSheet = QString("QToolButton{border:none;color:rgb(0, 0, 0);}"
										  "QToolButton:hover{background-color: rgb(220, 220, 220);border:none;color:rgb(82, 139, 139);}"
										  "QToolButton:pressed{background-color: rgb(180, 180, 180);border:none;color:rgb(0, 0, 0);}");
	int nSpace = STARTSPACE;
	KRbToolButton* formula = new KRbToolButton(this);
	formula->setObjectName("formula");
	formula->setText("formula");
	formula->setStyleSheet(strButtonStyleSheet);
	//openButton->setIcon();
	int nFormulaWidth = formula->sizeHint().width();
	formula->setGeometry(KStyle::dpiScale(nSpace), 0, KStyle::dpiScale(nFormulaWidth), KStyle::dpiScale(60));

	// ---------------------katex group
	nSpace += NORMALSPACE + nFormulaWidth;
	KRbCheckBox* katexInline = new KRbCheckBox(this);
	katexInline->setObjectName("KatexInlineCheckBox");
	katexInline->setText("KatexInline");
	int nKatexInline = katexInline->sizeHint().width();

	KRbCheckBox* katexOutline = new KRbCheckBox(this);
	katexOutline->setObjectName("KatexOutlineCheckBox");
	katexOutline->setText("KatexOutline");
	int nKatexOutline = katexOutline->sizeHint().width();

	int nMaxKatexCbWidth = nKatexInline > nKatexOutline ? nKatexInline : nKatexOutline;
	katexInline->setGeometry(KStyle::dpiScale(nSpace), 0, KStyle::dpiScale(nMaxKatexCbWidth), KStyle::dpiScale(30));
	katexOutline->setGeometry(KStyle::dpiScale(nSpace), KStyle::dpiScale(30), KStyle::dpiScale(nMaxKatexCbWidth), KStyle::dpiScale(30));

	//------------------------mathjax group
	nSpace += NORMALSPACE + nMaxKatexCbWidth;

	KRbCheckBox* mathJaxInLine = new KRbCheckBox(this);
	mathJaxInLine->setObjectName("MathJaxInlineCheckbox");
	mathJaxInLine->setText("MathJaxInline");
	int nMathJaxInline = mathJaxInLine->sizeHint().width();
	KRbCheckBox* mathJaxOutLine = new KRbCheckBox(this);
	mathJaxOutLine->setObjectName("MathJaxOutlineCheckbox");
	mathJaxOutLine->setText("MathJaxOutline");
	int nMathJaxOutline = mathJaxOutLine->sizeHint().width();

	int nMaxJaxCheckBox = nMathJaxInline > nMathJaxOutline ? nMathJaxInline : nMathJaxOutline;
	mathJaxInLine->setGeometry(KStyle::dpiScale(nSpace), 0, KStyle::dpiScale(nMaxJaxCheckBox), KStyle::dpiScale(30));
	mathJaxOutLine->setGeometry(KStyle::dpiScale(nSpace), KStyle::dpiScale(30), KStyle::dpiScale(nMaxJaxCheckBox), KStyle::dpiScale(30));

	nSpace += nMaxJaxCheckBox;
	KRbSeparatorWidget* spe = new KRbSeparatorWidget(this);
	spe->setGeometry(KStyle::dpiScale(nSpace), 0, KStyle::dpiScale(7), KStyle::dpiScale(30));
}
