#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class ErrorWindow;
}

class ErrorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorWindow(int index, QWidget *parent = 0);
    ~ErrorWindow();

private slots:
    void on_pushButtonOK_clicked();

private:
    Ui::ErrorWindow *ui;
    QString message;
};

#endif // ERRORWINDOW_H
