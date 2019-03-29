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
	label->setFixedHeight(KStyle::dpiScale(20));

	m_inlineView = new QWebEngineView(this);
	m_outlineView = new QWebEngineView(this);

	m_inlineView->load(QUrl("qrc:/html/resource/katex.html"));
	m_outlineView->load(QUrl("qrc:/html/resource/katex.html"));

	m_inlineView->setEnabled(false);
	m_outlineView->setEnabled(false);
	m_inlineView->setContextMenuPolicy(Qt::NoContextMenu);
	m_outlineView->setContextMenuPolicy(Qt::NoContextMenu);

	m_inlineView->setMinimumSize(KStyle::dpiScale(380), KStyle::dpiScale(120));
	m_outlineView->setMinimumSize(KStyle::dpiScale(380), KStyle::dpiScale(120));
	QWidget* toolWidget = new QWidget(this);
	toolWidget->setStyleSheet("background-color:red;");
	toolWidget->setFixedHeight(KStyle::dpiScale(30));

	this->setMinimumWidth(KStyle::dpiScale(380));
	mainLayout->addWidget(label);
	mainLayout->addWidget(m_inlineView);
	mainLayout->addWidget(m_outlineView);
	mainLayout->addWidget(toolWidget);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(1);

}

void KKatexWidget::updateWebView(QString strFormula)
{
	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormula);

	m_inlineView->page()->runJavaScript(runJS);
	m_outlineView->page()->runJavaScript(runJS);
}
