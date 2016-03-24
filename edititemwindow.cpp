#include "edititemwindow.h"
#include "ui_edititemwindow.h"

editItemWindow::editItemWindow(Database *db, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::editItemWindow)
{
    ui->setupUi(this);
    this->db = db;
}

editItemWindow::~editItemWindow()
{
    delete ui;
}

void editItemWindow::on_buttonBox_edit_accepted()
{
    itemEditName = ui->itemNameLineEdit_edit->text();

    itemEditPrice = ui->itemPriceSpinBox_edit->value();

    /**********************
     * ADD TO DATABSE
     ************************/

    emit ItemEdited(itemEditName, itemEditPrice);

    hide();
}

void editItemWindow::on_buttonBox_edit_rejected()
{
    hide();
}

