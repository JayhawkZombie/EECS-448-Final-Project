#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);

    ~Login();

private slots:


    void on_exitButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::Login *ui;
    bool authenticate(std::string, std::string);
};

#endif // LOGIN_H
