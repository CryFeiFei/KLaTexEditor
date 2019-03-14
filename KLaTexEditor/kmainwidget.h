//////////////////////////////////////////////////////
//MIT
// auther : CryFeiFei
// email : zhangpf@gmain.com
// time : 2019-3-13 23:29
///////////////////////////////////////////////////////
#ifndef KMAINWIDGET_H
#define KMAINWIDGET_H

#include <QWidget>
#include <QApplication>

class QSplitter;
class KTitleWidget;

class KMainWidget : public QWidget
{
	Q_OBJECT
public:
	using QWidget::QWidget;
	explicit KMainWidget(QWidget *parent = nullptr);
	~KMainWidget();

signals:

public slots:
	void ShowMiniSize();
	void ShowMaxSize();
	void Close();

private:
	void _centerToScreen(QWidget* widget);

private:
	KTitleWidget* m_titleBar;
	QWidget* m_toolBar;
	QSplitter* m_Splitter;
private:
	Q_DISABLE_COPY(KMainWidget)
};

#endif // KMAINWIDGET_H
