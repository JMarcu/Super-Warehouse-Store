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

/**
 * @brief The editMemberWindow class
 */
class editMemberWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief editMemberWindow
     * @param db
     * @param parent
     */
    explicit editMemberWindow(Database *db, QWidget *parent = 0);
    ~editMemberWindow();

signals:
    /**
     * @brief MemberEdit
     */
    void MemberEdit(QString, int, Date, bool, double);

private slots:

    /**
     * @brief on_editMemberConform_accepted
     */
    void on_editMemberConform_accepted();

    /**
     * @brief on_editMemberConform_rejected
     */
    void on_editMemberConform_rejected();

private:
    Ui::editMemberWindow *ui;

    QString memberName;

    QString memberType;

    int memberID;

    double totalSpent;

    Date expirationDate;

    bool isExecutive;

    Database *db;
};

#endif // EDITMEMBERWINDOW_H
