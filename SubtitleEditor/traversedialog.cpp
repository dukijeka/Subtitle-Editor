#include "traversedialog.h"
#include "ui_traversedialog.h"
#include "globalVariables.h"
#include "toolsdialog.h"

#include <QMessageBox>

TraverseDialog::TraverseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TraverseDialog)
{
    ui->setupUi(this);
    GlobalVariables::iter = GlobalVariables::subtitles->begin();
    updateWindowElements();
}

TraverseDialog::~TraverseDialog() {
    delete ui;
}

// fills the text fields with data from GlobalVariables::iter
void TraverseDialog::updateWindowElements() {
    // get the data about the subtitle
    string subtitleText = GlobalVariables::iter->getSubtitleText();

    string FromHours = to_string( GlobalVariables::iter->getTimeOfAppearance().getHours() );
    string FromMinutes = to_string( GlobalVariables::iter->getTimeOfAppearance().getMinutes() );
    string FromSeconds = to_string( GlobalVariables::iter->getTimeOfAppearance().getSeconds() );
    string FromMiliseconds = to_string( GlobalVariables::iter->getTimeOfAppearance().getMiliseconds() );


    string ToHours = to_string( GlobalVariables::iter->getTimeOfRemoval().getHours() );
    string ToMinutes = to_string( GlobalVariables::iter->getTimeOfRemoval().getMinutes() );
    string ToSeconds = to_string( GlobalVariables::iter->getTimeOfRemoval().getSeconds() );
    string ToMiliseconds = to_string( GlobalVariables::iter->getTimeOfRemoval().getMiliseconds() );


    // add it to text fields
    ui->SubtitleTextLineEdit->setText(QString::fromStdString(subtitleText));

    ui->FromHoursLineEdit->setText(QString::fromStdString(FromHours));
    ui->FromMinutesLineEdit->setText(QString::fromStdString(FromMinutes));
    ui->FromSecondsLineEdit->setText(QString::fromStdString(FromSeconds));
    ui->FromMilisecondsLineEdit->setText(QString::fromStdString(FromMiliseconds));


    ui->ToHoursLineEdit->setText(QString::fromStdString(ToHours));
    ui->ToMinutesLineEdit->setText(QString::fromStdString(ToMinutes));
    ui->ToSecondsLineEdit->setText(QString::fromStdString(ToSeconds));
    ui->ToMilisecondsLineEdit->setText(QString::fromStdString(ToMiliseconds));

    // update buttons
    if (GlobalVariables::subtitles->size() == 1) {
        ui->NextPushButton->setDisabled(true);
        ui->PreviousPushButton->setDisabled(true);
        return;
    }

    if (GlobalVariables::iter == GlobalVariables::subtitles->begin()) {
        ui->PreviousPushButton->setEnabled(false);
        ui->NextPushButton->setEnabled(true);
    } else if (GlobalVariables::iter == GlobalVariables::subtitles->end() - 1){
        ui->NextPushButton->setEnabled(false);
        ui->PreviousPushButton->setEnabled(true);
    } else {
        ui->PreviousPushButton->setEnabled(true);
        ui->NextPushButton->setEnabled(true);
    }


}

int TraverseDialog::getSUbtitleTextLineEditCursorPosition() const {
    return ui->SubtitleTextLineEdit->cursorPosition();
}

void TraverseDialog::on_pushButton_2_clicked() {}

void TraverseDialog::on_PreviousPushButton_clicked() {
    --GlobalVariables::iter;

    updateWindowElements();
}

void TraverseDialog::on_NextPushButton_clicked() {
    ++GlobalVariables::iter;

    updateWindowElements();
}

void TraverseDialog::on_EnterPushButton_clicked() {
    // check if all fields are vaild
    if (ui->FromHoursLineEdit->text() == ""
            || ui->FromMinutesLineEdit->text() == ""
            || ui->FromSecondsLineEdit->text() == ""
            || ui->FromMilisecondsLineEdit->text() == ""
            || ui->ToHoursLineEdit->text() == ""
            || ui->ToSecondsLineEdit->text() == ""
            || ui->ToMilisecondsLineEdit->text() == "") {
        QMessageBox::critical(this, "Incomplete times!", "Please enter times of appearence and/or removal.");
        updateWindowElements();
        return;
    }

    bool conversionSucess = true;
    //get the data
    string subtitleText = ui->SubtitleTextLineEdit->text().toStdString();

    int previousHours = ui->FromHoursLineEdit->text().toInt(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }

    int previousMinutes = ui->FromMinutesLineEdit->text().toInt(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }

    int previousSeconds = ui->FromSecondsLineEdit->text().toInt(&conversionSucess);
    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }

    int previousMiliseconds = ui->FromMilisecondsLineEdit->text().toInt(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }

    int nextHours = ui->ToHoursLineEdit->text().toInt(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }

    int nextMinutes = ui->ToMinutesLineEdit->text().toInt(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }

    int nextSeconds = ui->ToSecondsLineEdit->text().toInt(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }

    int nextMiliseconds = ui->ToMilisecondsLineEdit->text().toInt(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }


    //create Timestamps
    TimeStamp timeOfAppearence(previousHours,previousMinutes,previousSeconds,previousMiliseconds);
    TimeStamp timeOfRemoval(nextHours,nextMinutes,nextSeconds,nextMiliseconds);

    if (timeOfAppearence > timeOfRemoval) {
        QMessageBox::critical(this, "Time Overlaps!", "Time of appearence cannot be after time of removal.");
        updateWindowElements();
        return;
    }

    if (GlobalVariables::iter == GlobalVariables::subtitles->begin()
            && (GlobalVariables::iter + 1) != GlobalVariables::subtitles->end()) { // first subtitle, but not the only one
        if (timeOfRemoval
                > (GlobalVariables::iter + 1)->getTimeOfAppearance()) { // does it overlap?
            QMessageBox::critical(this, "Time Overlaps!", "Given time of removal overlaps with the next subtitle. "
                                                          "Please enter valid data!");
            updateWindowElements();
            return;
        }
    } else if (GlobalVariables::iter != GlobalVariables::subtitles->begin()
               && (GlobalVariables::iter + 1) == GlobalVariables::subtitles->end()) {// last subtitle, but no the only one
        if (timeOfAppearence
                < (GlobalVariables::iter - 1)->getTimeOfRemoval()) { // does it overlap?
            QMessageBox::critical(this, "Time Overlaps!", "Given time of appearence overlaps with the previous subtitle. "
                                                          "Please enter valid data!");
            updateWindowElements();
            return;
        }
    } else if (GlobalVariables::subtitles->size() > 1) { // if there's more then one element
        if (timeOfRemoval
                > (GlobalVariables::iter + 1)->getTimeOfAppearance()) { // does it overlap?
            QMessageBox::critical(this, "Time Overlaps!", "Given time of removal overlaps with the next subtitle. "
                                                          "Please enter valid data!");
            updateWindowElements();
            return;
        }

        if (timeOfAppearence
                < (GlobalVariables::iter - 1)->getTimeOfRemoval()) { // does it overlap?
            QMessageBox::critical(this, "Time Overlaps!", "Given time of appearence overlaps with the previous subtitle. "
                                                          "Please enter valid data!");
            updateWindowElements();
            return;
        }
    }

    // it doesn't overlap yaaay!

    GlobalVariables::iter->setTimeOfAppearance(timeOfAppearence);
    GlobalVariables::iter->setTimeOfRemoval(timeOfRemoval);
    GlobalVariables::iter->setSubtitleText(subtitleText);


    QMessageBox::information(this, "Sucess!", "Subtitle sucessfully updated!");


}

void TraverseDialog::on_DeletePushButton_clicked() {
    if (GlobalVariables::subtitles->size() == 1) {
        QMessageBox::critical(this, "Operation Failed!", "You cannot delete the only subtitle!");
        return;
    }

    GlobalVariables::iter = GlobalVariables::subtitles->erase(GlobalVariables::iter);

    if (GlobalVariables::iter == GlobalVariables::subtitles->end()) {
        --GlobalVariables::iter;
        ui->NextPushButton->setEnabled(false);
    }

    QMessageBox::information(this, "Sucess!", "Operation finished sucessfully!");
    updateWindowElements();
}

void TraverseDialog::on_InsertSubtitlePushButton_clicked(){
    string subtitleText = ui->SubtitleTextLineEdit->text().toStdString();

    if (GlobalVariables::iter == GlobalVariables::subtitles->end() - 1) { //if it's the last one, append it to the end
        TimeStamp timeStamp = GlobalVariables::iter->getTimeOfRemoval();

        GlobalVariables::subtitles->push_back(*new Subtitle(subtitleText, timeStamp,
            *new TimeStamp(timeStamp.getHours(),timeStamp.getMinutes(),timeStamp.getSeconds() + 1, 0)));
        GlobalVariables::iter = GlobalVariables::subtitles->end() - 1;
        updateWindowElements();

        return;
    }

    TimeStamp begining = GlobalVariables::iter->getTimeOfRemoval();
    TimeStamp end = (GlobalVariables::iter + 1)->getTimeOfAppearance();

    if (begining >= end) {
        if (GlobalVariables::subtitles->size() == 1) {
            QMessageBox::critical(this, "Operation Failed!", "Time between this subtitle and the next one is 0. Please "
                                                             "make a time gap between these two by editing their times.");
            return;
        }
    }

    // save the iterator position
    int position = distance(GlobalVariables::subtitles->begin(), GlobalVariables::iter);

    GlobalVariables::subtitles->insert(GlobalVariables::iter + 1, *new Subtitle(subtitleText, begining, end));

    // restore the iterator position
    GlobalVariables::iter = GlobalVariables::subtitles->begin() + position + 1;

    QMessageBox::information(this, "Sucess!", "Operation finished sucessfully!");

    updateWindowElements();
}

void TraverseDialog::on_JumToTimePushButton_clicked() {
    bool conversionSucess;

    TimeStamp lowTimeBound;


    // check if all fields are vaild
    if (ui->FromHoursLineEdit->text() == ""
            || ui->FromMinutesLineEdit->text() == ""
            || ui->FromSecondsLineEdit->text() == ""
            || ui->FromMilisecondsLineEdit->text() == "") {
        QMessageBox::critical(this, "Incomplete times!", "Please fill \"From\" time to jump to it!");
        updateWindowElements();
        return;
    }



    int previousHours = ui->FromHoursLineEdit->text().toInt(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }

    int previousMinutes = ui->FromMinutesLineEdit->text().toInt(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }

    int previousSeconds = ui->FromSecondsLineEdit->text().toInt(&conversionSucess);
    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }

    int previousMiliseconds = ui->FromMilisecondsLineEdit->text().toInt(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Incomplete times!", "Times must be numbers");
        updateWindowElements();
        return;
    }

    // create time stamp
    lowTimeBound = TimeStamp(previousHours,previousMinutes,previousSeconds,previousMiliseconds);

    if (lowTimeBound > (GlobalVariables::subtitles->end() - 1)->getTimeOfAppearance()
         || lowTimeBound.getTimeInSeconds() < 0) {
         QMessageBox::critical(this, "Time Out Of Bound", "Given time is out of bound!");
         updateWindowElements();
         return;
    }

    // find subtitles in this range
    auto begin = GlobalVariables::subtitles->begin();

    while (begin->getTimeOfAppearance() < lowTimeBound) {
        ++begin;
    }

    GlobalVariables::iter = begin;


    updateWindowElements();
}
