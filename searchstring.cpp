#include "searchstring.h"
#include "ui_searchstring.h"
#include "errorwindow.h"

SearchString::SearchString(int index, Database *db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchString)
{
    ui->setupUi(this);
    this->db = db;

    this->index = index;

    if(index == 0)
    {
        ui->label->setText("Enter a item to Search");
        ui->pushButton_ID->hide();
        ui->pushButton_Name->hide();
    }
    else
    {
        ui->buttonBox->hide();
        ui->lineEdit->hide();
        ui->label->setText("Search by Name or ID?");
    }
}

SearchString::~SearchString()
{
    delete ui;
}


void SearchString::on_buttonBox_accepted()
{
    bool valid;

    valid = false;

    if(index == 0)
    {
        ui->lineEdit->show();
        search = ui->lineEdit->text();

        std::list<Item> *list = db->GetAllItems();
        std::list<Item>::const_iterator items = list->begin();

        while(items != list->end() && valid != true)
        {
            if(search == items->GetItem())
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
            emit SearchItem(search);
            hide();
        }

        delete list;
    }
    else
    {
        if(clicked == 2)
        {
            search = ui->lineEdit->text();
            emit SearchName(search);
        }
        else
        {
            search = ui->lineEdit->text();
            emit SearchInt(search.toInt(0, 10));
        }


        hide();
    }

}

void SearchString::on_buttonBox_rejected()
{
    hide();
}

void SearchString::on_pushButton_Name_clicked()
{
    ui->pushButton_ID->hide();
    ui->pushButton_Name->hide();
    ui->buttonBox->show();
    ui->lineEdit->show();
    ui->label->setText("Enter a Member Name");
    clicked = 2;
}

void SearchString::on_pushButton_ID_clicked()
{
    ui->pushButton_ID->hide();
    ui->pushButton_Name->hide();
    ui->buttonBox->show();
    ui->lineEdit->show();
    ui->label->setText("Enter a Member ID");
    clicked = 3;
}
