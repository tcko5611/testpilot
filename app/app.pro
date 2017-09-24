QT       += core widgets 

TARGET = testpilot
TEMPLATE = app

SOURCES += \
    main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../mainwindow/release/ -lmainwindow
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../mainwindow/debug/ -lmainwindow
else:unix: LIBS += -L$$OUT_PWD/../mainwindow/ -lmainwindow

INCLUDEPATH += $$PWD/../mainwindow
DEPENDPATH += $$PWD/../mainwindow
