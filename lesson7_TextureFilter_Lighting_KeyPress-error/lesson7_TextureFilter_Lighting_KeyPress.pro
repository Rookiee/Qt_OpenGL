#QT += core
#QT -= gui

QT += core gui widgets opengl

CONFIG += c++11

TARGET = lesson7_TextureFilter_Lighting_KeyPress
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
