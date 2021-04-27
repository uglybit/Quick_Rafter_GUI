QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/commonrafter.cpp \
    Sources/dimensions.cpp \
    Sources/dimensionslength.cpp \
    Sources/element.cpp \
    Sources/gableroof.cpp \
    Sources/hippedroof.cpp \
    Sources/hiprafter.cpp \
    Sources/main.cpp \
    Sources/mainwindow.cpp \
    Sources/purlin.cpp \
    Sources/purlinprop.cpp \
    Sources/result.cpp \
    Sources/resultcommonrafter.cpp \
    Sources/resultgableroof.cpp \
    Sources/resulthippedroof.cpp \
    Sources/resulthiprafter.cpp \
    Sources/resultinterface.cpp \
    Sources/resultpurlin.cpp \
    Sources/resultpurlinprop.cpp \
    Sources/resulttruss.cpp \
    Sources/resultwallplate.cpp \
    Sources/truss.cpp \
    Sources/wallplate.cpp \

HEADERS += \
    Headers/commonrafter.h \
    Headers/dimensions.h \
    Headers/dimensionslength.h \
    Headers/element.h \
    Headers/gableroof.h \
    Headers/hippedroof.h \
    Headers/hiprafter.h \
    Headers/mainwindow.h \
    Headers/purlin.h \
    Headers/purlinprop.h \
    Headers/result.h \
    Headers/resultcommonrafter.h \
    Headers/resultgableroof.h \
    Headers/resulthippedroof.h \
    Headers/resulthiprafter.h \
    Headers/resultinterface.h \
    Headers/resultpurlin.h \
    Headers/resultpurlinprop.h \
    Headers/resulttruss.h \
    Headers/resultwallplate.h \
    Headers/truss.h \
    Headers/wallplate.h \

FORMS += \
    Forms/commonrafter.ui \
    Forms/dimensions.ui \
    Forms/dimensionslength.ui \
    Forms/hiprafter.ui \
    Forms/mainwindow.ui \
    Forms/purlin.ui \
    Forms/purlinprop.ui \
    Forms/result.ui \
    Forms/resultcommonrafter.ui \
    Forms/resulthiprafter.ui \
    Forms/resultinterface.ui \
    Forms/resultpurlin.ui \
    Forms/resultpurlinprop.ui \
    Forms/resulttruss.ui \
    Forms/resultwallplate.ui \
    Forms/wallplate.ui \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    pallets/Result_labels.xml
