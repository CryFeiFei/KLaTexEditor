#ifndef KTITLEWIDGET_H
#define KTITLEWIDGET_H

#include <QWidget>

namespace Ui {
class KTitleWidget;
}

class KTitleWidget : public QWidget
{
	Q_OBJECT
private:
	Q_DISABLE_COPY(KTitleWidget)

public:
	explicit KTitleWidget(QWidget *parent = nullptr);
	~KTitleWidget();

private:
	Ui::KTitleWidget *ui;

signals:
	void positionChanged(const QPoint& offset);
	void homeBtnClicked();
	void closeBtnClicked();
protected:
	void mousePressEvent(QMouseEvent* e) override;
	void mouseMoveEvent(QMouseEvent *e) override;
	void mouseReleaseEvent(QMouseEvent *e) override;
private:
	bool m_bPress;
	QPoint m_movePos;
};

#endif // KTITLEWIDGET_H
