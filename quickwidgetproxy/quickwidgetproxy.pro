QT       += core quickwidgets widgets qml

TARGET = quickwidgetproxy
TEMPLATE = lib

SOURCES += \
    quickwidgetproxy.cpp 

HEADERS += \
    quickwidgetproxy.h

copydata.commands = $(COPY_DIR) $$OUT_PWD/debug/quickwidgetproxy.dll $$OUT_PWD/../app/debug
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
