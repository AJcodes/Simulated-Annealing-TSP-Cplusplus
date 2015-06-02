TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    tsp.cpp \
    citymodel.cpp \
    city.cpp \
    route.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    tsp.h \
    citymodel.h \
    city.h \
    route.h
