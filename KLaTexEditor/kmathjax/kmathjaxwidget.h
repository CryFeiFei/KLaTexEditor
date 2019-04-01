#ifndef KMATHJAXWIDGET_H
#define KMATHJAXWIDGET_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>

class KMathJaxWidget : public QWidget
{
	Q_OBJECT
public:
	explicit KMathJaxWidget(QWidget *parent = nullptr);

signals:

public slots:
	void updateWebView(QString);

private:
	QWebEngineView* m_webView;
};

#endif // KMATHJAXWIDGET_H
