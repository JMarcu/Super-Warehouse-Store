#ifndef SEARCHSTRING_H
#define SEARCHSTRING_H

#include <QWidget>
#include <QString>
#include "Database.h"

namespace Ui {
class SearchString;
}

class SearchString : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief SearchString
     * @param index
     * @param db
     * @param parent
     */
    explicit SearchString(int index, Database *db, QWidget *parent = 0);
    ~SearchString();

signals:
    /**
     * @brief SearchItem
     */
    void SearchItem(QString);

    /**
     * @brief SearchName
     */
    void SearchName(QString);

    /**
     * @brief SearchInt
     */
    void SearchInt(int);

private slots:

    /**
     * @brief on_buttonBox_accepted
     */
    void on_buttonBox_accepted();

    /**
     * @brief on_buttonBox_rejected
     */
    void on_buttonBox_rejected();

    /**
     * @brief on_pushButton_Name_clicked
     */
    void on_pushButton_Name_clicked();

    /**
     * @brief on_pushButton_ID_clicked
     */
    void on_pushButton_ID_clicked();

private:
    Ui::SearchString *ui;

    QString search;
    int searchInt;
    int index;
    int clicked;

    Database *db;
};

#endif // SEARCHSTRING_H
