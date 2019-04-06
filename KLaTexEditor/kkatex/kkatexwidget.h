#ifndef KKATEXWIDGET_H
#define KKATEXWIDGET_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>

class KFormulaTextEdit;

class KKatexWidget : public QWidget
{
	Q_OBJECT
public:
	explicit KKatexWidget(QWidget *parent = nullptr);

signals:

public slots:
	void updateWebView(QString);

public slots:
	void refershFormula();
	void refershStart();

private:
	QString _dealLatexString(QString &);

private:
	// doushi out line zanshi todo
	QWebEngineView* m_webView;
	KFormulaTextEdit* m_textEdit;
	QTimer* m_refershTimer;
	QString m_strFormula;
};

#endif // KKATEXWIDGET_H
