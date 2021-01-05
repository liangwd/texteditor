#-------------------------------------------------
#
# Project created by QtCreator 2020-07-17T11:37:55
#
#-------------------------------------------------

QT       += core gui
QT	 += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = CTextEdit
TEMPLATE = app

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
SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qsyntaxhighligtherex.cpp \
    texteditex.cpp\
    inserttextundocommand.cpp\
    deletetextundocommand.cpp\
    third/detectcode.cpp \
    fileencodemenu.cpp \
    singletion.cpp \
    wrapeditor.cpp

HEADERS += \
    inserttextundocommand.h \
    deletetextundocommand.h\
    mainwindow.h \
    qsyntaxhighligtherex.h \
    texteditex.h\
    third/detectcode.h \
    fileencodemenu.h \
    singletion.h \
    wrapeditor.h

FORMS += \
        mainwindow.ui \
    fileencodemenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



RESOURCES += \
    res.qrc

INCLUDEPATH += $$PWD/third/lib/include
DEPENDPATH += $$PWD/third/lib/include
unix:!macx: LIBS += -L$$PWD/third/lib/lib/ -lenca
unix:!macx: LIBS += -L$$PWD/third/lib/lib/ -luchardet
unix:!macx: LIBS += -L$$PWD/third/lib/lib/ -liconv
unix:!macx: PRE_TARGETDEPS += $$PWD/third/lib/lib/libenca.a
unix:!macx: PRE_TARGETDEPS += $$PWD/third/lib/lib/libuchardet.a
unix:!macx: PRE_TARGETDEPS += $$PWD/third/lib/lib/libiconv.a
