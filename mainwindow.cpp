#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Database *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidgetItem->horizontalHeader()->setVisible(true);

    ui->pushButtonEdit->hide();
    ui->pushButtonRemove->hide();

    rowI = 0;
    rowM = 0;

    this->db = db;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddItemToItemsTable(QString name, int quantity, double price)
{
    ui->tableWidgetItem->insertRow(rowI);
    ui->tableWidgetItem->setItem(rowI,0,new QTableWidgetItem(name));
    ui->tableWidgetItem->setItem(rowI,1,new QTableWidgetItem(QString::number(quantity)));
    ui->tableWidgetItem->setItem(rowI,2,new QTableWidgetItem(QString::number(price)));
    rowI++;
    ui->tableWidgetMembers->resizeColumnsToContents();
}

void MainWindow::SortColumn(int column)
{

   ui->tableWidgetItem->sortItems(column, Qt::AscendingOrder);

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


void MainWindow::on_pushButtonAdd_clicked()
{
    AddItemWindow *add = new AddItemWindow();

    connect(add, SIGNAL(ItemAdded(QString,int,double)),
            this, SLOT(AddItemToItemsTable(QString,int,double)));
    add->show();

}

void MainWindow::on_tableWidgetItem_cellClicked(int row, int column)
{

    ui->pushButtonEdit->show();
    ui->pushButtonRemove->show();
}


void MainWindow::on_pushButton_MemberAdd_clicked()
{
    AddMemberWindow *member = new AddMemberWindow();
    connect(member,SIGNAL(AddMember(QString, int, Date, bool)),
            this, SLOT(AddMemberToTable(QString, int, Date, bool)));

    member->show();
}

void MainWindow::on_pushButtonEdit_clicked()
{
    editItemWindow *item = new editItemWindow();





}

void MainWindow::on_ViewReports_tabBarClicked(int index)
{
    std::list<Member> *memList = db->GetAllMembers();

    std::list<Member>::const_iterator members = memList->begin();


    while(members != memList->end())
    {
        AddMemberToTable(members->GetName(), members->GetID(), members->GetExpiration(), members->IsExecutive());
        members++;
    }

    delete memList;
}
