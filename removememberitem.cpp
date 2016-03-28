#include "removememberitem.h"
#include "ui_removememberitem.h"

RemoveMemberItem::RemoveMemberItem(Database *db, int index, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RemoveMemberItem)
{
    ui->setupUi(this);

    this->db = db;

    index1 = index;

    if(index == 0)
    {
        ui->label->setText("Enter Item to Remove");
    }
    else
    {
        ui->label->setText("Enter Member's' ID to Remove");
    }
}

RemoveMemberItem::~RemoveMemberItem()
{
    delete ui;
}

void RemoveMemberItem::on_buttonBox_accepted()
{
    int id;
    bool valid;
    Date date;

    valid = false;



    if(index1 == 0)
    {
        name = ui->lineEdit->text();

        std::list<Item> *listI = db->GetAllItems();
        std::list<Item>::const_iterator items = listI->begin();

        while(items != listI->end() && valid == false)
        {
            if(name == items->GetItem())
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
            db->DeleteItem(Item(name));
            hide();
        }

        delete listI;
    }
    else
    {
        id = ui->lineEdit->text().toInt(0,10);

        valid = false;

        std::list<Member> *list = db->GetAllMembers();
        std::list<Member>::const_iterator member = list->begin();

        while(member != list->end() && valid == false)
        {
            if(id == member->GetID())
            {
                name = member->GetName();
                valid = true;
                date.UpdateDate(0,0,0);
            }
            member++;
        }

        if(valid == false)
        {
            ErrorWindow *error = new ErrorWindow(4);
            error->show();
        }
        else
        {
            db->DeleteMember(Member(name, id, 0.0, date, false ));
            hide();
        }

        delete list;
    }
}

void RemoveMemberItem::on_buttonBox_rejected()
{
    hide();
}
