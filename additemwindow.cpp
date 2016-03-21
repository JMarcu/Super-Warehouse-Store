#include "additemwindow.h"
#include "ui_additemwindow.h"

AddItemWindow::AddItemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddItemWindow)
{
    ui->setupUi(this);
}

AddItemWindow::~AddItemWindow()
{
    delete ui;
}

void AddItemWindow::on_pushButton_AddItem_clicked()
{
    itemName = ui->NameEdit->text();

    itemAmount = ui->AmountEdit->value();

    itemPrice = ui->PriceEdit->value();

    emit ItemAdded(itemName, itemAmount, itemPrice);



    hide();
}

void AddItemWindow::on_pushButton_ItemCancel_clicked()
{
    hide();
}
