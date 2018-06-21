/********************************************************************************
** Form generated from reading UI file 'toolsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLSDIALOG_H
#define UI_TOOLSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ToolsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *FromHoursLineEdit;
    QLabel *label_3;
    QLineEdit *FromMinutesLineEdit;
    QLabel *label_4;
    QLineEdit *FromSecondsLineEdit;
    QLabel *label_5;
    QLineEdit *FromMilisecondsLineEdit;
    QLabel *label_6;
    QLineEdit *ToHoursLineEdit;
    QLabel *label_7;
    QLineEdit *ToMinutesLineEdit;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QLabel *label_9;
    QLineEdit *lineEdit_8;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QCheckBox *MoveAllCheckBox;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QLabel *label_10;
    QLineEdit *TimeDIsplacementLineEdit;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *MOveBackwardPushButton;
    QPushButton *MoveForwardPushButton;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *MergeWithNextPushButton;
    QPushButton *SplitPushButton;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *DecreseTimeGapPushButton;
    QPushButton *IncreseTimeGapPushButton;

    void setupUi(QDialog *ToolsDialog)
    {
        if (ToolsDialog->objectName().isEmpty())
            ToolsDialog->setObjectName(QStringLiteral("ToolsDialog"));
        ToolsDialog->resize(445, 235);
        verticalLayout = new QVBoxLayout(ToolsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(ToolsDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        FromHoursLineEdit = new QLineEdit(ToolsDialog);
        FromHoursLineEdit->setObjectName(QStringLiteral("FromHoursLineEdit"));

        horizontalLayout_2->addWidget(FromHoursLineEdit);

        label_3 = new QLabel(ToolsDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        FromMinutesLineEdit = new QLineEdit(ToolsDialog);
        FromMinutesLineEdit->setObjectName(QStringLiteral("FromMinutesLineEdit"));

        horizontalLayout_2->addWidget(FromMinutesLineEdit);

        label_4 = new QLabel(ToolsDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        FromSecondsLineEdit = new QLineEdit(ToolsDialog);
        FromSecondsLineEdit->setObjectName(QStringLiteral("FromSecondsLineEdit"));

        horizontalLayout_2->addWidget(FromSecondsLineEdit);

        label_5 = new QLabel(ToolsDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        FromMilisecondsLineEdit = new QLineEdit(ToolsDialog);
        FromMilisecondsLineEdit->setObjectName(QStringLiteral("FromMilisecondsLineEdit"));

        horizontalLayout_2->addWidget(FromMilisecondsLineEdit);

        label_6 = new QLabel(ToolsDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        ToHoursLineEdit = new QLineEdit(ToolsDialog);
        ToHoursLineEdit->setObjectName(QStringLiteral("ToHoursLineEdit"));

        horizontalLayout_2->addWidget(ToHoursLineEdit);

        label_7 = new QLabel(ToolsDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        ToMinutesLineEdit = new QLineEdit(ToolsDialog);
        ToMinutesLineEdit->setObjectName(QStringLiteral("ToMinutesLineEdit"));

        horizontalLayout_2->addWidget(ToMinutesLineEdit);

        label_8 = new QLabel(ToolsDialog);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_2->addWidget(label_8);

        lineEdit_7 = new QLineEdit(ToolsDialog);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        horizontalLayout_2->addWidget(lineEdit_7);

        label_9 = new QLabel(ToolsDialog);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_2->addWidget(label_9);

        lineEdit_8 = new QLineEdit(ToolsDialog);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        horizontalLayout_2->addWidget(lineEdit_8);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        MoveAllCheckBox = new QCheckBox(ToolsDialog);
        MoveAllCheckBox->setObjectName(QStringLiteral("MoveAllCheckBox"));

        horizontalLayout_3->addWidget(MoveAllCheckBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        label_10 = new QLabel(ToolsDialog);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_8->addWidget(label_10);

        TimeDIsplacementLineEdit = new QLineEdit(ToolsDialog);
        TimeDIsplacementLineEdit->setObjectName(QStringLiteral("TimeDIsplacementLineEdit"));

        horizontalLayout_8->addWidget(TimeDIsplacementLineEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        MOveBackwardPushButton = new QPushButton(ToolsDialog);
        MOveBackwardPushButton->setObjectName(QStringLiteral("MOveBackwardPushButton"));

        horizontalLayout_9->addWidget(MOveBackwardPushButton);

        MoveForwardPushButton = new QPushButton(ToolsDialog);
        MoveForwardPushButton->setObjectName(QStringLiteral("MoveForwardPushButton"));

        horizontalLayout_9->addWidget(MoveForwardPushButton);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        MergeWithNextPushButton = new QPushButton(ToolsDialog);
        MergeWithNextPushButton->setObjectName(QStringLiteral("MergeWithNextPushButton"));

        horizontalLayout_10->addWidget(MergeWithNextPushButton);

        SplitPushButton = new QPushButton(ToolsDialog);
        SplitPushButton->setObjectName(QStringLiteral("SplitPushButton"));

        horizontalLayout_10->addWidget(SplitPushButton);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        DecreseTimeGapPushButton = new QPushButton(ToolsDialog);
        DecreseTimeGapPushButton->setObjectName(QStringLiteral("DecreseTimeGapPushButton"));

        horizontalLayout_4->addWidget(DecreseTimeGapPushButton);

        IncreseTimeGapPushButton = new QPushButton(ToolsDialog);
        IncreseTimeGapPushButton->setObjectName(QStringLiteral("IncreseTimeGapPushButton"));

        horizontalLayout_4->addWidget(IncreseTimeGapPushButton);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(ToolsDialog);

        QMetaObject::connectSlotsByName(ToolsDialog);
    } // setupUi

    void retranslateUi(QDialog *ToolsDialog)
    {
        ToolsDialog->setWindowTitle(QApplication::translate("ToolsDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ToolsDialog", "From:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ToolsDialog", ":", Q_NULLPTR));
        label_4->setText(QApplication::translate("ToolsDialog", ":", Q_NULLPTR));
        label_5->setText(QApplication::translate("ToolsDialog", ":", Q_NULLPTR));
        label_6->setText(QApplication::translate("ToolsDialog", "To:", Q_NULLPTR));
        label_7->setText(QApplication::translate("ToolsDialog", ":", Q_NULLPTR));
        label_8->setText(QApplication::translate("ToolsDialog", ":", Q_NULLPTR));
        label_9->setText(QApplication::translate("ToolsDialog", ":", Q_NULLPTR));
        MoveAllCheckBox->setText(QApplication::translate("ToolsDialog", "Move All Subtitles", Q_NULLPTR));
        label_10->setText(QApplication::translate("ToolsDialog", "Time of displacement (in seconds):", Q_NULLPTR));
        MOveBackwardPushButton->setText(QApplication::translate("ToolsDialog", "Move Backward", Q_NULLPTR));
        MoveForwardPushButton->setText(QApplication::translate("ToolsDialog", "Move Forward", Q_NULLPTR));
        MergeWithNextPushButton->setText(QApplication::translate("ToolsDialog", "Merge With The Next One", Q_NULLPTR));
        SplitPushButton->setText(QApplication::translate("ToolsDialog", "Split In Two", Q_NULLPTR));
        DecreseTimeGapPushButton->setText(QApplication::translate("ToolsDialog", "Decrese Time Gap", Q_NULLPTR));
        IncreseTimeGapPushButton->setText(QApplication::translate("ToolsDialog", "Increse Time Gap", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ToolsDialog: public Ui_ToolsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLSDIALOG_H
