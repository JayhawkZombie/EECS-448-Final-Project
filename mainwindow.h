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

    void exitFunction();

    void registerAccount();

    void insertUser(std::string, std::string);

    bool createConnection();

    void invalidDialog(std::string);

    void authenticate(std::string, std::string);

private:
    Ui::MainWindow *ui;
    Login *log;
};

#endif // MAINWINDOW_H
