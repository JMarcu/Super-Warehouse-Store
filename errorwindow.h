#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QWidget>

namespace Ui {
class ErrorWindow;
}

class ErrorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorWindow(QWidget *parent = 0);
    ~ErrorWindow();

private slots:
    void on_pushButtonOK_clicked();

private:
    Ui::ErrorWindow *ui;
};

#endif // ERRORWINDOW_H
