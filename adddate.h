#ifndef ADDDATE_H
#define ADDDATE_H

#include <QWidget>
#include "date.h"

namespace Ui {
class AddDate;
}

class AddDate : public QWidget
{
    Q_OBJECT

public:
    explicit AddDate(QWidget *parent = 0);
    ~AddDate();
signals:
    void DateSelected(Date);

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    Date ReturnDate() const;

    void on_month_currentIndexChanged(int index);

    void on_year_currentIndexChanged(int index);

private:
    Ui::AddDate *ui;

    Date date;
};

#endif // ADDDATE_H
