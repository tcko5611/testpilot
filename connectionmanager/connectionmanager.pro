QT       += core widgets 

TARGET = connectionmanager
TEMPLATE = lib

SOURCES += \
    connectionmanager.cpp 

HEADERS += \
    connectionmanager.h

INCLUDEPATH += $$PWD/../mainwindow
DEPENDPATH += $$PWD/../mainwindow

copydata.commands = $(COPY_DIR) $$OUT_PWD/debug/connectionmanager.dll $$OUT_PWD/../app/debug
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
