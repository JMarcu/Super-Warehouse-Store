#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QMainWindow>

namespace Ui {
class reportWindow;
}

class reportWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit reportWindow(QWidget *parent = 0);
    ~reportWindow();

private slots:
    void on_reportclose_clicked();

private:
    Ui::reportWindow *ui;
};

#endif // REPORTWINDOW_H
