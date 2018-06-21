#include "toolsdialog.h"
#include "ui_toolsdialog.h"
#include "globalVariables.h"
#include "SerbianSubtitleReplacements.h"

#include <QMessageBox>

ToolsDialog::ToolsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ToolsDialog) {
    ui->setupUi(this);
    traverseDialog = new TraverseDialog(this);
    traverseDialog->show();
}

ToolsDialog::~ToolsDialog()
{
    delete ui;
}

void ToolsDialog::updateWindowElements() {
    if (ui->MoveAllCheckBox->isChecked()) {
        ui->FromHoursLineEdit->setEnabled(false);
        ui->FromMinutesLineEdit->setEnabled(false);
        ui->FromSecondsLineEdit->setEnabled(false);
        ui->FromMilisecondsLineEdit->setEnabled(false);

        ui->ToHoursLineEdit->setEnabled(false);
        ui->ToMinutesLineEdit->setEnabled(false);
        ui->ToSecondsLineEdit->setEnabled(false);
        ui->ToMilisecondsLineEdit->setEnabled(false);
    } else {
        ui->FromHoursLineEdit->setEnabled(true);
        ui->FromMinutesLineEdit->setEnabled(true);
        ui->FromSecondsLineEdit->setEnabled(true);
        ui->FromMilisecondsLineEdit->setEnabled(true);

        ui->ToHoursLineEdit->setEnabled(true);
        ui->ToMinutesLineEdit->setEnabled(true);
        ui->ToSecondsLineEdit->setEnabled(true);
        ui->ToMilisecondsLineEdit->setEnabled(true);
    }

//    if (GlobalVariables::iter >= GlobalVariables::subtitles->end() - 1) {
//        ui->MergeWithNextPushButton->setEnabled(false);
//    } else {
//        ui->MergeWithNextPushButton->setEnabled(true);
//    }

    // update traverse dialog
    traverseDialog->updateWindowElements();
}

void ToolsDialog::on_MoveAllCheckBox_clicked() {
    updateWindowElements();
}

void ToolsDialog::on_MoveBackwardPushButton_clicked() {

    TimeStamp lowTimeBound;
    TimeStamp highTimeBound;

    bool conversionSucess = true;

    double displacement = ui->TimeDisplacementLineEdit->text().toDouble(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Wrong displacement!", "Displacement must be a floating point value.");
        updateWindowElements();
        return;
    }


    if (!ui->MoveAllCheckBox->isChecked()) {
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

        //get the data
        //string subtitleText = ui->SubtitleTextLineEdit->text().toStdString();

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

        // create time stamps
        lowTimeBound = TimeStamp(previousHours,previousMinutes,previousSeconds,previousMiliseconds);
        highTimeBound = TimeStamp(nextHours,nextMinutes,nextSeconds,nextMiliseconds);
    } else {
        lowTimeBound = TimeStamp(0,0,0,0);
        highTimeBound = (GlobalVariables::subtitles->end() - 1)->getTimeOfRemoval();
    }

    if (lowTimeBound > highTimeBound) {
        QMessageBox::critical(this, "Time Overlaps!", "Low time bound can't be after the high time bound.");
        updateWindowElements();
        return;
    }

    // find subtitles in this range
    auto begin = GlobalVariables::subtitles->begin();
    auto end = GlobalVariables::subtitles->end() - 1;

    while (begin->getTimeOfAppearance() < lowTimeBound) {
        ++begin;
    }


    while (end->getTimeOfRemoval() > highTimeBound) {
        --end;
    }

    // check to see if the subtitles can be moved
    if (begin == GlobalVariables::subtitles->begin()) { //if it's the frist one
        if (displacement > begin->getTimeOfAppearance().getTimeInSeconds()) {
            QMessageBox::critical(this, "Displacement is too big", "Subtitles cannot be moved this much because it would"
                                                                   " cause an overlap with the previous one or"
                                                                   " the time of appearance would be negative");
            updateWindowElements();
            return;
        }
    } else {
        if (displacement > begin->getTimeOfAppearance().getTimeInSeconds() - (begin - 1)->getTimeOfRemoval().getTimeInSeconds()) {
            QMessageBox::critical(this, "Displacement is too big", "Subtitles cannot be moved this much because it would"
                                                                   "cause an overlap with the previous one or"
                                                                   "the time of appearance would be negative");
            updateWindowElements();
            return;
        }
    }

    //everything's ok
    for (auto i = begin; i <= end; ++i) {
        TimeStamp newTimeOfAppearance(i->getTimeOfAppearance().getTimeInSeconds() - displacement);
        TimeStamp newTimeOfRemoval(i->getTimeOfRemoval().getTimeInSeconds() - displacement);

        i->setTimeOfAppearance(newTimeOfAppearance);
        i->setTimeOfRemoval(newTimeOfRemoval);
    }

    QMessageBox::information(this, "Sucess!", "Operation finished sucessfully!");

    updateWindowElements();

}

void ToolsDialog::on_MoveForwardPushButton_clicked() {
    TimeStamp lowTimeBound;
    TimeStamp highTimeBound;

    bool conversionSucess = true;

    double displacement = ui->TimeDisplacementLineEdit->text().toDouble(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Wrong displacement!", "Displacement must be a floating point value.");
        updateWindowElements();
        return;
    }


    if (!ui->MoveAllCheckBox->isChecked()) {
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

        //get the data
        //string subtitleText = ui->SubtitleTextLineEdit->text().toStdString();

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

        // create time stamps
        lowTimeBound = TimeStamp(previousHours,previousMinutes,previousSeconds,previousMiliseconds);
        highTimeBound = TimeStamp(nextHours,nextMinutes,nextSeconds,nextMiliseconds);
    } else {
        lowTimeBound = TimeStamp(0,0,0,0);
        highTimeBound = (GlobalVariables::subtitles->end() - 1)->getTimeOfRemoval();
    }

    if (lowTimeBound > highTimeBound) {
        QMessageBox::critical(this, "Time Overlaps!", "Low time bound can't be after the high time bound.");
        updateWindowElements();
        return;
    }

    // find subtitles in this range
    auto begin = GlobalVariables::subtitles->begin();
    auto end = GlobalVariables::subtitles->end() - 1;

    while (begin->getTimeOfAppearance() < lowTimeBound) {
        ++begin;
    }


    while (end->getTimeOfRemoval() > highTimeBound) {
        --end;
    }

    // check to see if the subtitles can be moved
    if (end != GlobalVariables::subtitles->end() - 1) { // if it's the last one, there's no limit on how much it can be moved
        if ( displacement >
                (end + 1)->getTimeOfAppearance().getTimeInSeconds() - end->getTimeOfAppearance().getTimeInSeconds() ) {
            QMessageBox::critical(this, "Displacement is too big", "Subtitles cannot be moved this much because it would"
                                                                               " cause an overlap with the next one");
            updateWindowElements();
            return;
        }

    }

    // everything's ok
    for (auto i = begin; i <= end; ++i) {
        TimeStamp newTimeOfAppearance(i->getTimeOfAppearance().getTimeInSeconds() + displacement);
        TimeStamp newTimeOfRemoval(i->getTimeOfRemoval().getTimeInSeconds() + displacement);

        i->setTimeOfAppearance(newTimeOfAppearance);
        i->setTimeOfRemoval(newTimeOfRemoval);
    }

    QMessageBox::information(this, "Sucess!", "Operation finished sucessfully!");

    updateWindowElements();
}

void ToolsDialog::on_MergeWithNextPushButton_clicked() {
    if (GlobalVariables::iter == GlobalVariables::subtitles->end() - 1) {
        QMessageBox::critical(this, "Operation failed!", "This is the last subtitle. There's no next one.");
        updateWindowElements();
        return;
    }

    auto thisSubtitle = GlobalVariables::iter;
    auto nextSubtitle = GlobalVariables::iter + 1;

    TimeStamp timeOfAppearance = thisSubtitle->getTimeOfAppearance();
    //TimeStamp timeOfRemoval = nextSubtitle->getTimeOfRemoval();

    string mergedSubtitleText = thisSubtitle->getSubtitleText() + nextSubtitle->getSubtitleText();

    GlobalVariables::iter = GlobalVariables::subtitles->erase(thisSubtitle);

    GlobalVariables::iter->setSubtitleText(mergedSubtitleText);
    GlobalVariables::iter->setTimeOfAppearance(timeOfAppearance);

    updateWindowElements();

}

void ToolsDialog::on_SplitPushButton_clicked() {
    int splitPosition = traverseDialog->getSUbtitleTextLineEditCursorPosition();

    //QMessageBox::information(this, "position", QString::number(splitPosition));

    if (splitPosition >= GlobalVariables::iter->getSubtitleText().length()) {
        QMessageBox::critical(this, "Incorrect cursor position!", "Please place the cursor"
                                                                  " on a valid position  in the original subtitle text.");
        updateWindowElements();
        return;

    }

    string originalSubtitleText = GlobalVariables::iter->getSubtitleText();

    string firstSubtitleTextPart = originalSubtitleText.substr(0, splitPosition);
    string secondSubtitleTextPart = originalSubtitleText.substr(splitPosition + 1);

    TimeStamp firstTimeOfAppearance = GlobalVariables::iter->getTimeOfAppearance();
    TimeStamp secondTimeOfRmoval = GlobalVariables::iter->getTimeOfRemoval();
    TimeStamp middleTime( firstTimeOfAppearance.getTimeInSeconds() +
                ( (secondTimeOfRmoval.getTimeInSeconds() - firstTimeOfAppearance.getTimeInSeconds() ) / 2) );

    GlobalVariables::iter->setTimeOfAppearance(middleTime);
    GlobalVariables::iter->setSubtitleText(secondSubtitleTextPart);

    // save the iterator position
    int position = distance(GlobalVariables::subtitles->begin(), GlobalVariables::iter);

    GlobalVariables::subtitles->insert(GlobalVariables::iter, *new Subtitle(firstSubtitleTextPart, firstTimeOfAppearance, middleTime));

    // restore the iterator position
    GlobalVariables::iter = GlobalVariables::subtitles->begin() + position + 1;

    updateWindowElements();

}

void ToolsDialog::on_DecreseTimeGapPushButton_clicked() {

    bool conversionSucess;

    TimeStamp lowTimeBound;
    TimeStamp highTimeBound;

    double displacement = ui->TimeDisplacementLineEdit->text().toDouble(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Wrong displacement!", "Displacement must be a floating point value.");
        updateWindowElements();
        return;
    }

    if (!ui->MoveAllCheckBox->isChecked()) {
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

        //get the data
        //string subtitleText = ui->SubtitleTextLineEdit->text().toStdString();

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

        // create time stamps
        lowTimeBound = TimeStamp(previousHours,previousMinutes,previousSeconds,previousMiliseconds);
        highTimeBound = TimeStamp(nextHours,nextMinutes,nextSeconds,nextMiliseconds);
    } else {
        lowTimeBound = TimeStamp(0,0,0,0);
        highTimeBound = (GlobalVariables::subtitles->end() - 1)->getTimeOfRemoval();
    }

    if (lowTimeBound > highTimeBound) {
        QMessageBox::critical(this, "Time Overlaps!", "Low time bound can't be after the high time bound.");
        updateWindowElements();
        return;
    }

    // find subtitles in this range
    auto begin = GlobalVariables::subtitles->begin();
    auto end = GlobalVariables::subtitles->end() - 1;

    while (begin->getTimeOfAppearance() < lowTimeBound) {
        ++begin;
    }


    while (end->getTimeOfRemoval() > highTimeBound) {
        --end;
    }

    for (auto i = begin; i <= end; ++i) {

        if (i == GlobalVariables::subtitles->begin() &&
                i->getTimeOfAppearance().getTimeInSeconds() >= displacement) {
            i->setTimeOfAppearance(*new TimeStamp(i->getTimeOfAppearance().getTimeInSeconds() - displacement));
        }

       // i->setTimeOfAppearance(*new TimeStamp(i->getTimeOfAppearance().getTimeInSeconds() + displacement));
        if ( i != GlobalVariables::subtitles->begin() &&
                i->getTimeOfAppearance().getTimeInSeconds() - (i - 1)->getTimeOfRemoval().getTimeInSeconds()
             >= displacement ) {
            i->setTimeOfAppearance(*new TimeStamp(i->getTimeOfAppearance().getTimeInSeconds() - displacement));
        }

       if (i == GlobalVariables::subtitles->end() - 1 ||
                   (i + 1)->getTimeOfAppearance().getTimeInSeconds() - i->getTimeOfRemoval().getTimeInSeconds()
             >= displacement) {
            i->setTimeOfRemoval(*new TimeStamp(i->getTimeOfRemoval().getTimeInSeconds() + displacement));
        }
    }

    QMessageBox::information(this, "Sucess!", "Operation finished sucessfully!");
    updateWindowElements();
}

void ToolsDialog::on_IncreseTimeGapPushButton_clicked() {
    bool conversionSucess;

    TimeStamp lowTimeBound;
    TimeStamp highTimeBound;

    double displacement = ui->TimeDisplacementLineEdit->text().toDouble(&conversionSucess);

    if (!conversionSucess) {
        QMessageBox::critical(this, "Wrong displacement!", "Displacement must be a floating point value.");
        updateWindowElements();
        return;
    }

    if (!ui->MoveAllCheckBox->isChecked()) {
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

        //get the data
        //string subtitleText = ui->SubtitleTextLineEdit->text().toStdString();

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

        // create time stamps
        lowTimeBound = TimeStamp(previousHours,previousMinutes,previousSeconds,previousMiliseconds);
        highTimeBound = TimeStamp(nextHours,nextMinutes,nextSeconds,nextMiliseconds);
    } else {
        lowTimeBound = TimeStamp(0,0,0,0);
        highTimeBound = (GlobalVariables::subtitles->end() - 1)->getTimeOfRemoval();
    }

    if (lowTimeBound > highTimeBound) {
        QMessageBox::critical(this, "Time Overlaps!", "Low time bound can't be after the high time bound.");
        updateWindowElements();
        return;
    }

    // find subtitles in this range
    auto begin = GlobalVariables::subtitles->begin();
    auto end = GlobalVariables::subtitles->end() - 1;

    while (begin->getTimeOfAppearance() < lowTimeBound) {
        ++begin;
    }


    while (end->getTimeOfRemoval() > highTimeBound) {
        --end;
    }

    for (auto i = begin; i <= end; ++i) {
        if (i->getTimeOfAppearance().getTimeInSeconds() + displacement
                < i->getTimeOfRemoval().getTimeInSeconds() - displacement) {
            // if after shrinking time of appearance stays lower than time of removal
            i->setTimeOfAppearance(*new TimeStamp(i->getTimeOfAppearance().getTimeInSeconds() + displacement));
            i->setTimeOfRemoval(*new TimeStamp(i->getTimeOfRemoval().getTimeInSeconds() - displacement));
        }
    }

    QMessageBox::information(this, "Sucess!", "Operation finished sucessfully!");
    updateWindowElements();
}

void ToolsDialog::on_CorrectSubtitlesPushButton_clicked() {
    for (auto i = GlobalVariables::subtitles->begin(); i != GlobalVariables::subtitles->end(); ++i) {
        string tmpText = i->getSubtitleText();
        poop2017cppmodification::replace(tmpText);
        i->setSubtitleText(tmpText);
    }

    updateWindowElements();
}
