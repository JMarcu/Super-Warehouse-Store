#ifndef REMOVEMEMBERITEM_H
#define REMOVEMEMBERITEM_H

#include <QWidget>
#include "Database.h"
#include "errorwindow.h"


namespace Ui {
class RemoveMemberItem;
}

class RemoveMemberItem : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveMemberItem(Database *db, int index, QWidget *parent = 0);
    ~RemoveMemberItem();

signals:
    /**
     * @brief Remove
     */
    void Remove(QString);
private slots:
    /**
     * @brief on_buttonBox_accepted
     */
    void on_buttonBox_accepted();

    /**
     * @brief on_buttonBox_rejected
     */
    void on_buttonBox_rejected();

private:
    Ui::RemoveMemberItem *ui;
    QString name;
    Database *db;
    int index1;
};

#endif // REMOVEMEMBERITEM_H
