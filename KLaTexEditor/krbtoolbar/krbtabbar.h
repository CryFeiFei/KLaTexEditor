#ifndef KRBTABBAR_H
#define KRBTABBAR_H

#include <QWidget>
#include <QTabBar>

class KRbTabBarImp : public QTabBar
{

};

class KRbTabBar : public QWidget
{
	Q_OBJECT
public:
	explicit KRbTabBar(QWidget *parent = nullptr);
	~KRbTabBar();

signals:

public slots:

private:
	QWidget* m_miniToolWidget;
	QTabBar* m_tabbar;
};

#endif // KRBTABBAR_H
