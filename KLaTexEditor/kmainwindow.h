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

private:
	Ui::KMainWindow *ui;
};

#endif // MAINWINDOW_H
