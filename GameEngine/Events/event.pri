!EVENTS {


CONFIG += EVENTS
INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/event.h \
    $$PWD/keyboardevent.h \
    $$PWD/mouseevent.h

SOURCES += \
    $$PWD/event.cpp \
    $$PWD/keyboardevent.cpp \
    $$PWD/mouseevent.cpp
 
}
