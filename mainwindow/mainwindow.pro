QT       += core widgets quickwidgets

QMAKE_CC = ccache $$QMAKE_CC
QMAKE_CXX = ccache $$QMAKE_CXX

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../osgearth/release/ -lGCSOsgEarth
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../osgearth/debug/ -lGCSOsgEarth
else:unix: LIBS += -L$$OUT_PWD/../osgearth/ -lGCSOsgEarth

INCLUDEPATH += $$PWD/../osgearth
DEPENDPATH += $$PWD/../osgearth

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../quickwidgetproxy/release/ -lquickwidgetproxy
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../quickwidgetproxy/debug/ -lquickwidgetproxy
else:unix: LIBS += -L$$OUT_PWD/../quickwidgetproxy/ -lquickwidgetproxy

INCLUDEPATH += $$PWD/../quickwidgetproxy
DEPENDPATH += $$PWD/../quickwidgetproxy

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../svgimageprovider/release/ -lsvgimageprovider
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../svgimageprovider/debug/ -lsvgimageprovider
else:unix: LIBS += -L$$OUT_PWD/../svgimageprovider/ -lsvgimageprovider

INCLUDEPATH += $$PWD/../svgimageprovider
DEPENDPATH += $$PWD/../svgimageprovider

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../modelqmlcontext/release/ -lmodelqmlcontext
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../modelqmlcontext/debug/ -lmodelqmlcontext
else:unix: LIBS += -L$$OUT_PWD/../modelqmlcontext/ -lmodelqmlcontext

INCLUDEPATH += $$PWD/../modelqmlcontext
DEPENDPATH += $$PWD/../modelqmlcontext

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../uavobjects/release/ -luavobjects
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../uavobjects/debug/ -luavobjects
else:unix: LIBS += -L$$OUT_PWD/../uavobjects/ -luavobjects

INCLUDEPATH += $$PWD/../uavobjects
DEPENDPATH += $$PWD/../uavobjects
