#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T22:26:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Warehouse_Project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    adddate.cpp \
    additemwindow.cpp \
    addmemberwindow.cpp \
    DailySalesReport.cpp \
    Database.cpp \
    date.cpp \
    edititemwindow.cpp \
    editmemberwindow.cpp \
    errorwindow.cpp \
    ExecutiveConversionReport.cpp \
    ExpirationReport.cpp \
    ItemReport.cpp \
    Items.cpp \
    Member.cpp \
    MemberPurchaseReport.cpp \
    RebatesReport.cpp \
    RegularConversionReport.cpp \
    removememberitem.cpp \
    Sale.cpp \
    searchstring.cpp \
    TotalItemReport.cpp \
    TotalPurchaseReport.cpp \
    sqlite3.c
  

HEADERS  += mainwindow.h \
    adddate.h \
    additemwindow.h \
    addmemberwindow.h \
    DailySalesReport.h \
    Database.h \
    date.h \
    edititemwindow.h \
    editmemberwindow.h \
    errorwindow.h \
    ExecutiveConversionReport.h \
    ExpirationReport.h \
    ItemReport.h \
    Items.h \
    Member.h \
    MemberPurchaseReport.h \
    RebatesReport.h \
    RegularConversionReport.h \
    removememberitem.h \
    Sale.h \
    searchstring.h \
    sqlite3.h \
    TotalItemReport.h \
    TotalPurchaseReport.h



FORMS    += mainwindow.ui \
    adddate.ui \
    additemwindow.ui \
    addmemberwindow.ui \
    edititemwindow.ui \
    editmemberwindow.ui \
    errorwindow.ui \
    removememberitem.ui \
    searchstring.ui



DISTFILES += \
    WarehouseDB.db3 \
    TestOutput.txt

