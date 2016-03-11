#include "reportwindow.h"
#include "ui_reportwindow.h"

reportWindow::reportWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::reportWindow)
{
    ui->setupUi(this);
}

reportWindow::~reportWindow()
{
    delete ui;
}

void reportWindow::on_reportclose_clicked()
{
    hide();
}
