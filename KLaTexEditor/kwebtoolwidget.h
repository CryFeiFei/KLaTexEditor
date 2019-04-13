//auther : zhangpf
//email :zhangpf0313@gmail.com
//data:2019年3月30日14:22:52
#ifndef KWEBTOOLWIDGET_H
#define KWEBTOOLWIDGET_H

#include <QWidget>
#include <QPushButton>
//add color select widget
//add copy save tool widget
// inset outset

class KWebToolSeparate : public QWidget
{
	Q_OBJECT
public:
	using QWidget :: QWidget;
	explicit KWebToolSeparate(QWidget* parent = nullptr);
	~KWebToolSeparate();

public:
	void paintEvent(QPaintEvent* e) override;
	QSize sizeHint() const override;
};

class KColorLabel;

class KWebToolWidget : public QWidget
{
	Q_OBJECT
public:
	explicit KWebToolWidget(QWidget *parent = nullptr);
	~KWebToolWidget();

signals:
	void textColorChanged(const QColor &);
	void bgColorChanged(const QColor &);
	void fontSizeChanged(const QString &);
	void fontTypeChanged(const QString &);
	void copyToClipboard();
	void saveAs();

public slots:

private:
	KColorLabel* m_textColorLabel;
	KColorLabel* m_bgColorLabel;
};

#endif // KWEBTOOLWIDGET_H
