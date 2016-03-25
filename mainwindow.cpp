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
    rowR = 0;
    colR = 0;

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

void MainWindow::RemoveMember(int rowRemove, int column)
{   
    QString name = ui->tableWidgetMembers->item(rowRemove, 0)->text();
    int id       = ui->tableWidgetMembers->item(rowRemove,1)->text().toInt();

    Date expiration;
    expiration.UpdateDate(0,0,0);

    db->DeleteMember(Member(name, id, 0.0, expiration, false));

    ui->tableWidgetMembers->removeRow(rowRemove);

    ui->pushButton_MemberEdit->hide();
    ui->pushButton_MemberRemove->hide();
}

void MainWindow::RemoveItem(int rowRemove , int column)
{
    QString itemName = ui->tableWidgetItem->item(rowRemove,0)->text();
    double  itemPrice = ui->tableWidgetMembers->item(rowRemove, 1)->text().toInt();

    db->DeleteItem(Item(itemName, itemPrice));

    ui->tableWidgetItem->removeRow(rowRemove);

    ui->pushButtonEdit->hide();
    ui->pushButtonRemove->hide();
}


void MainWindow::AddDailySalesReport(Date dateIn)
{

    ClearTable(ui->tableWidget_ViewReports);

    const std::list<Sale> salesList = db->GetDailySalesReport(dateIn, 0)->GetDailySales();
    std::list<Sale>::const_iterator sales = salesList.begin();

    ui->tableWidget_ViewReports->horizontalHeader()->setVisible(true);

    double totalRevenue;

    totalRevenue = 0;

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(0, new QTableWidgetItem("Item Name"));
    colR++;

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(1, new QTableWidgetItem("Quantity Sold"));
    colR++;

        ui->tableWidget_ViewReports->resizeColumnsToContents();

    while(sales != salesList.end())
    {
        ui->tableWidget_ViewReports->insertRow(rowR);
        ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(sales->GetItemName()));
        ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem(QString::number(sales->GetQuantityPurchased())));
        totalRevenue += sales->GetSubtotal();
        sales++;
    }
    ui->tableWidget_SIDE->insertRow(rowS);
    ui->tableWidget_SIDE->setItem(rowS, 0, new QTableWidgetItem(QString::number(db->GetDailySalesReport(dateIn,0)->GetExecutiveCount())));
    ui->tableWidget_SIDE->setItem(rowS, 1, new QTableWidgetItem(QString::number(db->GetDailySalesReport(dateIn,0)->GetRegularCount())));
    ui->tableWidget_SIDE->setItem(rowS, 2, new QTableWidgetItem(totalRevenue));

}


/****************
 * FINISH
 *******************/
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

    connect(this, SIGNAL(on_tableWidgetItem_cellClicked( int, int)), this, SLOT(RemoveItem(int, int)));

    item->show();
}


void MainWindow::on_pushButton_MemberEdit_clicked()
{
    editMemberWindow *memberEdit = new editMemberWindow(db);

    connect(memberEdit, SIGNAL(MemberEdit(QString, int, Date, bool)),
            this, SLOT(AddMemberToTable(QString, int, Date, bool)));
    connect(this, SIGNAL(on_tableWidgetMembers_cellClicked(int row, int column)),
            this, SLOT(RemoveMember(int)));

    memberEdit->show();
}

void MainWindow::on_tableWidgetMembers_cellClicked(int row, int column)
{
    ui->pushButton_MemberEdit->show();
    ui->pushButton_MemberRemove->show();

}

void MainWindow::on_pushButton_MemberRemove_clicked()
{
    connect(this, SIGNAL(on_tableWidgetMembers_cellClicked(int, int)),
            this, SLOT(RemoveMember(int, int)));
}


void MainWindow::PopulateMembers()
{

    int currentRows = ui->tableWidgetMembers->rowCount();

    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        ui->tableWidgetMembers->removeRow(0);
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
    int currentRows = ui->tableWidgetItem->rowCount();

    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        ui->tableWidgetItem->removeRow(0);
    }

    rowI = 0;

    std::list<Item> *itemList = db->GetAllItems();
    std::list<Item>::const_iterator items = itemList->begin();

    while(items != itemList->end())
    {
        AddItemToItemsTable(items->GetItem(), items->GetPrice());
        items++;
    }

    delete itemList;
}

void MainWindow::AddSearchedItem(QString name)
{
    ClearTable(ui->tableWidget_ViewReports);

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Item Name"));

    colR++;

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Quantity Sold"));

    colR++;

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Total Revenue"));

    ui->tableWidget_ViewReports->resizeColumnsToContents();


    ui->tableWidget_ViewReports->insertRow(rowR);
    ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(db->GetItemReport(Item(name))->GetItem().GetItem()));
    ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem(QString::number(db->GetItemReport(Item(name))->GetQuantitySold())));
    ui->tableWidget_ViewReports->setItem(rowR, 2, new QTableWidgetItem(QString::number(db->GetItemReport(Item(name))->GetTotalRevenue())));

    ui->tableWidget_ViewReports->resizeRowsToContents();

}

void MainWindow::ClearTable(QTableWidget *table)
{
    int currentRows = table->rowCount();
    int currentCol =  table->columnCount();

    for(int rowRemove = 0; rowRemove < currentRows; rowRemove++)
    {
        table->removeRow(0);
    }

    for(int colRemove = 0; colRemove < currentCol; colRemove++)
    {
        table->removeColumn(0);
    }

    rowR = 0;
    colR = 0;
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


/************
 * FIX
 *************/
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
        date->show();
}

void MainWindow::on_Convert_Button_clicked()
{   
    ClearTable(ui->tableWidget_ViewReports);

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Member Name"));

    colR++;
    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Current Membership type"));


    std::list<Member> list = db->GetExecutiveConversionReport()->GetMembersToConvert();
    std::list<Member>::const_iterator members = list.begin();

    rowR = -1;

    while(members != list.end())
    {
        rowR++;
        ui->tableWidget_ViewReports->insertRow(rowR);
        ui->tableWidget_ViewReports->setItem(rowR, 0 ,new QTableWidgetItem(members->GetName()));
        ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem("Executive"));

        members++;
    }


}

void MainWindow::on_TotalPurchases_Button_clicked()
{
    ClearTable(ui->tableWidget_ViewReports);
    int index = 0;

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Member ID"));

    colR++;
    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Item"));

    colR++;
    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Quantity"));

    rowR = 0;

    std::list<Sale> saleList = db->GetTotalPurchaseReport()->GetPurchases(index);

    while(index < db->GetTotalPurchaseReport()->GetMaxIndex())
    {
        std::list<Sale> saleList = db->GetTotalPurchaseReport()->GetPurchases(index);
        std::list<Sale>::const_iterator sales = saleList.begin();

        ui->tableWidget_ViewReports->insertRow(rowR);
        ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(QString::number(sales->GetMemberID())));

        while(sales != saleList.end())
        {
            ui->tableWidget_ViewReports->insertRow(rowR);
            ui->tableWidget_ViewReports->setItem(rowR, 1,
                new QTableWidgetItem(sales->GetItemName()));
            ui->tableWidget_ViewReports->setItem(rowR, 2, new QTableWidgetItem(QString::number(sales->GetQuantityPurchased())));
            rowR++;
            sales++;
        }

        index++;
    }

}



void MainWindow::on_ItemsSoldQuantity_Button_clicked()
{
    ClearTable(ui->tableWidget_ViewReports);
    int index = 0;

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Item Name"));

    colR++;

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Quantity Sold"));

    colR++;

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Total Revenue"));

    colR++;

    ui->tableWidget_ViewReports->horizontalHeader()->setVisible(true);

    while(index < db->GetTotalItemReport()->ItemCount())
    {
        ui->tableWidget_ViewReports->insertRow(rowR);
        ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(db->GetTotalItemReport()->GetItem(index).GetItem()));
        ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem(QString::number(db->GetTotalItemReport()->GetQuantitySold(index))));
        ui->tableWidget_ViewReports->setItem(rowR, 2, new QTableWidgetItem(QString::number(db->GetTotalItemReport()->GetRevenue(index))));
        index++;
        rowR++;
    }
}



void MainWindow::on_Rebates_Button_clicked()
{
    ClearTable(ui->tableWidget_ViewReports);

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("MemberShip Number"));

    colR++;

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Rebate Ammount"));

    std::list<Member> list = db->GetRebatesReport()->GetExecutiveMembers();
    std::list<Member>::const_iterator members = list.begin();

    while(members != list.end())
    {
        ui->tableWidget_ViewReports->insertRow(rowR);
        ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(QString::number(members->GetID())));
        ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem(QString::number(members->GetRebate())));
        rowR++;
        members++;
    }

}




void MainWindow::on_ItemsSoldName_Button_clicked()
{
    SearchString *search = new SearchString(db);

    connect(search, SIGNAL(SearchItem(QString)),
            this, SLOT(AddSearchedItem(QString)));
    search->show();
}


/************
 * FINISH
 *************/
void MainWindow::on_MemberPurchases_Button_clicked()
{

}
