#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QMainWindow>

/***********************************************************************
 * reportWindow
 *    
 *    This class is a sub menu for item reporting.
 *    As of right now, this sub menu is not ready to be used and is
 *    undergoing a full implementation for the program.  For now, this
 *    is used for a test.
 ***********************************************************************/
 
namespace Ui {
class reportWindow;
}

class reportWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit reportWindow(QWidget *parent = 0);
    ~reportWindow();

private slots:
    void on_reportclose_clicked();

private:
    Ui::reportWindow *ui;
};

#endif // REPORTWINDOW_H
