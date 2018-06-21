#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "traversedialog.h"

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
    void on_Load_pushButton_clicked();

    void on_LoadPushButton_clicked();

    void on_MainWindow_destroyed();

    void on_SavePushButton_clicked();

    void on_TraversePushButton_clicked();

    void on_ToolsPushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
