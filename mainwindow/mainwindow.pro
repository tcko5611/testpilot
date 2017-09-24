QT       += core widgets 

TARGET = mainwindow
TEMPLATE = lib

SOURCES += \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../connectionmanager/release/ -lconnectionmanager
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../connectionmanager/debug/ -lconnectionmanager
else:unix: LIBS += -L$$OUT_PWD/../connectionmanager/ -lconnectionmanager

INCLUDEPATH += $$PWD/../connectionmanager
DEPENDPATH += $$PWD/../connectionmanager

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../welcomemode/release/ -lwelcomemode
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../welcomemode/debug/ -lwelcomemode
else:unix: LIBS += -L$$OUT_PWD/../welcomemode/ -lwelcomemode

INCLUDEPATH += $$PWD/../welcomemode
DEPENDPATH += $$PWD/../welcomemode

copydata.commands = $(COPY_DIR) $$OUT_PWD/debug/mainwindow.dll $$OUT_PWD/../app/debug
first.depends = $(first) copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata

RESOURCES += \
    mainwindow.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../pfdqmlmode/release/ -lpfdqmlmode
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../pfdqmlmode/debug/ -lpfdqmlmode
else:unix: LIBS += -L$$OUT_PWD/../pfdqmlmode/ -lpfdqmlmode

INCLUDEPATH += $$PWD/../pfdqmlmode
DEPENDPATH += $$PWD/../pfdqmlmode

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../osgearth/release/ -lGCSOsgEarth
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../osgearth/debug/ -lGCSOsgEarth
else:unix: LIBS += -L$$OUT_PWD/../osgearth/ -lGCSOsgEarth

INCLUDEPATH += $$PWD/../osgearth
DEPENDPATH += $$PWD/../osgearth
