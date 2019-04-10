#ifndef KPUSHBUTTON_H
#define KPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>

class KPushButton : public QPushButton
{
public:
	KPushButton(QWidget* parent = nullptr);

public:
	QSize sizeHint() const override;
};

#endif // KPUSHBUTTON_H
