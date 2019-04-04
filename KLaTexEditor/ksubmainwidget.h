#ifndef KSUBMAINWIDGET_H
#define KSUBMAINWIDGET_H

#include <QWidget>
#include <QWebEngineView>
class QTimer;
class KKatexWidget;
class KMathJaxWidget;


namespace Ui {
class KSubMainWidget;
}

class KSubMainWidget : public QWidget
{
	Q_OBJECT

public:
	explicit KSubMainWidget(QWidget *parent = 0);
	~KSubMainWidget();

private:
	Ui::KSubMainWidget *ui;
	KKatexWidget* m_katexWidget;
	KMathJaxWidget* m_mathjaxWidget;
};

#endif // KSUBMAINWIDGET_H
