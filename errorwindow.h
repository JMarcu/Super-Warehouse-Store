#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class ErrorWindow;
}

/**
 * @brief The ErrorWindow class
 */
class ErrorWindow : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief ErrorWindow
     * @param index
     * @param parent
     */
    explicit ErrorWindow(int index, QWidget *parent = 0);
    ~ErrorWindow();

private slots:
    /**
     * @brief on_pushButtonOK_clicked
     */
    void on_pushButtonOK_clicked();

private:
    Ui::ErrorWindow *ui;
    QString message;
};

#endif // ERRORWINDOW_H
