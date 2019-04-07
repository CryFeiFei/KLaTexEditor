#ifndef KKATEXWIDGET_H
#define KKATEXWIDGET_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QMenu>

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

public:
	void contextMenuEvent(QContextMenuEvent*) override;

private:
	// doushi out line zanshi todo
	QWebEngineView* m_webView;
	KFormulaTextEdit* m_textEdit;
	QTimer* m_refershTimer;
	QString m_strFormula;

	QMenu* m_menu;
};

#endif // KKATEXWIDGET_H
