#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Database *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidgetItem->horizontalHeader()->setVisible(true);

    ui->pushButton_MemberEdit->hide();
    ui->pushButton_MemberRemove->hide();

    ui->pushButtonEdit->hide();
    ui->pushButtonRemove->hide();

    ui->tableWidget_SIDE->hide();

    rowI = 0;
    rowM = 0;

    this->db = db;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddItemToItemsTable(QString name, double price)
{
    ui->tableWidgetItem->insertRow(rowI);
    ui->tableWidgetItem->setItem(rowI,0,new QTableWidgetItem(name));
    ui->tableWidgetItem->setItem(rowI,1,new QTableWidgetItem(QString::number(price)));
    rowI++;
    ui->tableWidgetItem->resizeColumnsToContents();
}


void MainWindow::AddMemberToTable(QString name, int id, Date expiration, bool isExecutive)
{
    QString executive;
    if(isExecutive == true)
    {
        executive = "Executive";
    }
    else
    {
        executive = "Regular";
    }

    ui->tableWidgetMembers->insertRow(rowM);
    ui->tableWidgetMembers->setItem(rowM, 0, new QTableWidgetItem(name));
    ui->tableWidgetMembers->setItem(rowM, 1, new QTableWidgetItem(QString::number(id)));
    ui->tableWidgetMembers->setItem(rowM, 2, new QTableWidgetItem(expiration.toString()));
    ui->tableWidgetMembers->setItem(rowM, 3, new QTableWidgetItem(executive));
    ui->tableWidgetMembers->setItem(rowM, 4, new QTableWidgetItem(QString::number(0.0)));
    rowM++;
    ui->tableWidgetMembers->resizeColumnsToContents();
}

void MainWindow::RemoveMember(int rowRemove)
{   
    ui->tableWidgetMembers->removeRow(rowRemove);

    QString name = ui->tableWidgetMembers->item(rowRemove, 0)->text();
    int id       = ui->tableWidgetMembers->item(rowRemove,1)->text().toInt();

    Date expiration;
    expiration.UpdateDate(0,0,0);

    db->DeleteMember(Member(name, id, 0.0, expiration, false));
}

void MainWindow::AddDailySalesReport(Date dateIn)
{
    int toRemove = 0;
    while(toRemove < rowR)
    {
        ui->tableWidget_ViewReports->removeRow(toRemove);
        toRemove++;
    }

    toRemove = 0;
    while(toRemove < rowS)
    {
        ui->tableWidget_ViewReports->removeRow(toRemove);
        toRemove++;
    }

    rowR = 0;
    rowS = 0;

    const std::list<Sale> salesList = db->GetDailySalesReport(dateIn, 0)->GetDailySales();
    std::list<Sale>::const_iterator sales = salesList.begin();

    ui->tableWidget_ViewReports->horizontalHeader()->setVisible(true);

    double totalRevenue;

    totalRevenue = 0;

    ui->tableWidget_ViewReports->setHorizontalHeaderItem(0, new QTableWidgetItem("Item Name"));
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(1, new QTableWidgetItem("Quantity Sold"));


    qDebug() << "Headers Set";

    while(sales != salesList.end())
    {
        ui->tableWidget_ViewReports->insertRow(rowR);
        ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(sales->GetItemName()));
        ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem(QString::number(sales->GetQuantityPurchased())));
        totalRevenue += sales->GetSubtotal();
        sales++;
    }

    qDebug() << "Added sales to table";

    ui->tableWidget_SIDE->insertRow(rowS);
    ui->tableWidget_SIDE->setItem(rowS, 0, new QTableWidgetItem(QString::number(db->GetDailySalesReport(dateIn,0)->GetExecutiveCount())));
    ui->tableWidget_SIDE->setItem(rowS, 1, new QTableWidgetItem(QString::number(db->GetDailySalesReport(dateIn,0)->GetRegularCount())));
    ui->tableWidget_SIDE->setItem(rowS, 2, new QTableWidgetItem(totalRevenue));

}

void MainWindow::ExpiredMembershipsReport(Date dateIn)
{
    std::list<Member> membersList = db->GetExpirationReport(dateIn)->GetExpiredAccounts();

}


void MainWindow::on_pushButtonAdd_clicked()
{
    AddItemWindow *add = new AddItemWindow(db);

    connect(add, SIGNAL(ItemAdded(QString,int)),
            this, SLOT(AddItemToItemsTable(QString,int)));
    add->show();

}

void MainWindow::on_tableWidgetItem_cellClicked(int row, int column)
{

    ui->pushButtonEdit->show();
    ui->pushButtonRemove->show();
}


void MainWindow::on_pushButton_MemberAdd_clicked()
{
    AddMemberWindow *member = new AddMemberWindow(db);

    connect(member,SIGNAL(AddMember(QString, int, Date, bool)),
            this, SLOT(AddMemberToTable(QString, int, Date, bool)));

    member->show();
}

void MainWindow::on_pushButtonEdit_clicked()
{
    editItemWindow *item = new editItemWindow(db);
    connect(item, SIGNAL(ItemEdited(QString,double)),
            this, SLOT(AddItemToItemsTable(QString,double)));

    item->show();
}


void MainWindow::on_pushButton_MemberEdit_clicked()
{
    editMemberWindow *memberEdit = new editMemberWindow(db);

    connect(memberEdit, SIGNAL(MemberEdit(QString, int, Date, bool)),
            this, SLOT(AddMemberToTable(QString, int, Date, bool)));

    memberEdit->show();
}

void MainWindow::on_tableWidgetMembers_cellClicked(int row, int column)
{
    ui->pushButton_MemberEdit->show();
    ui->pushButton_MemberRemove->show();



    emit CellEditOrRemove(row);

}

void MainWindow::on_pushButton_MemberRemove_clicked()
{
    connect(this, SIGNAL(CellEditOrRemove(int)), this, SLOT(RemoveMember(int)));

    ui->pushButton_MemberEdit->hide();
    ui->pushButton_MemberRemove->hide();

}


void MainWindow::PopulateMembers()
{
    int toRemove = 0;
    while(toRemove < rowM)
    {
        ui->tableWidgetMembers->removeRow(toRemove);
        toRemove++;
    }

    rowM = 0;

     std::list<Member>* memberList = db->GetAllMembers();
    std::list<Member>::const_iterator members = memberList->begin();

    while(members != memberList->end())
    {
        AddMemberToTable(members->GetName(), members->GetID(), members->GetExpiration(), members->IsExecutive());
        members++;
    }


    delete memberList;
}

void MainWindow::PopulateItems()
{
    int toRemove = 0;
    while(toRemove < rowM)
    {
        ui->tableWidgetMembers->removeRow(toRemove);
        toRemove++;
    }

    rowM = 0;


    std::list<Item> *itemList = db->GetAllItems();
    std::list<Item>::const_iterator items = itemList->begin();

    while(items != itemList->end())
    {
        AddItemToItemsTable(items->GetItem(), items->GetPrice());
        items++;
    }

    delete itemList;
}

void MainWindow::on_ViewMembers_tabBarClicked(int index)
{
    if(index == 0)
    {

    }
    else if( index == 1)
    {
        PopulateItems();
    }
    else if(index == 2)
    {
        PopulateMembers();
    }
    else
    {

    }
}



void MainWindow::on_SalesReport_Button_clicked()
{
    AddDate *date = new AddDate();

    connect(date, SIGNAL(DateSelected(Date)),
            this, SLOT(AddDailySalesReport(Date)));
    date->show();
}



void MainWindow::on_Expire_Button_clicked()
{
    AddDate *date = new AddDate();

    connect(date, SIGNAL(DateSelected(Date)),
            this, SLOT(ExpiredMembershipsReport(Date)));
}

void MainWindow::on_Convert_Button_clicked()
{
    int toRemove = 0;
    while(toRemove < rowR)
    {
        ui->tableWidget_ViewReports->removeRow(toRemove);
        toRemove++;
    }

    ui->tableWidget_ViewReports->setHorizontalHeaderItem(0, new QTableWidgetItem("Member Name"));
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(1, new QTableWidgetItem("Current Membership type"));

    std::list<Member> list = db->GetExecutiveConversionReport()->GetMembersToConvert();

    rowR = 0;

    std::list<Member>::const_iterator members = list.begin();


    while(members != list.end())
    {
        ui->tableWidget_ViewReports->insertRow(rowR);
        ui->tableWidget_ViewReports->setItem(rowR, 0 ,new QTableWidgetItem(members->GetName()));
        ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem("Executive"));
        rowR++;
        members++;
    }

}
