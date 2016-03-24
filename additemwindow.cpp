#include "additemwindow.h"
#include "ui_additemwindow.h"

AddItemWindow::AddItemWindow(Database *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddItemWindow)
{
    ui->setupUi(this);
    this->db = db;
}

AddItemWindow::~AddItemWindow()
{
    delete ui;
}

void AddItemWindow::on_pushButton_AddItem_clicked()
{
    itemName = ui->NameEdit->text();

    itemPrice = ui->PriceEdit->value();

    db->AddItem(Item(itemName, itemPrice));

    emit ItemAdded(itemName, itemPrice);



    hide();
}

void AddItemWindow::on_pushButton_ItemCancel_clicked()
{
    hide();
}
