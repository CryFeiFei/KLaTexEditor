#ifndef KRBTOOLBUTTON_H
#define KRBTOOLBUTTON_H

#include <QToolButton>

class KRbToolButton : public QToolButton
{
	Q_OBJECT
public:
	KRbToolButton(QWidget *parent = nullptr);
	~KRbToolButton();
};

#endif // KRBTOOLBUTTON_H
