#ifndef KFORMULATEXTEDIT_H
#define KFORMULATEXTEDIT_H

//#include <QTextEdit>

//class KFormulaTextEdit : public QTextEdit
//{
//public:
//	explicit KFormulaTextEdit(QWidget* parent = nullptr);
//	~KFormulaTextEdit();
//};


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
};

#endif // KFORMULATEXTEDIT_H
