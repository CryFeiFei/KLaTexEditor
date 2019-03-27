#include "kkatexwidget.h"
#include "kglobal.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSplitter>

KKatexWidget::KKatexWidget(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	QLabel* label = new QLabel(this);
	label->setText("katex");
	label->setFixedHeight(KStyle::dpiScale(15));

	m_inlineView = new QWebEngineView(this);
	m_outlineView = new QWebEngineView(this);

	m_inlineView->load(QUrl("qrc:/html/resource/katex.html"));
	m_outlineView->load(QUrl("qrc:/html/resource/katex.html"));

//	webSplitter->addWidget(m_inlineView);
//	webSplitter->addWidget(m_outlineView);

//	webSplitter->setStretchFactor(0, 1);
//	webSplitter->setStretchFactor(0, 1);

	QWidget* toolWidget = new QWidget(this);
	toolWidget->setStyleSheet("backgroud-color: red");
	toolWidget->setFixedHeight(KStyle::dpiScale(15));


	mainLayout->addWidget(label);
	mainLayout->addWidget(m_inlineView);
	mainLayout->addWidget(m_outlineView);
	mainLayout->addWidget(toolWidget);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);

}
