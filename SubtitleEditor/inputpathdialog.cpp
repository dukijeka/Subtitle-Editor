#include "inputpathdialog.h"
#include "ui_inputpathdialog.h"

InputPathDialog::InputPathDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputPathDialog)
{
    ui->setupUi(this);
}

InputPathDialog::~InputPathDialog()
{
    delete ui;
}
