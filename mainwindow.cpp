#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <stdio.h>
#include <QtSql/QtSql>
#include <QDebug>
#include <QFormLayout>
#include <QDialogButtonBox>

#include <QListWidgetItem>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "encryption.h"

//comments doh

//#include "C:\\SystemProgramming\\Qt-5.3\\sql\\connection.h"
std::string username = "";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    std::string message = "This program is a simple solution to password management\n"
                          "As a user you will be able to enter username and password combo's that will be encrypted in storage for security\n\n"
                            "You'll be prompted to login to the program on startup\n"
                            "You can register a new account and return to the login screen by selecting the \"Register\" button\n\n"
                            "Once you enter the application you'll be able to add new account/password combos";
    invalidDialog(message);

//
//runs loginBuuton call which opens the login dialog
//
    on_loginButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_logoutButton_clicked()
{
    on_loginButton_clicked();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Login Dialog Dialog
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::on_loginButton_clicked()
{
    this->hide();
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    form.addRow(new QLabel("Please enter credentials:"));

    // Add the lineEdits with their respective labels
    QLineEdit *userEdit = new QLineEdit(&dialog);
    QString userString = QString("Username:");
    form.addRow(userString, userEdit);

    //create password edit, set echo mode to password for password entry
    QLineEdit *passEdit = new QLineEdit(&dialog);
    passEdit->setEchoMode(QLineEdit::Password);
    QString passString = QString("Password:");
    form.addRow(passString, passEdit);

    // Add some standard buttons (Cancel/Ok) at the bottom of the dialog
    QPushButton *regButton = new QPushButton();
    QPushButton *okButton = new QPushButton();
    QPushButton *cancelButton = new QPushButton();
    regButton->setText("Register");
    okButton->setText("Ok");
    cancelButton->setText("Cancel");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);
    layout->addWidget(regButton);

    //QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, &dialog);
    form.addRow(layout);
    QObject::connect(regButton, SIGNAL(clicked()), this, SLOT(registerAccount()));
    QObject::connect(okButton, SIGNAL(clicked()), &dialog, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(exitFunction()));

    dialog.setWindowFlags( ( (dialog.windowFlags() | Qt::CustomizeWindowHint) & ~Qt::WindowCloseButtonHint) );

    // ok button pressed enters the if statement
    // cancel button closes application
    // register button opens register dialog
    if (dialog.exec() == QDialog::Accepted) {
        // If the user didn't dismiss the dialog, do something with the fields
        std::string user = userEdit->text().toStdString();
        std::string pss = passEdit->text().toStdString();

        authenticate(user, pss);
        this->show();
        enableStatus(true);
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  enable all of the items in the mainwindow and populate accountList
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::enableStatus(bool stat)
{
    ui->logoutButton->setEnabled(stat);
    ui->accountList->setEnabled(stat);
    ui->staticInfoLabel->setEnabled(stat);
    ui->addButton->setEnabled(stat);
    ui->deleteButton->setEnabled(stat);

    updateAccountList();
    ui->accountEdit->setEnabled(stat);
    ui->passEdit->setEnabled(stat);
    ui->saveButton->setEnabled(stat);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  update account list
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::updateAccountList()
{
    qDebug() << "Entering updateAccountList";
    ui->accountList->clear();
    ui->accountEdit->clear();
    ui->passEdit->clear();
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( "users.db3" );
    if( !db.open() )
    {
      qDebug() << db.lastError();
      qFatal( "Failed to connect." );
    }

    QSqlQuery qry;
    QString queryString = "SELECT * FROM '" + QString::fromStdString(encryption::encrypt(username, 29, 41)) + "'";\
    qDebug() << queryString;
    qry.prepare(queryString);
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
        qDebug( "entries Selected!" );

        QSqlRecord rec = qry.record();

        int cols = rec.count();

        for( int c=0; c<cols; c++ )
            qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

        for( int r=0; qry.next(); r++ )
        {
            ui->accountList->addItem(QString::fromStdString(encryption::decrypt(qry.value(0).toString().toStdString(), 29, 41)));
            for( int c=0; c<cols; c++ )
            {
                qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
            }//for
        }//for
    }

    if (ui->accountList->count() == 0)
    {
        std::string message = "It seems you don't have any entries associated with your account\n"
                                "Please enter a new username/password combo in the lineEdit boxes in the bottom right\n"
                                "You can then select \"Add\" or \"Save\" to add the combo to your account\n\n"
                                "Once you have a couple entries you can select said entries from the listWidget on the middle left\n"
                                "Clicking on entries will populate the lineEdits and you may edit thier information";
        //invalidDialog(message);
    }
    db.close();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Authenticate user on login
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::authenticate(std::string user, std::string pss)
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
    }

    QString queryString = "SELECT * FROM users WHERE username='" + QString::fromStdString(encryption::encrypt(user, 29, 41)) + "'";
    QSqlQuery query(db);
    query.prepare(queryString);

    if( !query.exec() )
      qDebug() << query.lastError();
    else
    {
        qDebug( "Selected!" );
        query.first();
        QSqlRecord rec = query.record();
        qDebug() << rec.value(0).toString();

        if (rec.value(0).toString() == "")
        {
            invalidDialog("Username not found");
            db.close();
            on_loginButton_clicked();
        }//not in database
        else if(QString::fromStdString(encryption::decrypt(rec.value(1).toString().toStdString(), 29, 41)) != QString::fromStdString(pss))
        {
            invalidDialog("Password doesn't match any on record");
            db.close();
            on_loginButton_clicked();
        }
        else
        {
            username = user;
            ui->nameLabel->setText(QString::fromStdString(user));
        }
//      int cols = rec.count();

//      for( int r=0; query.next(); r++ )
//        for( int c=0; c<cols; c++ )
//          qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( query.value(c).toString() );
    }
    db.close();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Call if you want to connect a slot to close the program
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::exitFunction()
{
    exit(1);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  Add account Dialog
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::registerAccount()
{
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add the lineEdits with their respective labels
    QLineEdit *userEdit = new QLineEdit(&dialog);
    QString userString = QString("Username:");
    form.addRow(userString, userEdit);

    //create password edit, set echo mode to password for password entry
    QLineEdit *passEdit = new QLineEdit(&dialog);
    QString passString = QString("Password:");
    form.addRow(passString, passEdit);

    QLineEdit *conPassEdit = new QLineEdit(&dialog);
    QString conPassString = QString("Confirm Password:");
    form.addRow(conPassString, conPassEdit);

    //Add buttons to the register dialog
    QPushButton *okButton = new QPushButton();
    QPushButton *cancelButton = new QPushButton();
    okButton->setText("Ok");
    cancelButton->setText("Cancel");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(okButton);
    layout->addWidget(cancelButton);

    form.addRow(layout);
    QObject::connect(okButton, SIGNAL(clicked()), &dialog, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), &dialog, SLOT(close()));

    if (dialog.exec() == QDialog::Accepted) {
        //add the user to the database

        //check passwords are equivalent
        if (passEdit->text() == conPassEdit->text() && userEdit->text() != "")
        {
            std::string usr = userEdit->text().toStdString();
            std::string pss = passEdit->text().toStdString();
            insertUser(usr, pss);
        }
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  insert User into database
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::insertUser(std::string usr, std::string pss)
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
    }

    QString queryString = "SELECT count(*) FROM sqlite_master WHERE type='table' AND name='" + QString::fromStdString(encryption::encrypt(usr, 29, 41)) + "'";
    QSqlQuery query(db);
    query.prepare(queryString);

    if( !query.exec() )
      qDebug() << query.lastError();
    else
    {
      qDebug( "Selected!" );

      QSqlRecord rec = query.record();

      int cols = rec.count();

      for( int r=0; query.next(); r++ )
        for( int c=0; c<cols; c++ )
          qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( query.value(c).toString() );
    }


    query.first();
    qDebug() << query.value(0).toString();
    if (query.value(0).toString() == "0" && usr != "users")
    {
        QSqlQuery query1(db);
        queryString = "create table '" + QString::fromStdString(encryption::encrypt(usr,29,41)) + "' (username varchar(20), password varchar(20))";
        qDebug() << queryString;
        query1.prepare(queryString);
        query1.exec();
        //insert into users(username, password) values('amy', '1234')
        queryString = "insert into users(username, password) values('" + QString::fromStdString(encryption::encrypt(usr, 29, 41)) + "', '" + QString::fromStdString(encryption::encrypt(pss, 29, 41)) + "')";
        qDebug() << queryString;
        query1.prepare(queryString);
        query1.exec();

    }
    else if (query.value(0).toString() == "1")
    {
        qDebug() << "Table exists";
        invalidDialog("Invalid Username please select another");
        registerAccount();
        db.close();
    }
    db.close();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  inform user that the username has already been taken
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::invalidDialog(std::string str)
{
    QDialog dialog(this);
    // Use a layout allowing to have a label next to each field
    QFormLayout form(&dialog);

    // Add some text above the fields
    QLabel *label = new QLabel(QString::fromStdString(str));
    label->setAlignment(Qt::AlignCenter);
    form.addRow(label);

    //Add buttons to the register dialog
    QPushButton *okButton = new QPushButton();
    okButton->setText("Ok");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(okButton);

    form.addRow(layout);
    QObject::connect(okButton, SIGNAL(clicked()), &dialog, SLOT(accept()));

    dialog.exec();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  connect to database initially - mainly referrence code
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool MainWindow::createConnection()
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
    db.close();
    return true;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  add account object to a users database
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::on_addButton_clicked()
{
    if (ui->accountEdit->text() == "" || ui->passEdit->text() == "")
    {
        invalidDialog("Please enter an appropriate username or password in the account info fields");
    }
    else if (ui->accountEdit->text() == "Selected Account Name" || ui->passEdit->text() == "Selected Account Password")
    {
        invalidDialog("Please clear account info' fields");
    }
    else
    {
        addAccount();
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  add account object to a users database table
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::addAccount()
{
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( "users.db3" );
    if( !db.open() )
    {
      qDebug() << db.lastError();
      qFatal( "Failed to connect." );
    }

    QSqlQuery qry;

    QString queryString = "INSERT INTO '" + QString::fromStdString(encryption::encrypt(username, 29, 41)) + "' (username, password) VALUES ('" + QString::fromStdString(encryption::encrypt(ui->accountEdit->text().toStdString(),29,41)) + "', '" + QString::fromStdString(encryption::encrypt(ui->passEdit->text().toStdString(),29,41)) + "')";
    qDebug() << queryString;
    qry.prepare(queryString);
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
        db.close();
        updateAccountList();
    }
    db.close();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  delete account object to a users database table
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::deleteAccount()
{
    if (ui->accountList->currentRow() != -1)
    {
        QString itemString = ui->accountList->currentItem()->text();

        QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
        db.setDatabaseName( "users.db3" );
        if( !db.open() )
        {
          qDebug() << db.lastError();
          qFatal( "Failed to connect." );
        }

        QSqlQuery qry;

        QString queryString = "DELETE FROM '" + QString::fromStdString(encryption::encrypt(username,29,41)) + "' WHERE username='" + QString::fromStdString(encryption::encrypt(itemString.toStdString(),29,41)) + "'";
        qDebug() << queryString;
        qry.prepare(queryString);
        if( !qry.exec() )
          qDebug() << qry.lastError();
        else
        {
            db.close();
            qDebug() << "Leaving deleteAccount";
            updateAccountList();
        }
        db.close();
    }
    else
    {
        invalidDialog("Please select an entry to delete");
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  delete entries from a users account
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::on_deleteButton_clicked()
{
    deleteAccount();
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  save edited account information to database
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::on_saveButton_clicked()
{
    if (ui->accountEdit->text() == "" || ui->passEdit->text() == "")
    {
        invalidDialog("Please enter a valid username/password");
    }
    else
    {
        QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
        db.setDatabaseName( "users.db3" );
        if( !db.open() )
        {
          qDebug() << db.lastError();
          qFatal( "Failed to connect." );
        }

        QString queryString = "SELECT * FROM '" + QString::fromStdString(encryption::encrypt(username,29,41)) + "' WHERE username='" + QString::fromStdString(encryption::encrypt(ui->accountEdit->text().toStdString(),29,41)) + "'";
        QSqlQuery query(db);
        query.prepare(queryString);

        if( !query.exec() )
          qDebug() << query.lastError();
        else
        {
            qDebug( "Selected!" );
            query.first();
            QSqlRecord rec = query.record();
            qDebug() << rec.value(0).toString();

            if (rec.value(0).toString() == "")
            {
                db.close();
                addAccount();
            }//not in database
            else
            {
                QString queryString = "UPDATE '" + QString::fromStdString(encryption::encrypt(username,29,41)) + "' SET password='" + QString::fromStdString(encryption::encrypt(ui->passEdit->text().toStdString(),29,41)) + "' " + "WHERE username='" + QString::fromStdString(encryption::encrypt(ui->accountEdit->text().toStdString(),29,41)) + "'";
                qDebug() << queryString;
                query.prepare(queryString);
                query.exec();
                db.close();
            }
        }
        updateAccountList();
    }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//  update account infor line edits when currentItem changes
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::on_accountList_itemClicked(QListWidgetItem *item)
{
    ui->accountEdit->setText(item->text());
    QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( "users.db3" );
    if( !db.open() )
    {
      qDebug() << db.lastError();
      qFatal( "Failed to connect." );
    }

    QSqlQuery qry;

    QString queryString = "SELECT * FROM '" + QString::fromStdString(encryption::encrypt(username,29,41)) + "' WHERE username='" + QString::fromStdString(encryption::encrypt(item->text().toStdString(), 29, 41)) + "'";\
    qDebug() << queryString;
    qry.prepare(queryString);
    if( !qry.exec() )
      qDebug() << qry.lastError();
    else
    {
        qDebug( "entry Selected!" );

        QSqlRecord rec = qry.record();

        int cols = rec.count();

        for( int c=0; c<cols; c++ )
            qDebug() << QString( "Column %1: %2" ).arg( c ).arg( rec.fieldName(c) );

        for( int r=0; qry.next(); r++ )
        {
            ui->passEdit->setText(QString::fromStdString(encryption::decrypt(qry.value(1).toString().toStdString(), 29, 41)));
            for( int c=0; c<cols; c++ )
            {
                qDebug() << QString( "Row %1, %2: %3" ).arg( r ).arg( rec.fieldName(c) ).arg( qry.value(c).toString() );
            }//for
        }//for
    }
    db.close();
}
