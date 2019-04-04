#include "kkatexwidget.h"
#include "kglobal.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSplitter>

#include "kwebtoolwidget.h"

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

	KWebToolWidget* webToolWidget = new KWebToolWidget(this);
	webToolWidget->setStyleSheet("background-color:gray;");
	webToolWidget->setFixedHeight(KStyle::dpiScale(30));

	m_textEdit = new QTextEdit(this);
	m_textEdit->setMinimumHeight(KStyle::dpiScale(60));

	QSplitter* mainSplitter = new QSplitter(Qt::Vertical, this);
	mainSplitter->addWidget(m_webView);
	mainSplitter->addWidget(webToolWidget);
	mainSplitter->addWidget(m_textEdit);
	mainSplitter->setChildrenCollapsible(false);

	this->setMinimumWidth(KStyle::dpiScale(380));
	mainLayout->addWidget(label);
	mainLayout->addWidget(mainSplitter);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(1);

	m_refershTimer = new QTimer(this);

	connect(m_textEdit, SIGNAL(textChanged()), SLOT(refershStart()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(refershFormula()));
}

void KKatexWidget::updateWebView(QString strFormula)
{
	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormula);

	m_webView->page()->runJavaScript(runJS);
}

void KKatexWidget::refershStart()
{
	//开始启动刷新
	if (m_refershTimer->isActive())
		return;

	m_refershTimer->start(1000);
}

void KKatexWidget::refershFormula()
{
	QString strFormat = m_textEdit->toPlainText();

	// 文本没有变化的话，不用刷新。
	if (m_strFormula == m_textEdit->toPlainText())
		return;

//	m_strFormula = strFormat;
	strFormat = _dealLatexString(strFormat);

//	emit updateFormula(strFormat);
	updateWebView(strFormat);
}

QString KKatexWidget::_dealLatexString(QString &strLatex)
{
	strLatex.replace("\\", "\\\\");
	//delete space
//	strFormatA.remove(QRegExp("\\s"));
	strLatex.remove(QRegExp("[\r\n]"));
	strLatex.insert(0, QString("$$"));
	strLatex.append(QString("$$"));

	return strLatex;
}
