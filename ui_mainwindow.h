/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLogout;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLineEdit *accountEdit;
    QLineEdit *passEdit;
    QPushButton *saveButton;
    QVBoxLayout *verticalLayout_2;
    QListWidget *accountList;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QLabel *nameLabel;
    QPushButton *logoutButton;
    QPushButton *loginButton;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(826, 506);
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(false);

        verticalLayout->addWidget(label_2);

        accountEdit = new QLineEdit(centralWidget);
        accountEdit->setObjectName(QStringLiteral("accountEdit"));
        accountEdit->setEnabled(false);

        verticalLayout->addWidget(accountEdit);

        passEdit = new QLineEdit(centralWidget);
        passEdit->setObjectName(QStringLiteral("passEdit"));
        passEdit->setEnabled(false);

        verticalLayout->addWidget(passEdit);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setEnabled(false);

        verticalLayout->addWidget(saveButton);


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        accountList = new QListWidget(centralWidget);
        new QListWidgetItem(accountList);
        accountList->setObjectName(QStringLiteral("accountList"));
        accountList->setEnabled(false);

        verticalLayout_2->addWidget(accountList);

        addButton = new QPushButton(centralWidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setEnabled(false);

        verticalLayout_2->addWidget(addButton);

        deleteButton = new QPushButton(centralWidget);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        deleteButton->setEnabled(false);

        verticalLayout_2->addWidget(deleteButton);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        logoutButton = new QPushButton(centralWidget);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));
        logoutButton->setEnabled(false);
        logoutButton->setMaximumSize(QSize(16777215, 23));
        logoutButton->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(logoutButton, 1, 1, 1, 1);

        loginButton = new QPushButton(centralWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        gridLayout->addWidget(loginButton, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 826, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionLogout);
        menuMenu->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Password Manager", 0));
        actionLogout->setText(QApplication::translate("MainWindow", "Logout", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        label_2->setText(QApplication::translate("MainWindow", "Edit Account Information:", 0));
        accountEdit->setText(QApplication::translate("MainWindow", "Selected Account Name", 0));
        passEdit->setText(QApplication::translate("MainWindow", "Selected Account Pass", 0));
        saveButton->setText(QApplication::translate("MainWindow", "Save", 0));

        const bool __sortingEnabled = accountList->isSortingEnabled();
        accountList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = accountList->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Account Names", 0));
        accountList->setSortingEnabled(__sortingEnabled);

        addButton->setText(QApplication::translate("MainWindow", "Add", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        nameLabel->setText(QApplication::translate("MainWindow", "UserName", 0));
        logoutButton->setText(QApplication::translate("MainWindow", "Logout", 0));
        loginButton->setText(QApplication::translate("MainWindow", "Login", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
