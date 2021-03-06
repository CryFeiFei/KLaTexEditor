#-------------------------------------------------
#
# Project created by QtCreator 2019-03-13T22:51:36
#
#-------------------------------------------------

QT       += core gui

QT += webenginewidgets
#x11 support
unix:QT += x11extras

#QT += svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KLaTexEditor
TEMPLATE = app
win32:RC_ICONS = KLatexEditor.ico

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

#qt4
#QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
        main.cpp \
    kmainwidget.cpp \
    ktitlewidget.cpp \
    ksubmainwidget.cpp \
    krbtoolbar/krbtabbar.cpp \
    krbtoolbar/krbtoolbar.cpp \
    krbtoolbar/krbbuttongroup.cpp \
    krbtoolbar/krbtoolbutton.cpp \
    krbtoolbar/krbtabwidget.cpp \
    kwebtoolwidget.cpp \
    kcore/kwebformulastring.cpp \
    kformulatextedit.cpp \
    kcolorlabel.cpp \
    kcombobox.cpp \
    kpushbutton.cpp \
    kcore/kformulawidget.cpp \
    kcore/kformulatitlewidget.cpp

HEADERS += \
    kmainwidget.h \
    ktitlewidget.h \
    ksubmainwidget.h \
    krbtoolbar/krbtabbar.h \
    krbtoolbar/krbtoolbar.h \
    kglobal.h \
    krbtoolbar/krbbuttongroup.h \
    krbtoolbar/krbtoolbutton.h \
    krbtoolbar/krbtabwidget.h \
    kwebtoolwidget.h \
    kcore/kwebformulastring.h \
    kformulatextedit.h \
    kcolorlabel.h \
    kcombobox.h \
    kpushbutton.h \
    kcore/kformulawidget.h \
    kcore/kformulatitlewidget.h

FORMS += \
    ktitlewidget.ui \
    ksubmainwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    klatexwebsource.qrc \
#    image.qrc
