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
    /**
     * @brief AddDate
     * @param index
     * @param parent
     */
    explicit AddDate(int index, QWidget *parent = 0);


    ~AddDate();
signals:
    /**
     * @brief DateSelected
     */
    void DateSelected(Date);

private slots:
    /**
     * @brief on_buttonBox_rejected
     */
    void on_buttonBox_rejected();

    /**
     * @brief on_buttonBox_accepted
     */
    void on_buttonBox_accepted();

    /**
     * @brief ReturnDate
     * @return
     */
    Date ReturnDate() const;

private:
    /**
     * @brief ui
     */
    Ui::AddDate *ui;

    /**
     * @brief date
     */
    Date date;
    /**
     * @brief index
     */
    int index;
};

#endif // ADDDATE_H
