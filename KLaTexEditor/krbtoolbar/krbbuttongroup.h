#ifndef KRBBUTTONGROUP_H
#define KRBBUTTONGROUP_H

#include <QWidget>
#include <QPushButton>
class KRbTabButton : public QPushButton
{
	Q_OBJECT
public:
	KRbTabButton(QWidget* parent = nullptr);
	~KRbTabButton();
};

class KRbButtonGroup : public QWidget
{
	Q_OBJECT
public:
	KRbButtonGroup(QWidget *parent = nullptr);
	void paintEvent(QPaintEvent* );

signals:

public slots:

private:
	KRbTabButton* m_startButton;
	KRbTabButton* m_viewButton;
};

#endif // KRBBUTTONGROUP_H
