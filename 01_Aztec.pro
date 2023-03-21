QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += ../shared

SOURCES += \
    ../shared/qstd.cpp \
    main.cpp \
    mainwindow.cpp \
    moncanvas.cpp \
    piece.cpp \
    plateau.cpp \
    possibilites.cpp

HEADERS += \
    ../shared/qstd.h \
    mainwindow.h \
    moncanvas.h \
    piece.h \
    plateau.h \
    possibilites.h

FORMS += \
    mainwindow.ui \
    possibilites.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
