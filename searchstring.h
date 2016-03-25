#ifndef SEARCHSTRING_H
#define SEARCHSTRING_H

#include <QWidget>
#include <QString>
#include <Database.h>

namespace Ui {
class SearchString;
}

class SearchString : public QWidget
{
    Q_OBJECT

public:
    explicit SearchString(Database *db, QWidget *parent = 0);
    ~SearchString();

signals:
    void SearchItem(QString);

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SearchString *ui;

    QString itemName;

    Database *db;
};

#endif // SEARCHSTRING_H
