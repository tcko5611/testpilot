QT       += core quickwidgets widgets qml svg

QMAKE_CC = ccache $$QMAKE_CC
QMAKE_CXX = ccache $$QMAKE_CXX

TARGET = svgimageprovider
TEMPLATE = lib

SOURCES += \
    svgimageprovider.cpp 

HEADERS += \
    svgimageprovider.h

copydata.commands = $(COPY_DIR) $$OUT_PWD/debug/svgimageprovider.dll $$OUT_PWD/../app/debug
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
# QMAKE_EXTRA_TARGETS += copydata
