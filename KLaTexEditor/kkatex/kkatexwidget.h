#ifndef KKATEXWIDGET_H
#define KKATEXWIDGET_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>

class KKatexWidget : public QWidget
{
	Q_OBJECT
public:
	explicit KKatexWidget(QWidget *parent = nullptr);

signals:

public slots:
	void updateWebView(QString);

private:
	// doushi out line zanshi todo
	QWebEngineView* m_webView;
};

#endif // KKATEXWIDGET_H
