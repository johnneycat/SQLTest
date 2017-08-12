TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L/usr/lib/x86_64-linux-gnu -lmysqlclient -lpthread -lz -lm -lrt -latomic -ldl

SOURCES += main.c
