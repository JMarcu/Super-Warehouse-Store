#include "errorwindow.h"
#include "ui_errorwindow.h"

ErrorWindow::ErrorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ErrorWindow)
{
    ui->setupUi(this);
}

ErrorWindow::~ErrorWindow()
{
    delete ui;
}

void ErrorWindow::on_pushButtonOK_clicked()
{
    ui->label_Error->setText("ERROR - ID Must be 5 Digits Long");

    hide();
}
