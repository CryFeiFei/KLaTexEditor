#ifndef KFORMULATEXTEDIT_H
#define KFORMULATEXTEDIT_H

#include <QTextEdit>

class QCompleter;

class KFormulaTextEdit : public QTextEdit
{
	Q_OBJECT

public:
	KFormulaTextEdit(QWidget *parent = 0);
	~KFormulaTextEdit();

	void setCompleter(QCompleter *c);
	QCompleter *completer() const;

protected:
	void keyPressEvent(QKeyEvent *e) override;
	void focusInEvent(QFocusEvent *e) override;

private slots:
	void insertCompletion(const QString &completion);

private:
	QString textUnderCursor() const;

private:
	QCompleter *c;
	static QStringList m_textCompleter;
};

#endif // KFORMULATEXTEDIT_H
