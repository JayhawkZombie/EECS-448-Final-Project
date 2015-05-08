#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>

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

    void invalidDialog(std::string);

    void authenticate(std::string, std::string);

    void enableStatus(bool);

    void on_addButton_clicked();

    void updateAccountList();

    void addAccount();

    void deleteAccount();

    void on_deleteButton_clicked();

    void on_saveButton_clicked();

    void on_accountList_itemClicked(QListWidgetItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
