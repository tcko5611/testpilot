QT       += core quickwidgets widgets qml

QMAKE_CC = ccache $$QMAKE_CC
QMAKE_CXX = ccache $$QMAKE_CXX

TARGET = uavobjects
TEMPLATE = lib

SOURCES += \
    attitudestate.cpp 

HEADERS += \
    attitudestate.h

copydata.commands = $(COPY_DIR) $$OUT_PWD/debug/uavobjects.dll $$OUT_PWD/../app/debug
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

