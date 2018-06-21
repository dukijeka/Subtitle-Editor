#ifndef TOOLSDIALOG_H
#define TOOLSDIALOG_H

#include "traversedialog.h"

#include <QDialog>

namespace Ui {
class ToolsDialog;
}

class ToolsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ToolsDialog(QWidget *parent = 0);
    ~ToolsDialog();

    friend class TraverseDialog;

private slots:
    void on_MoveAllCheckBox_clicked();

    void on_MoveBackwardPushButton_clicked();

    void on_MoveForwardPushButton_clicked();

    void on_MergeWithNextPushButton_clicked();

    void on_SplitPushButton_clicked();

    void on_DecreseTimeGapPushButton_clicked();

    void on_IncreseTimeGapPushButton_clicked();

    void on_CorrectSubtitlesPushButton_clicked();

private:
    Ui::ToolsDialog *ui;
    TraverseDialog* traverseDialog;
    void updateWindowElements();
};

#endif // TOOLSDIALOG_H
