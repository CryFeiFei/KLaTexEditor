#ifndef KFORMULAWIDGET_H
#define KFORMULAWIDGET_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QMenu>

class KFormulaTextEdit;

class KFormulaWidget : public QWidget
{
	Q_OBJECT
public:
	explicit KFormulaWidget(QWidget *parent = nullptr, QString strUrl = QString(), QString strTitle = QString());
	virtual ~KFormulaWidget();

public:
	void contextMenuEvent(QContextMenuEvent*) override;


signals:

public slots:
	void updateWebView(QString);
	void refershFormula();
	void refershStart();
	void doRefersh();

	//----------------- web tool slot;
public slots:
	void textColorChange(const QColor &);
	void bgColorChange(const QColor &);
	void fontSizeChange(const QString &);
	void fontTypeChange(const QString &);
	void copyToClipboard();
	void saveAs();
	void saveAsPdf();

private:
	void _dealLatexString(QString &);
	void _addOutlineString(QString &);
	void _dealFontSizeTypeString(QString &);

private:
	QWebEngineView* m_webView;
	KFormulaTextEdit* m_textEdit;
	QTimer* m_refershTimer;
	QString m_strFormula;
	QMenu* m_menu; // 右键菜单
	QString m_strUrl; // 加载的网页

	QString m_textColor; // 文本颜色的颜色
	QString m_bgColor; //背景颜色
	QString m_fontSize; //字体大小
	QString m_fontType; //字体类型

	//
	QString m_strTitle;
};

#endif // KFORMULAWIDGET_H
