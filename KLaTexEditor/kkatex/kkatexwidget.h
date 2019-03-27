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

private:
	// doushi out line zanshi todo
	QWebEngineView* m_inlineView;
	QWebEngineView* m_outlineView;
};

#endif // KKATEXWIDGET_H
