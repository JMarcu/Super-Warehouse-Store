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
        ui->label->setText("Enter Member to Remove");
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

    name = ui->lineEdit->text();

    if(index1 == 0)
    {
        std::list<Item> *listI = db->GetAllItems();
        std::list<Item>::const_iterator items = listI->begin();

        while(items != listI->end() && valid == false)
        {
            if(name == items->GetItem())
            {
                valid == true;
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
        valid = false;

        std::list<Member> *list = db->GetAllMembers();
        std::list<Member>::const_iterator member = list->begin();

        while(member != list->end() && valid == false)
        {
            if(name == member->GetName())
            {
                id = member->GetID();
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
