#ifndef KSUBMAINWIDGET_H
#define KSUBMAINWIDGET_H

#include <QWidget>
#include <QWebEngineView>
class QTimer;
class KKatexWidget;
class KMathJaxWidget;


namespace Ui {
class KSubMainWidget;
}

class KSubMainWidget : public QWidget
{
	Q_OBJECT

public:
	explicit KSubMainWidget(QWidget *parent = 0);
	~KSubMainWidget();

public slots:
	void refershFormula();
	void refershStart();
	void referMathJax();

signals:
	void updateFormula(QString);

private:
	QString _dealLatexString(QString& strLatex);

private:
	QTimer* m_refershTimer;
	Ui::KSubMainWidget *ui;
	QString m_strFormula;
	KKatexWidget* m_katexWidget;
	KMathJaxWidget* m_mathjaxWidget;
};

#endif // KSUBMAINWIDGET_H
