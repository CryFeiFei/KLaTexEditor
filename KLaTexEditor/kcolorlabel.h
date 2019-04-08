#ifndef KCOLORLABEL_H
#define KCOLORLABEL_H

#include <QWidget>
#include <QObject>

class KColorLabel : public QWidget
{
	Q_OBJECT
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChange)
	Q_PROPERTY(QColor color MEMBER m_bgColor NOTIFY colorChange)
public:
	KColorLabel(QWidget *parent = nullptr);
	~KColorLabel();

public:
	QColor color();
	void setColor(QColor color);
	QString toolTipPrefix();
	void setToolTipPrefix(QString strToolTipPrefix);

public:
	bool event(QEvent *event) override;
	void paintEvent(QPaintEvent* ) override;
	QSize sizeHint() const override;

signals:
	void colorChange();

public slots:

private:
	QColor m_bgColor;
	QString m_strToolTipPrefix;
};

#endif // KCOLORLABEL_H
