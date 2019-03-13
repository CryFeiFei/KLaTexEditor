#include "kmainwindow.h"
#include "ui_kmainwindow.h"

KMainWindow::KMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::KMainWindow)
{
	ui->setupUi(this);
}

KMainWindow::~KMainWindow()
{
	delete ui;
}
