QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 console warn_on

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/analysis.cpp \
    src/antivirus.cpp \
    src/clamui.cpp \
    src/history.cpp \
    src/network.cpp \
    src/quarantine.cpp \
    src/scan.cpp \
    src/scandirectory.cpp \
    src/schedule.cpp \
    src/settings.cpp \
    src/setup.cpp \
    src/update.cpp \
    src/updateassistant.cpp \
    src/whitelist.cpp \
    src/main.cpp

HEADERS += \
    include/analysis.h \
    include/antivirus.h \
    include/clamui.h \
    include/history.h \
    include/network.h \
    include/quarantine.h \
    include/scan.h \
    include/scandirectory.h \
    include/schedule.h \
    include/settings.h \
    include/setup.h \
    include/update.h \
    include/updateassistant.h \
    include/whitelist.h

FORMS += \
    forms/analysis.ui \
    forms/clamui.ui \
    forms/history.ui \
    forms/network.ui \
    forms/quarantine.ui \
    forms/scan.ui \
    forms/scandirectory.ui \
    forms/schedule.ui \
    forms/settings.ui \
    forms/update.ui \
    forms/updateassistant.ui \
    forms/whitelist.ui

TRANSLATIONS += \
    clamavui_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += \
    -L/usr/lib/ -lfreshclam\
    -L/usr/lib/ -lclamav

INCLUDEPATH += $$PWD/include
