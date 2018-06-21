#ifndef TRAVERSEDIALOG_H
#define TRAVERSEDIALOG_H

//#include "globalvariables.h"

#include <QDialog>

namespace Ui {
class TraverseDialog;
}

class TraverseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TraverseDialog(QWidget *parent = 0);
    ~TraverseDialog();

    friend class ToolsDialog;

private slots:
    void on_pushButton_2_clicked();

    void on_PreviousPushButton_clicked();

    void on_NextPushButton_clicked();

    void on_EnterPushButton_clicked();

    void on_DeletePushButton_clicked();

    void on_InsertSubtitlePushButton_clicked();

    void on_JumToTimePushButton_clicked();

private:
    Ui::TraverseDialog *ui;

    void updateWindowElements();

    int getSUbtitleTextLineEditCursorPosition() const;
};

#endif // TRAVERSEDIALOG_H
