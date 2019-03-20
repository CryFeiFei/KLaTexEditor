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

private:
	QTimer* m_refershTimer;
	Ui::KSubMainWidget *ui;
	QString m_strFormula;
	QWebEngineView* m_webView;
};

#endif // KSUBMAINWIDGET_H