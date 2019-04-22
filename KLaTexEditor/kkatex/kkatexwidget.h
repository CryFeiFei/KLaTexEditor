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
	void doRefersh();

	// web tool slot;
public slots:
	void textColorChange(const QColor &);
	void bgColorChange(const QColor &);
	void fontSizeChange(const QString &);
	void fontTypeChange(const QString &);

private:
	void _dealLatexString(QString &);
	void _addOutlineString(QString &);
	void _dealFontSizeTypeString(QString &);


public:
	void contextMenuEvent(QContextMenuEvent*) override;

private:
	// doushi out line zanshi todo
	QWebEngineView* m_webView;
	KFormulaTextEdit* m_textEdit;
	QTimer* m_refershTimer;
	QString m_strFormula;
	QMenu* m_menu; // 右键菜单

	QString m_textColor; // 文本颜色的颜色
	QString m_bgColor; //背景颜色
	QString m_fontSize; //字体大小
	QString m_fontType; //字体类型
};

#endif // KKATEXWIDGET_H
