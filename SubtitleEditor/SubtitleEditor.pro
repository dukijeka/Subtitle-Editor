#-------------------------------------------------
#
# Project created by QtCreator 2017-05-01T13:16:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SubtitleEditor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    mainwindow.cpp \
    Subtitles.cpp \
    MicroDVD.cpp \
    MPlayer.cpp \
    Subtitle.cpp \
    TimeStamp.cpp \
    SRT.cpp \
    SubtitleIO.cpp \
    utilities.cpp \
    traversedialog.cpp \
    globalVariables.cpp \
    toolsdialog.cpp

HEADERS  += mainwindow.h \
    globalVariables.h \
    Exceptions.h \
    MicroDVD.h \
    MPlayer.h \
    Subtitle.h \
    Subtitles.h \
    TimeStamp.h \
    SRT.h \
    SubtitleIO.h \
    utilities.h \
    traversedialog.h \
    toolsdialog.h \
    SerbianSubtitleReplacements.h

FORMS    += mainwindow.ui \
    traversedialog.ui \
    toolsdialog.ui

DISTFILES += \
    SubtitleEditor.pro.user
