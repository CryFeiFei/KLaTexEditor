#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class KMainWindow;
}

class KMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit KMainWindow(QWidget *parent = nullptr);
	~KMainWindow();

public slots:
	void onPositionChange(const QPoint& point);

private:
	Ui::KMainWindow *ui;
};

#endif // MAINWINDOW_H
