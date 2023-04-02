QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    book.cpp \
    book1.cpp \
    checkout.cpp \
    dashboardwindow.cpp \
    main.cpp \
    loginwindow.cpp \
    returns.cpp \
    user.cpp

HEADERS += \
    book.h \
    book1.h \
    checkout.h \
    dashboardwindow.h \
    loginwindow.h \
    returns.h \
    user.h

FORMS += \
    book.ui \
    book1.ui \
    checkout.ui \
    dashboardwindow.ui \
    loginwindow.ui \
    mainmenuwindow.ui \
    returns.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
