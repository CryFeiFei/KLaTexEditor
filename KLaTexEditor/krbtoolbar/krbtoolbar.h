//MIT
//ribbon tool bar
//email:zhangpf0313@gmail.com

#ifndef KRBTOOLBAR_H
#define KRBTOOLBAR_H

#include <QWidget>
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
	QWidget* m_rbTabWidget;
};

#endif // KRBTOOLBAR_H
