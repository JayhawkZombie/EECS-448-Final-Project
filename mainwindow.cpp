#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <stdio.h>
#include <QtSql/QtSql>
#include <QFormLayout>
#include <QDialogButtonBox>

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

//#include "C:\\SystemProgramming\\Qt-5.3\\sql\\connection.h"

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db3");
    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"
                     "This example needs SQLite support. Please read "
                     "the Qt SQL driver documentation for information how "
                     "to build it.\n\n"
                     "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }

    QSqlQuery query;
    query.exec("create table users (id int primary key, "
               "username varchar(20), password varchar(20))");
    query.exec("insert into users values(1, 'Danny', '1234')");
    query.exec("insert into users values(2, 'Christine', '1234')");
    query.exec("insert into users values(3, 'Lars', '1234')");
    query.exec("insert into users values(4, 'Roberto', '1234')");
    query.exec("insert into users values(5, 'Maria', '1234')");

    query.exec("drop table items");
//    query.exec("create table items (id int primary key,"
//                                             "imagefile int,"
//                                             "itemtype varchar(20),"
//                                             "description varchar(100))");
//    query.exec("insert into items "
//               "values(0, 0, 'Qt',"
//               "'Qt is a full development framework with tools designed to "
//               "streamline the creation of stunning applications and  "
//               "amazing user interfaces for desktop, embedded and mobile "
//               "platforms.')");
//    query.exec("insert into items "
//               "values(1, 1, 'Qt Quick',"
//               "'Qt Quick is a collection of techniques designed to help "
//               "developers create intuitive, modern-looking, and fluid "
//               "user interfaces using a CSS & JavaScript like language.')");
//    query.exec("insert into items "
//               "values(2, 2, 'Qt Creator',"
//               "'Qt Creator is a powerful cross-platform integrated "
//               "development environment (IDE), including UI design tools "
//               "and on-device debugging.')");
//    query.exec("insert into items "
//               "values(3, 3, 'Qt Project',"
//               "'The Qt Project governs the open source development of Qt, "
//               "allowing anyone wanting to contribute to join the effort "
//               "through a meritocratic structure of approvers and "
//               "maintainers.')");

//    query.exec("create table images (itemid int, file varchar(20))");
//    query.exec("insert into images values(0, 'images/qt-logo.png')");
//    query.exec("insert into images values(1, 'images/qt-quick.png')");
//    query.exec("insert into images values(2, 'images/qt-creator.png')");
//    query.exec("insert into images values(3, 'images/qt-project.png')");

    return true;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//
//create simple dialog that displays a button and has an ok button
//
//    QDialog dialog(this);
//    QFormLayout form(&dialog);
//    QLabel *message = new QLabel("Please select the Login button");
//    form.addWidget(message);
//    QDialogButtonBox buttonBox(QDialogButtonBox::Ok, &dialog);
//    form.addRow(&buttonBox);
//    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
//    dialog.exec();

//
//run database generation code
//
    if (!createConnection())
            exit(1);

//
//runs loginBuuton call which opens the login dialog
//
    on_loginButton_clicked();

//
//simple database example
//
//    this->hide();
//    QSqlDatabase db;
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("users.db3");
//    db.open();
//    db.
//    this->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logoutButton_clicked()
{
    close();
}

void MainWindow::on_loginButton_clicked()
{
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("Please enter credentials:"));

    // Add the lineEdits with their respective labels
    QLineEdit *userEdit = new QLineEdit(&dialog);
    QString userString = QString("Username:");
    form.addRow(userString, userEdit);

    QLineEdit *passEdit = new QLineEdit(&dialog);
    QString passString = QString("Password:");
    form.addRow(passString, passEdit);

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Show the dialog as modal
    if (dialog.exec() == QDialog::Accepted) {
        // If the user didn't dismiss the dialog, do something with the fields
        ui->nameLabel->setText(userEdit->text());
    }
    else {

    }
}
