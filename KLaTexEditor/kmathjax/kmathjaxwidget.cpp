﻿#include "kmathjaxwidget.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSplitter>
#include "kglobal.h"
#include "kwebtoolwidget.h"
#include "kformulatextedit.h"

KMathJaxWidget::KMathJaxWidget(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	QLabel* label = new QLabel(this);
	label->setText("mathjax");
	label->setFixedHeight(KStyle::dpiScale(20));

	m_webView = new QWebEngineView(this);

	m_webView->load(QUrl("qrc:/html/resource/mathjax.html"));

	m_webView->setMinimumSize(KStyle::dpiScale(380), KStyle::dpiScale(120));
	m_webView->setEnabled(false);
	m_webView->setContextMenuPolicy(Qt::NoContextMenu);
	m_webView->resize(KStyle::dpiScale(380), KStyle::dpiScale(280));

	KWebToolWidget* webToolWidget = new KWebToolWidget(this);
	webToolWidget->setStyleSheet("background-color:gray;");
	webToolWidget->setFixedHeight(KStyle::dpiScale(30));

	m_textEdit = new KFormulaTextEdit(this);
	QSplitter* splitter = new QSplitter(Qt::Vertical, this);
	splitter->addWidget(m_webView);
	splitter->addWidget(webToolWidget);
	splitter->addWidget(m_textEdit);
	splitter->setChildrenCollapsible(false);

	this->setMinimumWidth(KStyle::dpiScale(380));
	mainLayout->addWidget(label);
	mainLayout->addWidget(splitter);
//	mainLayout->addWidget(webToolWidget);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(1);

	m_refershTimer = new QTimer(this);

	connect(m_textEdit, SIGNAL(textChanged()), SLOT(refershStart()));
	connect(m_refershTimer, SIGNAL(timeout()), this, SLOT(refershFormula()));

	connect(webToolWidget, &KWebToolWidget::textColorChanged, this, &KMathJaxWidget::textColorChange);
}

void KMathJaxWidget::updateWebView(QString strFormula)
{
	QString runJS = QString("renderLatexByRaw(\"%1\")").arg(strFormula);

	m_webView->page()->runJavaScript(runJS);
}

void KMathJaxWidget::refershStart()
{
	//开始启动刷新
	if (m_refershTimer->isActive())
		return;

	m_refershTimer->start(1000);
}

void KMathJaxWidget::refershFormula()
{
	QString strFormat = m_textEdit->toPlainText();

	// 文本没有变化的话，不用刷新。
	if (m_strFormula == m_textEdit->toPlainText())
		return;

	m_strFormula = strFormat;
	strFormat = _dealLatexString(strFormat);

	strFormat = QString("\\color {#%1}{%2}").arg(m_textColor).arg(strFormat);

//	emit updateFormula(strFormat);
	updateWebView(strFormat);
}

QString KMathJaxWidget::_dealLatexString(QString &strLatex)
{
	strLatex.replace("\\", "\\\\");
	//delete space
//	strFormatA.remove(QRegExp("\\s"));
	strLatex.remove(QRegExp("[\r\n]"));
	strLatex.insert(0, QString("$$"));
	strLatex.append(QString("$$"));

	return strLatex;
}

void KMathJaxWidget::textColorChange(const QColor &color)
{
	m_textColor = color.name(QColor::HexRgb);
	qDebug()<<m_textColor<<endl;
//	\color {#rgb}{text}
//	m_textColor = QString("\\color {#%1}{}")
}

void KMathJaxWidget::bgColorChange(const QColor &color)
{

}

void KMathJaxWidget::fontSizeChange(const QString &fs)
{

}

void KMathJaxWidget::fontTypeChange(const QString &ft)
{

}
