#include "kmainwindow.h"
#include "ui_kmainwindow.h"

#include "kmainwidget.h"

KMainWindow::KMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::KMainWindow)
{
	ui->setupUi(this);
	KMainWidget* mainWidget = new KMainWidget(this);
	setCentralWidget(mainWidget);
}

KMainWindow::~KMainWindow()
{
	delete ui;
}
