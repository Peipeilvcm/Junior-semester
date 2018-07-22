#-------------------------------------------------
#
# Project created by QtCreator 2017-12-08T22:28:56
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OnlineStore
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    registerdialog.cpp \
    managedialog.cpp \
    product.cpp \
    book.cpp \
    cloth.cpp \
    food.cpp \
    phone.cpp \
    addgoodsdialog.cpp \
    modifyuserinfodialog.cpp \
    addtocartdialog.cpp \
    modifyquantitydialog.cpp \
    accountmanagedialog.cpp \
    paydialog.cpp \
    globalinfo.cpp \
    productfactory.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    registerdialog.h \
    managedialog.h \
    product.h \
    book.h \
    cloth.h \
    food.h \
    phone.h \
    addgoodsdialog.h \
    modifyuserinfodialog.h \
    addtocartdialog.h \
    modifyquantitydialog.h \
    accountmanagedialog.h \
    paydialog.h \
    globalinfo.h \
    productfactory.h \
    observer.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    registerdialog.ui \
    managedialog.ui \
    addgoodsdialog.ui \
    modifyuserinfodialog.ui \
    addtocartdialog.ui \
    modifyquantitydialog.ui \
    accountmanagedialog.ui \
    paydialog.ui

RESOURCES += \
    icon.qrc
