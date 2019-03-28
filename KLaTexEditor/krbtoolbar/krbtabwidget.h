#ifndef KRBTABWIDGET_H
#define KRBTABWIDGET_H

#include <QWidget>
#include <QHBoxLayout>

class KRbTabWidget : public QWidget
{
	Q_OBJECT
public:
	KRbTabWidget(QWidget *parent = nullptr);
	~KRbTabWidget();

public:
	void addToolWidget(QWidget* );
	virtual void init() = 0;

signals:

public slots:

private:
	QHBoxLayout* m_mainLayout;
};

////////////////////////
class KRbStartTabWidget : public KRbTabWidget
{
	Q_OBJECT
public:
	using KRbTabWidget::KRbTabWidget;
	KRbStartTabWidget(QWidget* parent = nullptr);
	virtual void init();

};

#endif // KRBTABWIDGET_H
