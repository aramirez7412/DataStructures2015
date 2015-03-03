#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_push_button_viewListOfWineries_clicked();

    void on_pushButton_back_viewList_clicked();

    void on_pushButton_backPlanTrip_clicked();

    void on_pushButton_planTrip_clicked();

    void on_pushButton_backTourAndPurchase_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_Admin_clicked();

    void on_pushButton_adminLogin_clicked();

    void on_pushButton_adminLogout_clicked();

    void on_pushButton_tourAndPurchase_clicked();

private:
    Ui::MainWindow *ui;

    QString currentPassword;
    QString currentUsername;

    bool adminAccessGranted;
};

#endif // MAINWINDOW_H
