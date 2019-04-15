#ifndef KMATHJAXWIDGET_H
#define KMATHJAXWIDGET_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>

class KFormulaTextEdit;

class KMathJaxWidget : public QWidget
{
	Q_OBJECT
public:
	explicit KMathJaxWidget(QWidget *parent = nullptr);

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

private:
	QWebEngineView* m_webView;
	KFormulaTextEdit* m_textEdit;
	QTimer* m_refershTimer;
	QString m_strFormula;


//	void textColorChanged(const QColor &);
//	void bgColorChanged(const QColor &);
//	void fontSizeChanged(const QString &);
//	void fontTypeChanged(const QString &);
//	void copyToClipboard();
//	void saveAs();
	QString m_textColor; // 文本颜色的颜色
	QString m_bgColor; //背景颜色
	QString m_fontSize; //字体大小
	QString m_fontType; //字体类型
};

#endif // KMATHJAXWIDGET_H
