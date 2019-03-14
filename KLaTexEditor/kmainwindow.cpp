#include "kmainwindow.h"
#include "ui_kmainwindow.h"

#include "kmainwidget.h"
#include <QLayout>

KMainWindow::KMainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::KMainWindow)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	KMainWidget* mainWidget = new KMainWidget(this);
	setCentralWidget(mainWidget);
	QLayout* mainLayout = this->layout();
	mainLayout->setMargin(0);
	this->setContentsMargins(0, 0, 0, 0);
	connect(mainWidget, SIGNAL(positionchanged(const QPoint&)), this, SLOT(onPositionChange(const QPoint&)));
}

KMainWindow::~KMainWindow()
{
	delete ui;
}

void KMainWindow::onPositionChange(const QPoint &point)
{
	this->move(point);
}
