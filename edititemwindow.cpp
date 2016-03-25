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

    while(items != list->end())
    {
        if(itemEditName == items->GetItem())
        {
            ErrorWindow *error = new ErrorWindow(2);
            error->show();
            valid = false;
        }

        items++;
    }

    if(valid == true)
    {

        db->AddItem(Item(itemEditName, itemEditPrice));

        emit ItemEdited(itemEditName, itemEditPrice);

        hide();

    }
}

void editItemWindow::on_buttonBox_edit_rejected()
{
    hide();
}

