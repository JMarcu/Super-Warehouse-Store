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
    /**
     * @brief AddMemberWindow
     * @param db
     * @param parent
     * - constructor for adding a member
     */
    explicit AddMemberWindow(Database *db, QWidget *parent = 0);
    ~AddMemberWindow();


signals:
    /**
     * @brief AddMember
     * - sends signal with members information to be
     *      added to database
     */
    void AddMember(QString, int, Date, bool, double);

private slots:
    /**
     * @brief on_pushButton_MemberAdd_clicked
     *  - sends signal of member to be added
     *      and closes window
     */
    void on_pushButton_MemberAdd_clicked();

    /**
     * @brief on_pushButton_MemberCancel_clicked
     *  - closes window
     */
    void on_pushButton_MemberCancel_clicked();

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
