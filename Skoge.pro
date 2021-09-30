TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        app.cpp \
        debug.cpp \
        event.cpp \
        main.cpp \
        object.cpp
INCLUDEPATH += D:\SFML-2.5.1\include
LIBS += D:\SFML-2.5.1\lib\libsfml-system.a \
    D:\SFML-2.5.1\lib\libsfml-window.a \
    D:\SFML-2.5.1\lib\libsfml-graphics.a \
    D:\SFML-2.5.1\lib\libsfml-audio.a \
    D:\SFML-2.5.1\lib\libsfml-network.a

HEADERS += \
    app.h \
    debug.h \
    event.h \
    manager.h \
    object.h
