QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    infodialog.cpp \
    loadingdialog.cpp \
    main.cpp \
    maincontrol.cpp \
    mainwindow.cpp \
    yesnodialog.cpp

HEADERS += \
    infodialog.h \
    loadingdialog.h \
    maincontrol.h \
    mainwindow.h \
    sensordata.h \
    yesnodialog.h

FORMS += \
    infodialog.ui \
    loadingdialog.ui \
    mainwindow.ui \
    yesnodialog.ui

RESOURCES += \
    resources/resources.qrc
