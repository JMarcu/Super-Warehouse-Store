#ifndef ADDMEMBERWINDOW_H
#define ADDMEMBERWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QString>
#include <QDebug>
#include "mainwindow.h"
#include "date.h"
#include "Database.h"

namespace Ui {
class AddMemberWindow;
}

class AddMemberWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddMemberWindow(Database *db, QWidget *parent = 0);
    ~AddMemberWindow();


signals:
    void AddMember(QString, int, Date, bool);

private slots:
    void on_pushButton_MemberAdd_clicked();

    void on_pushButton_MemberCancel_clicked();

    void on_cb_month_currentIndexChanged(int index);

    void on_cb_year_currentIndexChanged(int index);

private:
    Ui::AddMemberWindow *ui;
    QString             name;
    int                 id;
    Date                expiration;
    double              totalSpent;
    bool                isExecutive;
    Database *db;
};

#endif // ADDMEMBERWINDOW_H
