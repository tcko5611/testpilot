QT       += core widgets quickwidgets

QMAKE_CC = ccache $$QMAKE_CC
QMAKE_CXX = ccache $$QMAKE_CXX

TARGET = welcomemode
TEMPLATE = lib

SOURCES += \
    welcomemode.cpp 

HEADERS += \
welcomemode.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../quickwidgetproxy/release/ -lquickwidgetproxy
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../quickwidgetproxy/debug/ -lquickwidgetproxy
else:unix: LIBS += -L$$OUT_PWD/../quickwidgetproxy/ -lquickwidgetproxy

INCLUDEPATH += $$PWD/../quickwidgetproxy
DEPENDPATH += $$PWD/../quickwidgetproxy

copydata.commands = $(COPY_DIR) $$OUT_PWD/debug/welcomemode.dll $$OUT_PWD/../app/debug
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

RESOURCES += \
    welcomemode.qrc
