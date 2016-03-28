#include "edititemwindow.h"
#include "ui_edititemwindow.h"
#include "errorwindow.h"

editItemWindow::editItemWindow(Database *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editItemWindow)
{
    ui->setupUi(this);
    this->db = db;
}

editItemWindow::~editItemWindow()
{
    delete ui;
}

void editItemWindow::on_buttonBox_edit_accepted()
{
    bool valid;
    valid = true;

    itemEditName = ui->itemNameLineEdit_edit->text();

    itemEditPrice = ui->itemPriceSpinBox_edit->value();

    std::list<Item> *list = db->GetAllItems();
    std::list<Item>::const_iterator items = list->begin();

    while(items != list->end() && valid != false)
    {
        qDebug() << items->GetItem();
        if(itemEditName == items->GetItem())
        {
            valid = false;
        }

        items++;
    }

    if(items == list->end() && valid == true)
    {
        ErrorWindow *error = new ErrorWindow(2);
        error->show();
    }
    else
    {
        db->UpdateItem(Item(itemEditName, itemEditPrice));

        emit ItemEdited(itemEditName, itemEditPrice);

        hide();
    }


}

void editItemWindow::on_buttonBox_edit_rejected()
{
    hide();
}

