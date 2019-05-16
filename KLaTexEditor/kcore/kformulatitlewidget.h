#ifndef KFORMULATITLEWIDGET_H
#define KFORMULATITLEWIDGET_H

#include <QWidget>

class KPushButton;
class KFormulaTitleWidget : public QWidget
{
	Q_OBJECT
public:
	explicit KFormulaTitleWidget(QString strTitle = QString(), QWidget *parent = nullptr);

public:
	void paintEvent(QPaintEvent* ) override;

signals:
	void refresh();

public slots:

private:
	QString m_strTitle;
	KPushButton* m_refreshBtn;
};

#endif // KFORMULATITLEWIDGET_H
