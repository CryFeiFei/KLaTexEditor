#ifndef KRBTABBAR_H
#define KRBTABBAR_H

#include <QWidget>
#include <QButtonGroup>

class KRbButtonGroup;

class KRbTabBar : public QWidget
{
	Q_OBJECT
public:
	KRbTabBar(QWidget *parent = nullptr);
	~KRbTabBar();

signals:

public slots:

private:
	QWidget* m_miniToolWidget;
	KRbButtonGroup* m_buttonGroup;
};

#endif // KRBTABBAR_H
