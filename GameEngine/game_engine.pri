!GAME_ENGINE {


CONFIG += GAME_ENGINE
INCLUDEPATH += $$PWD

include(Events/event.pri)

HEADERS += \
    $$PWD/controller.h\
    $$PWD/abstractstate.h\
    $$PWD/abstractmodel.h\
    $$PWD/camera.h



SOURCES += \
    $$PWD/controller.cpp\
    $$PWD/abstractstate.cpp\
    $$PWD/abstractmodel.cpp\
    $$PWD/camera.cpp

} 

HEADERS += \
    $$PWD/maingamewindow.h

SOURCES += \
    $$PWD/maingamewindow.cpp

