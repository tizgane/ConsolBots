TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH = inc

HEADERS += \
    inc/Robot.h \
    inc/Device.h \
    inc/Wheels.h \
    inc/Rover.h \
    inc/Transport.h \
    inc/RobotParameters.h \
    inc/RobotOperatingParameters.h

SOURCES += \
    src/main.cpp \
    src/Robot.cpp \
    src/Device.cpp \
    src/Wheels.cpp \
    src/Rover.cpp \
    src/Transport.cpp \
    src/RobotParameters.cpp \
    src/RobotOperatingParameters.cpp




