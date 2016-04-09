#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * @param db
 * @param parent
 */
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
    rowS = 0;

    this->db = db;
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::AddItemToItemsTable
 * @param name
 * @param price
 */
void MainWindow::AddItemToItemsTable(QString name, double price)
{
    ui->tableWidgetItem->insertRow(rowI);
    ui->tableWidgetItem->setItem(rowI,0,new QTableWidgetItem(name));
    ui->tableWidgetItem->setItem(rowI,1,new QTableWidgetItem(QString::number(price)));
    rowI++;
    ui->tableWidgetItem->resizeColumnsToContents();
}

/**
 * @brief MainWindow::AddMemberToTable
 * @param name
 * @param id
 * @param expiration
 * @param isExecutive
 * @param totalSpent
 */
void MainWindow::AddMemberToTable(QString name, int id, Date expiration, bool isExecutive, double totalSpent)
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
    ui->tableWidgetMembers->setItem(rowM, 4, new QTableWidgetItem(QString::number(totalSpent)));
    rowM++;
    ui->tableWidgetMembers->resizeColumnsToContents();
}

/**
 * @brief MainWindow::AddDailySalesReport
 * @param dateIn
 */
void MainWindow::AddDailySalesReport(Date dateIn)
{
    ui->tableWidget_SIDE->show();
    ClearTable(ui->tableWidget_SIDE);
    ClearTable(ui->tableWidget_ViewReports);

    const DailySalesReport *dsr = db->GetDailySalesReport(dateIn,(int) 0);

    const std::list<Sale> salesList = dsr->GetDailySales();
    std::list<Sale>::const_iterator sales = salesList.begin();

    if(salesList.size() == 0 )
    {
        ErrorWindow *error = new ErrorWindow(5);
        error->show();
    }
    else
    {
        qDebug() << "DAILY SALES REPORT-";
        qDebug() << "------------------------------------------------------------";

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

            qDebug() << "Item Name: " << sales->GetItemName() << "\tQuantity Sold: " << sales->GetQuantityPurchased();
            sales++;
        }

        ui->tableWidget_SIDE->insertColumn(colS);
        ui->tableWidget_SIDE->setHorizontalHeaderItem(colS, new QTableWidgetItem("Number of Executives Sales"));

        colS++;
        ui->tableWidget_SIDE->insertColumn(colS);
        ui->tableWidget_SIDE->setHorizontalHeaderItem(colS, new QTableWidgetItem("Number of Regular Sales"));

        colS++;
        ui->tableWidget_SIDE->insertColumn(colS);
        ui->tableWidget_SIDE->setHorizontalHeaderItem(colS, new QTableWidgetItem("Total Revenue for " + dateIn.toString()));

        ui->tableWidget_SIDE->insertRow(rowS);
        ui->tableWidget_SIDE->setItem(rowS, 0, new QTableWidgetItem(QString::number(dsr->GetExecutiveCount())));
        ui->tableWidget_SIDE->setItem(rowS, 1, new QTableWidgetItem(QString::number(dsr->GetRegularCount())));
        ui->tableWidget_SIDE->setItem(rowS, 2, new QTableWidgetItem(QString::number(totalRevenue)));

        qDebug() << "Number of Executives Sales: " << dsr->GetExecutiveCount();
        qDebug() << "Number of Regular Sales: " << dsr->GetRegularCount();
        qDebug() << "Total Revenue: " << totalRevenue;

        ui->tableWidget_SIDE->resizeColumnsToContents();
        ui->tableWidget_SIDE->horizontalHeader()->setStretchLastSection(true);
    }

    qDebug() << endl << endl << endl;

    ui->tableWidget_ViewReports->resizeColumnsToContents();
    ui->tableWidget_ViewReports->horizontalHeader()->setStretchLastSection(true);
    delete dsr;

}

/**
 * @brief MainWindow::ExpiredMembershipsReport
 * @param dateIn
 */
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

/**
 * @brief MainWindow::on_pushButtonAdd_clicked
 */
void MainWindow::on_pushButtonAdd_clicked()
{
    AddItemWindow *add = new AddItemWindow(db);

    connect(add, SIGNAL(ItemAdded(QString,int)),
            this, SLOT(AddItemToItemsTable(QString,int)));
    add->show();

}

/**
 * @brief MainWindow::on_pushButton_MemberAdd_clicked
 */
void MainWindow::on_pushButton_MemberAdd_clicked()
{
    AddMemberWindow *member = new AddMemberWindow(db);

    connect(member,SIGNAL(AddMember(QString, int, Date, bool, double)),
            this, SLOT(AddMemberToTable(QString, int, Date, bool, double)));

    member->show();
}

/**
 * @brief MainWindow::on_pushButtonEdit_clicked
 */
void MainWindow::on_pushButtonEdit_clicked()
{   
    editItemWindow *item = new editItemWindow(db);
    connect(item, SIGNAL(ItemEdited(QString,double)), this, SLOT(PopulateItems()));
    item->show();
//    PopulateItems();
}

/**
 * @brief MainWindow::on_pushButton_MemberEdit_clicked
 */
void MainWindow::on_pushButton_MemberEdit_clicked()
{
    editMemberWindow *memberEdit = new editMemberWindow(db);

    connect(memberEdit, SIGNAL(MemberEdit(QString, int, Date, bool, double)),
            this, SLOT(AddMemberToTable(QString, int, Date, bool, double)));

    memberEdit->show();
//    PopulateMembers();
}

/**
 * @brief MainWindow::on_pushButton_MemberRemove_clicked
 */
void MainWindow::on_pushButton_MemberRemove_clicked()
{
    RemoveMemberItem *toRemove = new RemoveMemberItem(db, 1);
    toRemove->show();
}

/**
 * @brief MainWindow::PopulateMembers
 */
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
        AddMemberToTable(members->GetName(), members->GetID(), members->GetExpiration(), members->IsExecutive(), members->GetTotalSpent());
        members++;
    }


    delete memberList;
}

/**
 * @brief MainWindow::PopulateItems
 */
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

/**
 * @brief MainWindow::AddSearchedItem
 * @param name
 */
void MainWindow::AddSearchedItem(QString name)
{
    ui->tableWidget_SIDE->hide();
    ClearTable(ui->tableWidget_ViewReports);

    const ItemReport *ir = db->GetItemReport(Item(name));

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
    ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(ir->GetItem().GetItem()));
    ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem(QString::number(ir->GetQuantitySold())));
    ui->tableWidget_ViewReports->setItem(rowR, 2, new QTableWidgetItem(QString::number(ir->GetTotalRevenue())));

    ui->tableWidget_ViewReports->resizeColumnsToContents();


    delete ir;
}


/**
 * @brief MainWindow::ClearTable
 * @param table
 */
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
    colS = 0;
    rowS = 0;
}


/**
 * @brief MainWindow::AddMemberPurchaseString
 * @param name
 */
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


/**
 * @brief MainWindow::AddMemberPurchaseInt
 * @param id
 */
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


/**
 * @brief MainWindow::on_ViewMembers_tabBarClicked
 * @param index
 */
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


/**
 * @brief MainWindow::on_SalesReport_Button_clicked
 */
void MainWindow::on_SalesReport_Button_clicked()
{
    AddDate *date = new AddDate(0);

    connect(date, SIGNAL(DateSelected(Date)),
            this, SLOT(AddDailySalesReport(Date)));
    date->show();
}


/**
 * @brief MainWindow::on_Expire_Button_clicked
 */
void MainWindow::on_Expire_Button_clicked()
{
    AddDate *date = new AddDate(1);

    connect(date, SIGNAL(DateSelected(Date)),
            this, SLOT(ExpiredMembershipsReport(Date)));

        date->show();

}

/**
 * @brief MainWindow::on_Convert_Button_clicked
 */
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

/**
 * @brief MainWindow::on_TotalPurchases_Button_clicked
 */
void MainWindow::on_TotalPurchases_Button_clicked()
{
    ui->tableWidget_SIDE->hide();

    const TotalPurchaseReport* tpr = db->GetTotalPurchaseReport();

    ClearTable(ui->tableWidget_ViewReports);

    int index = 0;

    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Member ID"));

    colR++;
    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Total Spent"));

    colR++;
    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Item"));

    colR++;
    ui->tableWidget_ViewReports->insertColumn(colR);
    ui->tableWidget_ViewReports->setHorizontalHeaderItem(colR, new QTableWidgetItem("Quantity"));

    rowR = 0;

    qDebug() << "TOTAL PURCHASE REPORTS - ";
    qDebug() << "-------------------------------------------------------------------";

    while(index < tpr->GetMaxIndex())
    {
        std::list<Sale> saleList              = tpr->GetPurchases(index);
        std::list<Sale>::const_iterator sales = saleList.begin();

        ui->tableWidget_ViewReports->insertRow(rowR);
        ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(QString::number(tpr->GetMember(index).GetID())));
        ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem(QString::number(tpr->GetGrandTotal(index))));

        qDebug() << "Member ID: " << tpr->GetMember(index).GetID() << "\tTotal Spent: " << tpr->GetGrandTotal(index);

        qDebug() << "Purchases Made: ";
        while(sales != saleList.end())
        {
            qDebug() << "Item Name: " << sales->GetItemName() << "\t# Purchased: " << sales->GetQuantityPurchased();

            ui->tableWidget_ViewReports->setItem(rowR, 2,
                new QTableWidgetItem(sales->GetItemName()));
            ui->tableWidget_ViewReports->setItem(rowR, 3, new QTableWidgetItem(QString::number(sales->GetQuantityPurchased())));
            rowR++;


            ui->tableWidget_ViewReports->insertRow(rowR);
            sales++;
        }

        ui->tableWidget_ViewReports->removeRow(rowR);

        index++;
    }

    qDebug() << endl << endl << endl;

    ui->tableWidget_ViewReports->resizeColumnsToContents();

    delete tpr;

}//END - void MainWindow::on_TotalPurchases_Button_clicked()


/**
 * @brief MainWindow::on_ItemsSoldQuantity_Button_clicked
 */
void MainWindow::on_ItemsSoldQuantity_Button_clicked()
{
    qDebug() << "ITEMS SOLD - ";
    qDebug() << "------------------------------------------------";
    ui->tableWidget_SIDE->hide();
    ClearTable(ui->tableWidget_ViewReports);
    int index = 0;

    const TotalItemReport *tir = db->GetTotalItemReport();

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

    while(index < tir->ItemCount())
    {
        qDebug() << "Item Name: " << tir->GetItem(index).GetItem() << "\t# Sold: " << tir->GetQuantitySold(index) << "\tRevenue: " << tir->GetRevenue(index);
        ui->tableWidget_ViewReports->insertRow(rowR);
        ui->tableWidget_ViewReports->setItem(rowR, 0, new QTableWidgetItem(tir->GetItem(index).GetItem()));
        ui->tableWidget_ViewReports->setItem(rowR, 1, new QTableWidgetItem(QString::number(tir->GetQuantitySold(index))));
        ui->tableWidget_ViewReports->setItem(rowR, 2, new QTableWidgetItem(QString::number(tir->GetRevenue(index))));
        index++;
        rowR++;
    }

    ui->tableWidget_ViewReports->resizeColumnsToContents();

    qDebug() << endl << endl << endl;

    delete tir;
}


/**
 * @brief MainWindow::on_Rebates_Button_clicked
 */
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



/**
 * @brief MainWindow::on_ItemsSoldName_Button_clicked
 */
void MainWindow::on_ItemsSoldName_Button_clicked()
{
    SearchString *search = new SearchString(0, db);

    connect(search, SIGNAL(SearchItem(QString)),
            this, SLOT(AddSearchedItem(QString)));


    search->show();
}

/**
 * @brief MainWindow::on_MemberPurchases_Button_clicked
 */
void MainWindow::on_MemberPurchases_Button_clicked()
{
    SearchString *search = new SearchString(1, db);

    connect(search, SIGNAL(SearchName(QString)), this, SLOT(AddMemberPurchaseString(QString)));
    connect(search, SIGNAL(SearchInt(int)), this, SLOT(AddMemberPurchaseInt(int)));
    search->show();

}

/**
 * @brief MainWindow::on_pushButtonRemove_clicked
 */
void MainWindow::on_pushButtonRemove_clicked()
{
    RemoveMemberItem *remove = new RemoveMemberItem(db, 0);
    remove->show();
}
