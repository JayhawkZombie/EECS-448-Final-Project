/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *userEdit;
    QPushButton *loginButton;
    QPushButton *exitButton;
    QLineEdit *passEdit;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 112);
        verticalLayout_2 = new QVBoxLayout(Login);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(10, 10, 10, 10);
        userEdit = new QLineEdit(Login);
        userEdit->setObjectName(QStringLiteral("userEdit"));

        gridLayout->addWidget(userEdit, 1, 0, 1, 1);

        loginButton = new QPushButton(Login);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        gridLayout->addWidget(loginButton, 2, 0, 1, 1);

        exitButton = new QPushButton(Login);
        exitButton->setObjectName(QStringLiteral("exitButton"));

        gridLayout->addWidget(exitButton, 2, 1, 1, 1);

        passEdit = new QLineEdit(Login);
        passEdit->setObjectName(QStringLiteral("passEdit"));
        passEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passEdit, 1, 1, 1, 1);

        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0));
        userEdit->setText(QApplication::translate("Login", "Username", 0));
        loginButton->setText(QApplication::translate("Login", "Login", 0));
        exitButton->setText(QApplication::translate("Login", "Exit", 0));
        passEdit->setText(QString());
        label_2->setText(QApplication::translate("Login", "Password:", 0));
        label->setText(QApplication::translate("Login", "Username:", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
