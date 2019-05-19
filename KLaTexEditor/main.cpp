#include <QApplication>
#include "kmainwidget.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
//	a.setWindowIcon(QIcon("qrc::/application/resource/image/application/formula.svg"));
	KMainWidget w;
	w.show();
	return a.exec();
}
