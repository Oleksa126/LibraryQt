QT += core
QT -= gui

CONFIG += c++11

TARGET = Library
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    book.cpp \
    reader.cpp \
    librarian.cpp

HEADERS += \
    author.h \
    book.h \
    reader.h \
    librarian.h
