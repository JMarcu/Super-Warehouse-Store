#ifndef EDITITEMWINDOW_H
#define EDITITEMWINDOW_H

#include <QMainWindow>
#include "Database.h"

namespace Ui {
class editItemWindow;
}

class editItemWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief editItemWindow
     * @param db
     * @param parent
     */
    explicit editItemWindow(Database *db, QWidget *parent = 0);
    ~editItemWindow();

signals:
    /**
         * @brief ItemEdited
         */
        void ItemEdited(QString, double);

private slots:
     /**
     * @brief on_buttonBox_edit_accepted
     */
    void on_buttonBox_edit_accepted();

    /**
     * @brief on_buttonBox_edit_rejected
     */
    void on_buttonBox_edit_rejected();

private:
    Ui::editItemWindow *ui;

    QString itemEditName;

    double itemEditPrice;

    Database *db;
};

#endif // EDITITEMWINDOW_H
