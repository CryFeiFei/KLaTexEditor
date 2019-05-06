#ifndef KSUBMAINWIDGET_H
#define KSUBMAINWIDGET_H

#include <QWidget>
#include <QWebEngineView>
class QTimer;
class KKatexWidget;
class KMathJaxWidget;
class KFormulaWidget;


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
	KFormulaWidget* m_katexWidget;
	KFormulaWidget* m_mathjaxWidget;
};

#endif // KSUBMAINWIDGET_H
