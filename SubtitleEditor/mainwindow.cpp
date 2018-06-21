#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalVariables.h"
#include "utilities.h"
#include "traversedialog.h"
#include "toolsdialog.h"
#include "SRT.h"
#include "MicroDVD.h"
#include "MPlayer.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDir>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->statusBar->showMessage("No File Loaded");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Load_pushButton_clicked() {}



void MainWindow::on_LoadPushButton_clicked()
{
   QString filter = "All Supported Types (*.srt *.sub *.txt);;SubRip Subtitle (*.srt);;MPlayer Subtitle (*.sub);;MicroDVD Subtititle (*.sub *.txt)";
   GlobalVariables::inFilePath = QFileDialog::getOpenFileName(this, "Open a Subtitle File", QDir::currentPath(), filter);
   if (GlobalVariables::inFilePath != nullptr) {
       // determine subtitle format
       if (GlobalVariables::inFilePath.endsWith(".srt")) { // it's SubRip
            GlobalVariables::inSubtitle = new SRT();
       } else if (GlobalVariables::inFilePath.endsWith(".txt")) { //it's MicroDVD
            GlobalVariables::inSubtitle = new MicroDVD();
       } else {
           bool microDVD;
            try {
                microDVD = isItMicroDVD(GlobalVariables::inFilePath);
            } catch (CannotOpenFileException ce) {
               QMessageBox::warning(this, "Error", QString::fromStdString(ce.what()));
            }

           if (microDVD) { //it's MicroDVD
               GlobalVariables::inSubtitle = new MicroDVD();
           } else { //it's MPlayer
               GlobalVariables::inSubtitle = new MPlayer();
           }
       }

       // open and load file
       try {
          GlobalVariables::subtitles = GlobalVariables::inSubtitle->load(GlobalVariables::inFilePath.toStdString());
       } catch (CannotOpenFileException ce) {
           QMessageBox::warning(this, "Error", QString::fromStdString(ce.what()));
       }

       QMessageBox::information(this, "File Loaded", "Loading sucessfuly completed!");

       ui->SavePushButton->setEnabled(true);
       ui->TraversePushButton->setEnabled(true);
       ui->ToolsPushButton->setEnabled(true);

       ui->statusBar->showMessage("File Loaded");

   }
}

void MainWindow::on_MainWindow_destroyed()
{
    delete GlobalVariables::inSubtitle;
}

void MainWindow::on_SavePushButton_clicked()
{
    QString filter = "SubRip Subtitle (*.srt);;MPlayer Subtitle (*.sub);;MicroDVD Subtititle (*.txt)";
    GlobalVariables::outFilePath = QFileDialog::getSaveFileName(this, "Save As", QDir::currentPath(), filter);
    if (GlobalVariables::outFilePath == nullptr) return;

    // determine subtitle format
    if (GlobalVariables::outFilePath.endsWith(".srt")) { // it's SubRip
         GlobalVariables::outSubtitle = new SRT();
    } else if (GlobalVariables::outFilePath.endsWith(".txt")) { //it's MicroDVD
         GlobalVariables::outSubtitle = new MicroDVD();
    } else { // it's Mplayer
            GlobalVariables::outSubtitle = new MPlayer();
    }

    // save file
    try {
       GlobalVariables::outSubtitle->save(GlobalVariables::outFilePath.toStdString(), *GlobalVariables::subtitles);
    } catch (CannotWriteFileException ce) {
        QMessageBox::warning(this, "Error", QString::fromStdString(ce.what()));
    }

    QMessageBox::information(this, "Sucess" ,"Action Completed Successfully");

//    try {
//        GlobalVariables::InSubtitle->save(GlobalVariables::outFilePath.toStdString(), *GlobalVariables::subtitles);
//    } catch (CannotWriteFileException ce) {
//        QMessageBox::warning(this, "Error", QString::fromStdString(ce.what()));
//    }
}

void MainWindow::on_TraversePushButton_clicked() {
    TraverseDialog traverseDialog;
    traverseDialog.setModal(true);
    traverseDialog.exec();
}

void MainWindow::on_ToolsPushButton_clicked() {
    ToolsDialog toolsDialog;
    toolsDialog.setModal(false);
    toolsDialog.exec();
}
