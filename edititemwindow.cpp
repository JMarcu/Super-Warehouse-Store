#include "edititemwindow.h"
#include "ui_edititemwindow.h"

editItemWindow::editItemWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editItemWindow)
{
    ui->setupUi(this);

//    prevItem.SetItemProfile(db->GetInventory()->GetItem(),
//                            db->GetInventory()->GetAmount(),
//                            db->GetInventory()->GetPrice());

//    ui->itemNameLineEdit_edit->setText(db->GetInventory()->GetItem());

//    ui->itemAmountSpinBox_edit->setValue(db->GetInventory()->GetItem());

//    ui->itemPriceSpinBox_edit->setValue(db->GetInventory()->GetItem());

    // change GetInventory soon!!!
}

editItemWindow::~editItemWindow()
{
    delete ui;
}

void editItemWindow::on_buttonBox_edit_accepted()
{
    itemEditName = ui->itemNameLineEdit_edit->text();

    itemEditAmount = ui->itemAmountSpinBox_edit->value();

    itemEditPrice = ui->itemPriceSpinBox_edit->value();

//    db->DeleteItem(prevItem.GetItem(), prevItem.GetAmount(), prevItem.GetPrice());

//    db->AddItem(prevItem.GetItem(), prevItem.GetAmount(), prevItem.GetPrice());

    hide();

}

void editItemWindow::on_buttonBox_edit_rejected()
{
    hide();
}
