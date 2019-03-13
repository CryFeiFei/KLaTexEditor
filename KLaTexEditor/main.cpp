#include "kmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	KMainWindow w;
	w.show();

	return a.exec();
}
