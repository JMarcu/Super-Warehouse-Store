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
    explicit SearchString(int index, Database *db, QWidget *parent = 0);
    ~SearchString();

signals:
    void SearchItem(QString);
    void SearchName(QString);
    void SearchInt(int);

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_Name_clicked();

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
