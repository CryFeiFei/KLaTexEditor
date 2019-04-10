//auther : zhangpf
//email :zhangpf0313@gmail.com
//data:2019年3月30日14:22:52
#ifndef KWEBTOOLWIDGET_H
#define KWEBTOOLWIDGET_H

#include <QWidget>
#include <QPushButton>

//add color select widget
//add copy save tool widget
// inset outset

class KWebToolSeparate : public QWidget
{
	Q_OBJECT
public:
	using QWidget :: QWidget;
	explicit KWebToolSeparate(QWidget* parent = nullptr);
	~KWebToolSeparate();

public:
	void paintEvent(QPaintEvent* e) override;
	QSize sizeHint() const override;
};

class KWebToolWidget : public QWidget
{
	Q_OBJECT
public:
	explicit KWebToolWidget(QWidget *parent = nullptr);
	~KWebToolWidget();

signals:

public slots:
};

#endif // KWEBTOOLWIDGET_H
