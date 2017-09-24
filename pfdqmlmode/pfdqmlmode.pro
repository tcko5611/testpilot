QT       += core widgets quickwidgets

TARGET = pfdqmlmode
TEMPLATE = lib

SOURCES += \
    pfdqmlmode.cpp \ 
    pfdqmlcontext.cpp

HEADERS += \
pfdqmlmode.h \
    pfdqmlcontext.h

RESOURCES += \
   pfdqmlmode.qrc

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

copydata.commands = $(COPY_DIR) $$OUT_PWD/debug/pfdqmlmode.dll $$OUT_PWD/../app/debug
copydata2.commands = $(COPY_DIR) $$PWD/qml $$OUT_PWD/../share
copydata3.commands = $(COPY_DIR) $$PWD/models $$OUT_PWD/../share
copydata4.commands = $(COPY_DIR) $$PWD/backgrounds $$OUT_PWD/../share
first.depends = $(first) copydata copydata2 copydata3 copydata4
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata copydata2 copydata3 copydata4
