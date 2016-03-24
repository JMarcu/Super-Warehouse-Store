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
    case NAME_ITEM : message = "INVALID ITEM NAME - item already exists";
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
