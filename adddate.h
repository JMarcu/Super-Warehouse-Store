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
     *   - sends date selected by user
     */
    void DateSelected(Date);

private slots:
    /**
     * @brief on_buttonBox_rejected
     *  - Closes window
     */
    void on_buttonBox_rejected();

    /**
     * @brief on_buttonBox_accepted
     * - closes window and sends signal to main window
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
     *  - date entered
     */
    Date date;
    /**
     * @brief index
     */
    int index;
};

#endif // ADDDATE_H
