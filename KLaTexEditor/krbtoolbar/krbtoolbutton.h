#ifndef KRBTOOLBUTTON_H
#define KRBTOOLBUTTON_H

#include <QToolButton>
#include <QCheckBox>

//todo sizehint
class KRbToolButton : public QToolButton
{
	Q_OBJECT
public:
	KRbToolButton(QWidget *parent = nullptr);
	~KRbToolButton();
	QSize sizeHint() const;
};

class KRbCheckBox : public QCheckBox
{
	Q_OBJECT
public:
	using QCheckBox::QCheckBox;
	KRbCheckBox(QWidget *parent = nullptr);
	~KRbCheckBox();
};

#endif // KRBTOOLBUTTON_H
