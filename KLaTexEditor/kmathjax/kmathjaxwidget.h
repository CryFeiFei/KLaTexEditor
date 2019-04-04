#ifndef KMATHJAXWIDGET_H
#define KMATHJAXWIDGET_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QTextEdit>

class KMathJaxWidget : public QWidget
{
	Q_OBJECT
public:
	explicit KMathJaxWidget(QWidget *parent = nullptr);

signals:

public slots:
	void updateWebView(QString);

public slots:
	void refershFormula();
	void refershStart();

private:
	QString _dealLatexString(QString &);

private:
	QWebEngineView* m_webView;
	QTextEdit* m_textEdit;
	QTimer* m_refershTimer;
	QString m_strFormula;
};

#endif // KMATHJAXWIDGET_H
