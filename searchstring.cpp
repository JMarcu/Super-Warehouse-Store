#include "searchstring.h"
#include "ui_searchstring.h"
#include "errorwindow.h"

SearchString::SearchString(Database *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchString)
{
    ui->setupUi(this);
    this->db = db;
}

SearchString::~SearchString()
{
    delete ui;
}


void SearchString::on_buttonBox_accepted()
{
    bool valid;

    valid = false;

    itemName = ui->lineEdit->text();

    std::list<Item> *list = db->GetAllItems();
    std::list<Item>::const_iterator items = list->begin();

    while(items != list->end() && valid != true)
    {
        if(itemName == items->GetItem())
        {
            valid = true;
        }

        items++;
    }

    if(valid == false)
    {
        ErrorWindow *error = new ErrorWindow(3);
        error->show();
    }
    else
    {
        emit SearchItem(itemName);
        hide();
    }

    delete list;

}

void SearchString::on_buttonBox_rejected()
{
    hide();
}
