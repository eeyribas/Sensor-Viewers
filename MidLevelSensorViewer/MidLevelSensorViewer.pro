QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    advsettingsdialog.cpp \
    infodialog.cpp \
    languagedialog.cpp \
    loadingdialog.cpp \
    main.cpp \
    maincontrol.cpp \
    mainwindow.cpp \
    scrollareaproperties.cpp \
    usersettingsdialog.cpp \
    yesnodialog.cpp

HEADERS += \
    advsettingsdialog.h \
    infodialog.h \
    languagedialog.h \
    loadingdialog.h \
    maincontrol.h \
    mainwindow.h \
    scrollareaproperties.h \
    sensordata.h \
    usersettingsdialog.h \
    yesnodialog.h

FORMS += \
    advsettingsdialog.ui \
    infodialog.ui \
    languagedialog.ui \
    loadingdialog.ui \
    mainwindow.ui \
    usersettingsdialog.ui \
    yesnodialog.ui

RESOURCES += \
    resources/resources.qrc
