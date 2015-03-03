#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpwindow.h"
#include <QWindow>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainMenu->show();
//    HelpWindow myHelp;

    //Initializization of attributes
    currentPassword    = "password";
    currentUsername    = "admin";
    adminAccessGranted = false;
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_push_button_viewListOfWineries_clicked()
{
    ui->mainMenu->hide();

    ui->viewListOfWineries->show();
}

void MainWindow::on_pushButton_back_viewList_clicked()
{
    ui->viewListOfWineries->hide();

    ui->mainMenu->show();
}

void MainWindow::on_pushButton_backPlanTrip_clicked()
{
    ui->planATrip->hide();
    ui->mainMenu->show();
}

void MainWindow::on_pushButton_planTrip_clicked()
{
    ui->mainMenu->hide();
    ui->planATrip->show();
}

void MainWindow::on_pushButton_backTourAndPurchase_clicked()
{
    ui->tourWineriesAndPurchase->hide();
    ui->mainMenu->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    //Back button in admin login window
    ui->adminLogin->hide();
    ui->mainMenu->show();
    ui->lineEdit_password->clear();
    ui->lineEdit_username->clear();
}

void MainWindow::on_pushButton_Admin_clicked()
{
    ui->mainMenu->hide();
    ui->adminLogin->show();
}

void MainWindow::on_pushButton_adminLogin_clicked()
{

   QString password = ui->lineEdit_password->text();
   QString username = ui->lineEdit_username->text();


   bool passwordCorrect            = password == currentPassword;
   bool usernameCorrect            = username == currentUsername;
   bool passwordAndUserNameCorrect = (password != currentPassword) ||
                                     (username != currentUsername);

   if(passwordAndUserNameCorrect)
   {
       QMessageBox::information(this, "Login Error", "Incorrect Username or Password");
       ui->lineEdit_password->clear();
       ui->lineEdit_username->clear();
   }
//   if(passwordCorrect)
//   {
//       QMessageBox::information(this, "Login Error","Incorrect Password");
//   }
//   else if(!usernameCorrect)
//   {
//       QMessageBox::information(this, "Login Error", "Incorrect Password");
//   }
   else if(passwordCorrect && usernameCorrect)
   {
       QMessageBox::information(this, "Welcome", "Access granted");
       adminAccessGranted = true;

       ui->adminLogin->hide();
       ui->afterAdminLogin->show();
       ui->lineEdit_password->clear();
       ui->lineEdit_username->clear();
   }

}

void MainWindow::on_pushButton_adminLogout_clicked()
{
    adminAccessGranted = false;
    ui->afterAdminLogin->hide();
    ui->adminLogin->show();
}

void MainWindow::on_pushButton_tourAndPurchase_clicked()
{
    ui->mainMenu->hide();
    ui->tourWineriesAndPurchase->show();
}
