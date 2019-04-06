#ifndef KWEBFORMULASTRING_H
#define KWEBFORMULASTRING_H

#include <QObject>

class KWebFormulaString : public QObject
{
	Q_OBJECT
public:
	explicit KWebFormulaString(QObject *parent = nullptr);
	~KWebFormulaString();
signals:

public slots:

private:
	QString m_formula;
	QString m_textColor;
	QString m_bgColor;
	QString m_fontSize;
	QString m_fontType;
};

#endif // KWEBFORMULASTRING_H
