#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<QException>
#include<QSqlDatabase>
#include"main.h"

namespace Ui {
class MainWindow;
}

class loginException:public QException{
public:
    //错误类型
    static const errorType accountError=0;
    static const errorType accountNotFound=1;
    static const errorType passwordError=2;
private:
    errorType kind;//登录时哪一信息发生错误
             //0卡号错误，1卡号不存在，2密码错误
public:
    explicit loginException(int kind);
    QString what();

};

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QSqlDatabase db;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createConnect(bool isExist);
    void updateInfo();

private:
    Ui::MainWindow *ui;

signals:
    void paySignal();
private slots:
    void buttonLogin_clicked();
    void buttonRegister_clicked();
    void buttonManage_clicked();
    void getPaySignal();
};

#endif // MAINWINDOW_H
