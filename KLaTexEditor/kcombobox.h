#ifndef KCOMBOBOX_H
#define KCOMBOBOX_H

#include <QWidget>
#include <QComboBox>

class KComboBox : public QComboBox
{
	Q_OBJECT
public:
	KComboBox(QWidget* parent = nullptr);
	~KComboBox();

public:
	QString toolTipPrefix();
	void setToolTipPrefix(QString strToolTipPrefix);
	void setBackGoundColor(QColor color);

public:
	QSize sizeHint() const override;
	bool event(QEvent *event) override;
	void paintEvent(QPaintEvent* event) override;

public slots:

private:
	QString m_strToolTipPrefix;
	QColor m_bgColor;
};

#endif // KCOMBOBOX_H
