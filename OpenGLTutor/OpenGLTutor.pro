QT += gui opengl

CONFIG += c++11 console
CONFIG -= app_bundle

include(../GameEngine/game_engine.pri)
include(SimpleState/simple_state.pri)
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cubemodel.cpp \
        main.cpp \
        texturecube.cpp \
        utilsopengl.cpp

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += glfw3
unix: PKGCONFIG += gl
unix: PKGCONFIG += glew
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    cubemodel.h \
    texturecube.h \
    utilsopengl.h

DISTFILES += \
    ../shader/SimpleFragmentShader.fragmentshader \
    ../shader/SimpleVertexShader.vertexshader \
    ../shader/fragment.fragmentshader \
    ../shader/vertex.vertexshader \

