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

	m_webView = new QWebEngineView(this);
	m_webView->load(QUrl("qrc:/html/resource/katex.html"));
	m_webView->setEnabled(false);
	m_webView->setContextMenuPolicy(Qt::NoContextMenu);

	m_webView->setMinimumSize(KStyle::dpiScale(380), KStyle::dpiScale(120));
	QWidget* toolWidget = new QWidget(this);
	toolWidget->setStyleSheet("background-color:red;");
	toolWidget->setFixedHeight(KStyle::dpiScale(30));

	this->setMinimumWidth(KStyle::dpiScale(380));
	mainLayout->addWidget(label);
	mainLayout->addWidget(m_webView);
	mainLayout->addWidget(toolWidget);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(1);
}

void KKatexWidget::updateWebView(QString strFormula)
{
	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormula);

	m_webView->page()->runJavaScript(runJS);
}
