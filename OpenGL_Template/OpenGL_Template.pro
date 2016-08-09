#-------------------------------------------------
#
# Project created by QtCreator 2016-08-08T21:46:37
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenGL_Template
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    view.cpp \
    help.cpp

HEADERS  += mainwindow.h \
    view.h \
    help.h

FORMS    += mainwindow.ui \
    help.ui

mac{
    LIBS += -framework opengl -framework glut
}

