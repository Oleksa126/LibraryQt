QT += core
QT -= gui

CONFIG += c++11

TARGET = LibraryQt
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    library.cpp

HEADERS += \
    author.h \
    book.h \
    library.h \
    reader.h \
    reading.h \
    menu.h
