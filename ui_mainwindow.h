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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *nameLabel;
    QFrame *line;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_2;
    QListWidget *accountList;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QVBoxLayout *verticalLayout;
    QPushButton *loginButton;
    QPushButton *logoutButton;
    QSpacerItem *verticalSpacer;
    QLabel *staticInfoLabel;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *accountEdit;
    QLineEdit *passEdit;
    QPushButton *saveButton;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(540, 404);
        actionLogout = new QAction(MainWindow);
        actionLogout->setObjectName(QStringLiteral("actionLogout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 10, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(nameLabel);


        verticalLayout_3->addLayout(horizontalLayout);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(5);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_3->addWidget(line);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(10, 10, 10, 10);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 10, 10, 10);
        accountList = new QListWidget(centralWidget);
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


        formLayout->setLayout(1, QFormLayout::LabelRole, verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(10, 10, 10, 10);
        loginButton = new QPushButton(centralWidget);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        verticalLayout->addWidget(loginButton);

        logoutButton = new QPushButton(centralWidget);
        logoutButton->setObjectName(QStringLiteral("logoutButton"));
        logoutButton->setEnabled(false);
        logoutButton->setMaximumSize(QSize(16777215, 23));
        logoutButton->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(logoutButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        staticInfoLabel = new QLabel(centralWidget);
        staticInfoLabel->setObjectName(QStringLiteral("staticInfoLabel"));
        staticInfoLabel->setEnabled(false);

        verticalLayout->addWidget(staticInfoLabel);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, -1, -1, -1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        accountEdit = new QLineEdit(centralWidget);
        accountEdit->setObjectName(QStringLiteral("accountEdit"));
        accountEdit->setEnabled(false);

        gridLayout->addWidget(accountEdit, 1, 1, 1, 1);

        passEdit = new QLineEdit(centralWidget);
        passEdit->setObjectName(QStringLiteral("passEdit"));
        passEdit->setEnabled(false);

        gridLayout->addWidget(passEdit, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setEnabled(false);

        verticalLayout->addWidget(saveButton);


        formLayout->setLayout(1, QFormLayout::FieldRole, verticalLayout);


        verticalLayout_3->addLayout(formLayout);


        verticalLayout_4->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 540, 21));
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
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionLogout, SIGNAL(triggered()), loginButton, SLOT(animateClick()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Password Manager - Gehrig, Kurt, Philip", 0));
        actionLogout->setText(QApplication::translate("MainWindow", "Logout", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        label_3->setText(QApplication::translate("MainWindow", "Logged in as:", 0));
        nameLabel->setText(QString());
        addButton->setText(QApplication::translate("MainWindow", "Add Account to Database", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Delete Account from Database", 0));
        loginButton->setText(QApplication::translate("MainWindow", "Login", 0));
        logoutButton->setText(QApplication::translate("MainWindow", "Logout", 0));
        staticInfoLabel->setText(QApplication::translate("MainWindow", "Edit Account Information:", 0));
        label_2->setText(QApplication::translate("MainWindow", "Password:", 0));
        label->setText(QApplication::translate("MainWindow", "Username:", 0));
        accountEdit->setText(QString());
        passEdit->setText(QString());
        saveButton->setText(QApplication::translate("MainWindow", "(Save) Update Account Information", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
