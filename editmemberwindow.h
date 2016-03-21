#ifndef EDITMEMBERWINDOW_H
#define EDITMEMBERWINDOW_H

#include <QMainWindow>
#include <QIntValidator>
#include <QString>

namespace Ui {
class editMemberWindow;
}

class editMemberWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit editMemberWindow(QWidget *parent = 0);
    ~editMemberWindow();

private slots:
    void on_RegularCheck_edit_clicked();

    void on_ExecutiveCheck_edit_clicked();

    void on_editMemberConform_accepted();

    void on_editMemberConform_rejected();

    void on_memberEditID_returnPressed();

private:
    Ui::editMemberWindow *ui;

    QString memberName;

    QString memberType;

    int memberID;

    int expMonth;

    int expDay;

    int expYear;

//    RegularMember regular;

//    ExecutiveMember executive;

//    QValidator IDValidator = new QIntValidator(00001, 99999,this);

//    QLineEdit *edit = new QLineEdit(this);

    bool isExecutive;
};

#endif // EDITMEMBERWINDOW_H
