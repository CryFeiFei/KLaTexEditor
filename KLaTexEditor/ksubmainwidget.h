#ifndef KSUBMAINWIDGET_H
#define KSUBMAINWIDGET_H

#include <QWidget>
#include <QWebEngineView>
class QTimer;


namespace Ui {
class KSubMainWidget;
}

class KSubMainWidget : public QWidget
{
	Q_OBJECT

public:
	explicit KSubMainWidget(QWidget *parent = 0);
	~KSubMainWidget();

public slots:
	void refershFormula();
	void refershStart();
	void referMathJax();

private:
	QTimer* m_refershTimer;
	Ui::KSubMainWidget *ui;
	QString m_strFormula;
	QWebEngineView* m_webView;
	QWebEngineView* m_mathjaxView;
};

#endif // KSUBMAINWIDGET_H
