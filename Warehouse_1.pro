#-------------------------------------------------
#
# Project created by QtCreator 2016-03-17T17:18:31
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Warehouse_1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    additemwindow.cpp \
    addmemberwindow.cpp \
    date.cpp \
    edititemwindow.cpp \
    editmemberwindow.cpp \
    errorwindow.cpp \
    DailySalesReport.cpp \
    Database.cpp \
    ExecutiveConversionReport.cpp \
    ExpirationReport.cpp \
    ItemReport.cpp \
    Items.cpp \
    Member.cpp \
    MemberPurchaseReport.cpp \
    RebatesReport.cpp \
    RegularConversionReport.cpp \
    Sale.cpp \
    TotalItemReport.cpp \
    TotalPurchaseReport.cpp \
    sqlite3.c \
    adddate.cpp \
    searchstring.cpp


HEADERS  += mainwindow.h \
    additemwindow.h \
    addmemberwindow.h \
    date.h \
    edititemwindow.h \
    editmemberwindow.h \
    errorwindow.h \
    DailySalesReport.h \
    Database.h \
    ExecutiveConversionReport.h \
    ExpirationReport.h \
    ItemReport.h \
    Items.h \
    Member.h \
    MemberPurchaseReport.h \
    RebatesReport.h \
    RegularConversionReport.h \
    Sale.h \
    sqlite3.h \
    TotalItemReport.h \
    TotalPurchaseReport.h \
    adddate.h \
    searchstring.h


FORMS    += mainwindow.ui \
    additemwindow.ui \
    addmemberwindow.ui \
    edititemwindow.ui \
    editmemberwindow.ui \
    errorwindow.ui \
    adddate.ui \
    searchstring.ui

DISTFILES += \
    ../../../../../Users/ashlyhernandez/Desktop/Super-Warehouse-Store-master 2/ItemClassImplements.txt \
    WarehouseDB.db3

