//////////////////////////////////////////////////////
//MIT
// auther : CryFeiFei
// email : zhangpf@gmain.com
// time : 2019-3-13 23:29
///////////////////////////////////////////////////////
#ifndef KMAINWIDGET_H
#define KMAINWIDGET_H

#include <QWidget>

class QSplitter;

class KMainWidget : public QWidget
{
	Q_OBJECT
public:
	using QWidget::QWidget;
	explicit KMainWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
	QWidget* m_titleBar;
	QWidget* m_toolBar;
	QSplitter* m_Splitter;
private:
	Q_DISABLE_COPY(KMainWidget)
};

#endif // KMAINWIDGET_H
