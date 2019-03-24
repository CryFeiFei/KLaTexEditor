//MIT
//ribbon tool bar
//email:zhangpf0313@gmail.com

#ifndef KRBTOOLBAR_H
#define KRBTOOLBAR_H

#include <QWidget>
#include <QStackedWidget>

class KRbTabBar;

class KRbToolBar : public QWidget
{
	Q_OBJECT
public:
	explicit KRbToolBar(QWidget *parent = nullptr);

signals:

public slots:

private:
	KRbTabBar* m_rbTabBar;
	QStackedWidget* m_rbTabWidget;
//	QWidget* m_rbTabWidget;
};

#endif // KRBTOOLBAR_H
