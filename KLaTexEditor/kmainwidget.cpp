#include "kmainwidget.h"
#include <QVBoxLayout>
#include <QSplitter>
#include <ktitlewidget.h>
#include <QDesktopWidget>
#include <QTextEdit>
#include "ksubmainwidget.h"
///////////////
#include "krbtoolbar/krbtoolbar.h"
//////////////

KMainWidget::KMainWidget(QWidget *parent) : QWidget(parent)
{
	setObjectName("KMainWidget");

//	setWindowFlags(Qt::FramelessWindowHint);

	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	// title bar
	m_titleBar = new KTitleWidget(this);
	connect(m_titleBar, SIGNAL(miniButtonClicked()), this, SLOT(ShowMiniSize()));
	connect(m_titleBar, SIGNAL(maxButtonClicked()), this, SLOT(ShowMaxSize()));
	connect(m_titleBar, SIGNAL(closeButtonClicked()), this, SLOT(Close()));
	mainLayout->addWidget(m_titleBar);
	m_titleBar->setVisible(false);

	m_toolBar = new KRbToolBar(this);
	m_toolBar->setStyleSheet("background-color: rgb(245, 245, 245)");
	m_toolBar->setMinimumHeight(100);
	m_toolBar->setMaximumHeight(100);
	mainLayout->addWidget(m_toolBar);

	m_subMainWidget = new KSubMainWidget(this);
	mainLayout->addWidget(m_subMainWidget);

	mainLayout->setMargin(0);
	mainLayout->setSpacing(0);
	setLayout(mainLayout);

	resize(700, 700);
	_centerToScreen(this);
}

KMainWidget::~KMainWidget()
{

}

void KMainWidget::ShowMiniSize()
{
	this->showMinimized();
}

void KMainWidget::ShowMaxSize()
{
	this->showMaximized();
}

void KMainWidget::Close()
{
	this->close();
}

void KMainWidget::_centerToScreen(QWidget * widget)
{
	if (!widget)
		return;
	QDesktopWidget* m = QApplication::desktop();
	QRect desk_rect = m->screenGeometry(m->screenNumber(QCursor::pos()));
	int desk_x = desk_rect.width();
	int desk_y = desk_rect.height();
	int x = widget->width();
	int y = widget->height();
	widget->move(desk_x / 2 - x / 2 + desk_rect.left(), desk_y / 2 - y / 2 + desk_rect.top());
}
