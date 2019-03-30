#ifndef KGLOBAL_H
#define KGLOBAL_H

#include <QObject>
#ifdef Q_OS_UNIX
#include <QtX11Extras/QX11Info>
#endif
#include <QtCore>
#include <QtGui>
#ifdef QT_DEBUG
#include <QDebug>
#endif

class KStyle : public QObject
{
	Q_OBJECT
public:
	static double dpiScale(double d)
	{
#ifdef Q_OS_UNIX
		return QX11Info::appDpiX() / (double)96 * d;
#endif
		return d;
	}

private:
	Q_DISABLE_COPY(KStyle)
};

#endif // KGLOBAL_H
