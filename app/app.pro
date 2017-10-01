QT       += core widgets 

QMAKE_CC = ccache $$QMAKE_CC
QMAKE_CXX = ccache $$QMAKE_CXX

TARGET = testpilot
TEMPLATE = app

SOURCES += \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mainwindow/release/ -lmainwindow
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mainwindow/debug/ -lmainwindow
else:unix: LIBS += -L$$OUT_PWD/../mainwindow/ -lmainwindow

INCLUDEPATH += $$PWD/../mainwindow
DEPENDPATH += $$PWD/../mainwindow

copydata.commands = $(COPY_DIR) $$PWD/share $$OUT_PWD
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
