#ifndef INPUTPATHDIALOG_H
#define INPUTPATHDIALOG_H

#include <QDialog>

namespace Ui {
class InputPathDialog;
}

class InputPathDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputPathDialog(QWidget *parent = 0);
    ~InputPathDialog();

private:
    Ui::InputPathDialog *ui;
};

#endif // INPUTPATHDIALOG_H
