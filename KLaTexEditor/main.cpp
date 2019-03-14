#include <QApplication>
#include "kmainwidget.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KMainWidget w;
	w.show();
	return a.exec();
}
