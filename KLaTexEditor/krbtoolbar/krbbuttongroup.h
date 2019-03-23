#ifndef KRBBUTTONGROUP_H
#define KRBBUTTONGROUP_H

#include <QWidget>
//class KRbTabButton : public QWidget
//{
//	Q_OBJECT
//public:
//	KRbTabButton(QWidget* parent = nullptr);
//	~KRbTabButton();
//};

class KRbButtonGroup : public QWidget
{
	Q_OBJECT
public:
	KRbButtonGroup(QWidget *parent = nullptr);
	void paintEvent(QPaintEvent* );

signals:

public slots:
};

#endif // KRBBUTTONGROUP_H
