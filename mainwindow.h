#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_logoutButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    Login *log;
};

#endif // MAINWINDOW_H
