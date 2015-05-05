#include "login.h"
#include "mainwindow.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

}

Login::~Login()
{
    delete ui;
}

void Login::on_exitButton_clicked()
{
    exit(0);
}

void Login::on_loginButton_clicked()
{
    //authenticate credentials
    //
    QString name = ui->userEdit->text();
    QString pass = ui->userEdit->text();
    //...
    std::string sname = name.toStdString();
    std::string spass = pass.toStdString();
    //...
    if(authenticate(sname, spass))
    {
        close();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Failed Authentication");
        msgBox.setText("Please re-enter credentials");
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
}

bool Login::authenticate(std::string, std::string)
{
    //authenticate stuff...
    return true;
}
