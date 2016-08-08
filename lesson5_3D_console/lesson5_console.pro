QT += core gui widgets opengl


CONFIG += c++11

TARGET = lesson1_console
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    nehewidget.cpp

mac{
LIBS += -framework opengl -framework glut
}
HEADERS += \
    nehewidget.h
