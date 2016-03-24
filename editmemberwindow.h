#ifndef EDITMEMBERWINDOW_H
#define EDITMEMBERWINDOW_H

#include <QMainWindow>
#include <QIntValidator>
#include <QString>
#include "date.h"
#include "Database.h"

namespace Ui {
class editMemberWindow;
}

class editMemberWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit editMemberWindow(Database *db, QWidget *parent = 0);
    ~editMemberWindow();

signals:
    void MemberEdit(QString, int, Date, bool);

private slots:

    void on_editMemberConform_accepted();

    void on_editMemberConform_rejected();

private:
    Ui::editMemberWindow *ui;

    QString memberName;

    QString memberType;

    int memberID;

    Date expirationDate;

    bool isExecutive;

    Database *db;
};

#endif // EDITMEMBERWINDOW_H
