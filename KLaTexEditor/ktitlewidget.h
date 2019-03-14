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
	void miniButtonClicked();
	void maxButtonClicked();
	void closeButtonClicked();

protected:
	void mousePressEvent(QMouseEvent* e) override;
	void mouseMoveEvent(QMouseEvent *e) override;
	void mouseReleaseEvent(QMouseEvent *e) override;
private:
	bool m_bPress;
	QPoint m_movePos;
	QPoint m_parentPos;
};

#endif // KTITLEWIDGET_H
