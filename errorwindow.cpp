#include "errorwindow.h"
#include "ui_errorwindow.h"

ErrorWindow::ErrorWindow(int index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorWindow)
{
    ui->setupUi(this);

    switch(index)
    {
        case NAME_MEM : message = "INVALID MEMBER NAME";
            break;
        case ID : message = "INVALID ID - ID already exists";
            break;
        case NAME_ITEM : message = "INVALID ITEM NAME - Item already exists";
            break;
        case ITEM_NF : message = "ITEM NOT FOUND - Try again or press cancel";
            break;
        case MEM_NF : message = "MEMBER NOT FOUND - Try again or press cancel";
            break;
        case DATE : message = "NO SALES FOUND FOR DATE ENTERED";
            break;
        case MEM_SALE : message = "MEMBER HAS NOT MADE ANY PURCHASES";
            break;
        case EXP : message = "NO MEMBERSHIPS EXPIRE THIS MONTH";
            break;

    }

    ui->label_Error->setText(message);
}

ErrorWindow::~ErrorWindow()
{
    delete ui;
}

void ErrorWindow::on_pushButtonOK_clicked()
{
    hide();
}
