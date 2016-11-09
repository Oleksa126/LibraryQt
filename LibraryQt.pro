QT += core
QT -= gui

CONFIG += c++11

TARGET = LibraryQt
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    library.cpp \
    book.cpp \
    menu.cpp \
    reader.cpp \
    reading.cpp
HEADERS += \
    author.h \
    book.h \
    library.h \
    reading.h \
    menu.h \
    reader.h
