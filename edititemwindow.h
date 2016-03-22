#ifndef EDITITEMWINDOW_H
#define EDITITEMWINDOW_H

#include <QMainWindow>

namespace Ui {
class editItemWindow;
}

class editItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit editItemWindow(QWidget *parent = 0);
    ~editItemWindow();

signals:
        void ItemEdited(QString, int, double);

private slots:
    void on_buttonBox_edit_accepted();

    void on_buttonBox_edit_rejected();

private:
    Ui::editItemWindow *ui;

    QString itemEditName;

    int itemEditAmount;

    double itemEditPrice;

    //Items prevItem;
};

#endif // EDITITEMWINDOW_H
