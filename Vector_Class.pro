QT += core
QT -= gui

CONFIG += c++11

TARGET = Array_Class
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    vector_class.h \
    vector_class_impl.h \
    iterator.h
