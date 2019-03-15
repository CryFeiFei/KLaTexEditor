#ifndef KSUBMAINWIDGET_H
#define KSUBMAINWIDGET_H

#include <QWidget>

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

private:
	Ui::KSubMainWidget *ui;
};

#endif // KSUBMAINWIDGET_H
