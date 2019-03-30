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
	QSize sizeHint() const;
};

class KRbSeparatorWidget : public QWidget
{
	Q_OBJECT
public:
	using QWidget::QWidget;
	KRbSeparatorWidget(QWidget* parent = nullptr);
	~KRbSeparatorWidget();

public:
	void paintEvent(QPaintEvent* ) override;
};


#endif // KRBTOOLBUTTON_H
