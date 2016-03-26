#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Database *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidgetItem->horizontalHeader()->setVisible(true);

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


void MainWindow::AddDailySalesReport(Date dateIn)
{
    ui->tableWidget_SIDE->hide();
    ClearTable(ui->tableWidget_ViewReports);

    const std::list<Sale> salesList = db->GetDailySalesReport(dateIn, 0)->GetDailySales();
    std::list<Sale>::const_iterator sales = salesList.begin();

    if(salesList.size() == 0 )
    {
        ErrorWindow *error = new ErrorWindow(5);
        error->show();
    }
    else
    {
        ui->tableWidget_ViewReports->horizontalHeader()->setVisible(true);

        double totalRevenue;

        totalRevenue = 0;

        ui->tableWidget_ViewReports->insertColumn(colR);
        ui->tableWidget_ViewReports->setHorizontalHeaderItem(0, new QTableWidgetItem("Item Name"));
        colR++;

        ui->tableWidget_ViewReports->insertColumn(colR);
        ui->tableWidget_ViewReports->setHorizontalHeaderItem(1, new QTableWidgetItem("Quantity Sold"));
        colR++;
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

    ui->tableWidget_ViewReports->resizeColumnsToContents();

}


void MainWindow::ExpiredMembershipsReport(Date dateIn)
{
    ui->tableWidget_SIDE->hide();
    ClearTable(ui->tableWidget_ViewReports);

    std::list<Member> membersList = db->GetExpirationReport(dateIn)->GetExpiredAccounts();
    std::list<Member>::const_iterator members = membersList.begin();

    if(membersList.size() == 0)
    {
        ErrorWindow *error = new ErrorWindow(7);
        error->show();
    }
    else
    {
        ui->tableWidget_ViewReports->insertColumn(colR);
        ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Member Name"));
        colR++;

        ui->tableWidget_ViewReports->insertColumn(colR);
        ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Renewal Ammount"));
        colR++;

        while(members != membersList.end())
        {
            ui->tableWidget_ViewReports->insertRow(rowR);
            ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(members->GetName()));
            ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem(QString::number(members->GetRenewalAmount())));
            rowR++;
            members++;
        }

        ui->tableWidget_ViewReports->resizeColumnsToContents();
    }
}


void MainWindow::on_pushButtonAdd_clicked()
{
    AddItemWindow *add = new AddItemWindow(db);

    connect(add, SIGNAL(ItemAdded(QString,int)),
            this, SLOT(AddItemToItemsTable(QString,int)));
    add->show();

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
    connect(item, SIGNAL(ItemEdited(QString,double)), this, SLOT(PopulateItems()));
    item->show();
    PopulateItems();
}


void MainWindow::on_pushButton_MemberEdit_clicked()
{
    editMemberWindow *memberEdit = new editMemberWindow(db);

    connect(memberEdit, SIGNAL(MemberEdit(QString, int, Date, bool)),
            this, SLOT(AddMemberToTable(QString, int, Date, bool)));

    memberEdit->show();
    PopulateMembers();
}


void MainWindow::on_pushButton_MemberRemove_clicked()
{
    RemoveMemberItem *toRemove = new RemoveMemberItem(db, 1);
    toRemove->show();
    PopulateMembers();
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
    ui->tableWidget_SIDE->hide();
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

    ui->tableWidget_ViewReports->resizeColumnsToContents();

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

void MainWindow::AddMemberPurchaseString(QString name)
{
    ui->tableWidget_SIDE->hide();
    ClearTable(ui->tableWidget_ViewReports);


    std::list<Sale> list = db->GetMemberPurchaseReport(name)->GetSales();
    std::list<Sale>::const_iterator sales = list.begin();

    if(list.size() == 0)
    {
        ErrorWindow *error = new ErrorWindow(6);
        error->show();
    }
    else
    {
        ui->tableWidget_ViewReports->insertColumn(colR);
        ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Item Name"));
        colR++;

        ui->tableWidget_ViewReports->insertColumn(colR);
        ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Quantity Purchased"));
        colR++;


        while(sales != list.end())
        {
            ui->tableWidget_ViewReports->insertRow(rowR);
            ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(sales->GetItemName()));
            ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem(QString::number(sales->GetQuantityPurchased())));
            rowR++;
            sales++;
        }
    }

    ui->tableWidget_ViewReports->resizeColumnsToContents();
}

void MainWindow::AddMemberPurchaseInt(int id)
{
    ui->tableWidget_SIDE->hide();
    ClearTable(ui->tableWidget_ViewReports);

    std::list<Sale> list = db->GetMemberPurchaseReport(id)->GetSales();
    std::list<Sale>::const_iterator sales = list.begin();

    if(list.size() == 0)
    {
        ErrorWindow *error = new ErrorWindow(6);
        error->show();
    }
    else
    {
        ui->tableWidget_ViewReports->insertColumn(colR);
        ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Item Name"));
        colR++;

        ui->tableWidget_ViewReports->insertColumn(colR);
        ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Quantity Purchased"));
        colR++;


        while(sales != list.end())
        {
            ui->tableWidget_ViewReports->insertRow(rowR);
            ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(sales->GetItemName()));
            ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem(QString::number(sales->GetQuantityPurchased())));
            rowR++;
            sales++;
        }
    }

    ui->tableWidget_ViewReports->resizeColumnsToContents();
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
    AddDate *date = new AddDate(0);

    connect(date, SIGNAL(DateSelected(Date)),
            this, SLOT(AddDailySalesReport(Date)));
    date->show();
}



void MainWindow::on_Expire_Button_clicked()
{
    AddDate *date = new AddDate(1);

    connect(date, SIGNAL(DateSelected(Date)),
            this, SLOT(ExpiredMembershipsReport(Date)));

        date->show();

}

void MainWindow::on_Convert_Button_clicked()
{   ui->tableWidget_SIDE->hide();
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

    ui->tableWidget_ViewReports->resizeColumnsToContents();
}

void MainWindow::on_TotalPurchases_Button_clicked()
{

    ClearTable(ui->tableWidget_ViewReports);
    ClearTable(ui->tableWidget_SIDE);
    ui->tableWidget_SIDE->show();

    int index = 0;
    vector<double> totals;

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Member ID"));

    colR++;
    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Item"));

    colR++;
    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Quantity"));


    ui->tableWidget_SIDE->insertColumn(0);
    ui->tableWidget_SIDE->setHorizontalHeaderItem(0, new QTableWidgetItem("Member ID"));
    ui->tableWidget_SIDE->insertColumn(1);
    ui->tableWidget_SIDE->setHorizontalHeaderItem(1, new QTableWidgetItem("Total Spent"));

    rowR = 0;


    while(index < db->GetTotalPurchaseReport()->GetMaxIndex())
    {
        std::list<Sale> saleList = db->GetTotalPurchaseReport()->GetPurchases(index);
        std::list<Sale>::const_iterator sales = saleList.begin();

        ui->tableWidget_ViewReports->insertRow(rowR);
        ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(QString::number(db->GetTotalPurchaseReport()->GetMember(index).GetID())));

        while(sales != saleList.end())
        {
            ui->tableWidget_ViewReports->insertRow(rowR);
            ui->tableWidget_ViewReports->setItem(rowR, 1,
                new QTableWidgetItem(sales->GetItemName()));
            ui->tableWidget_ViewReports->setItem(rowR, 2, new QTableWidgetItem(QString::number(sales->GetQuantityPurchased())));
            totals[index] += db->GetTotalPurchaseReport()->GetGrandTotal(index);
            rowR++;
            sales++;
        }

        ui->tableWidget_SIDE->insertRow(rowS);
        ui->tableWidget_SIDE->setItem(rowS, 0, new QTableWidgetItem(QString::number(db->GetTotalPurchaseReport()->GetMember(index).GetID())));
        rowS++;
        ui->tableWidget_SIDE->insertRow(rowS);
        ui->tableWidget_SIDE->setItem(rowS, 0, new QTableWidgetItem(QString::number(db->GetTotalPurchaseReport()->GetGrandTotal(index))));

        ui->tableWidget_SIDE->resizeColumnsToContents();

        index++;
    }


    ui->tableWidget_ViewReports->resizeColumnsToContents();
}



void MainWindow::on_ItemsSoldQuantity_Button_clicked()
{
    ui->tableWidget_SIDE->hide();
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

    ui->tableWidget_ViewReports->resizeColumnsToContents();
}



void MainWindow::on_Rebates_Button_clicked()
{
    ui->tableWidget_SIDE->hide();
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

    ui->tableWidget_ViewReports->resizeColumnsToContents();
}




void MainWindow::on_ItemsSoldName_Button_clicked()
{
    SearchString *search = new SearchString(0, db);

    connect(search, SIGNAL(SearchItem(QString)),
            this, SLOT(AddSearchedItem(QString)));


    search->show();
}

void MainWindow::on_MemberPurchases_Button_clicked()
{
    SearchString *search = new SearchString(1, db);

    connect(search, SIGNAL(SearchName(QString)), this, SLOT(AddMemberPurchaseString(QString)));
    connect(search, SIGNAL(SearchInt(int)), this, SLOT(AddMemberPurchaseInt(int)));
    search->show();

}

void MainWindow::on_pushButtonRemove_clicked()
{
    RemoveMemberItem *remove = new RemoveMemberItem(db, 0);
    remove->show();
    PopulateItems();
}
