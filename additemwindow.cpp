#include "additemwindow.h"
#include "ui_additemwindow.h"


/**
 * @brief AddItemWindow::AddItemWindow
 * @param db
 * @param parent
 */
AddItemWindow::AddItemWindow(Database *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddItemWindow)
{
    ui->setupUi(this);
    this->db = db;
}

/**
 * @brief AddItemWindow::~AddItemWindow
 */
AddItemWindow::~AddItemWindow()
{
    delete ui;
}

/**
 * @brief AddItemWindow::on_pushButton_AddItem_clicked
 */
void AddItemWindow::on_pushButton_AddItem_clicked()
{
    bool valid;
    valid = true;

    itemName = ui->NameEdit->text();

    itemPrice = ui->PriceEdit->value();

    std::list<Item> *list = db->GetAllItems();
    std::list<Item>::const_iterator items = list->begin();

    while(items != list->end())
    {
        if(itemName == items->GetItem())
        {
            ErrorWindow *error = new ErrorWindow(2);
            error->show();
            valid = false;
        }

        items++;
    }

    if(valid == true)
    {

        db->AddItem(Item(itemName, itemPrice));

        emit ItemAdded(itemName, itemPrice);

        hide();
    }
}

/**
 * @brief AddItemWindow::on_pushButton_ItemCancel_clicked
 */
void AddItemWindow::on_pushButton_ItemCancel_clicked()
{
    hide();
}
