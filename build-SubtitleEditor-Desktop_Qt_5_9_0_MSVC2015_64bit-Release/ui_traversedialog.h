/********************************************************************************
** Form generated from reading UI file 'traversedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVERSEDIALOG_H
#define UI_TRAVERSEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TraverseDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *FromHoursLineEdit;
    QLabel *label_2;
    QLineEdit *FromMinutesLineEdit;
    QLabel *label_3;
    QLineEdit *FromSecondsLineEdit;
    QLabel *label_8;
    QLineEdit *FromMilisecondsLineEdit;
    QLabel *label_4;
    QLineEdit *ToHoursLineEdit;
    QLabel *label_5;
    QLineEdit *ToMinutesLineEdit;
    QLabel *label_6;
    QLineEdit *ToSecondsLineEdit;
    QLabel *label_7;
    QLineEdit *ToMilisecondsLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *SubtitleTextLineEdit;
    QPushButton *EnterPushButton;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *PreviousPushButton;
    QPushButton *NextPushButton;
    QPushButton *InsertSubtitlePushButton;
    QPushButton *DeletePushButton;

    void setupUi(QDialog *TraverseDialog)
    {
        if (TraverseDialog->objectName().isEmpty())
            TraverseDialog->setObjectName(QStringLiteral("TraverseDialog"));
        TraverseDialog->resize(475, 197);
        verticalLayout_3 = new QVBoxLayout(TraverseDialog);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(TraverseDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        FromHoursLineEdit = new QLineEdit(TraverseDialog);
        FromHoursLineEdit->setObjectName(QStringLiteral("FromHoursLineEdit"));

        horizontalLayout_4->addWidget(FromHoursLineEdit);

        label_2 = new QLabel(TraverseDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        FromMinutesLineEdit = new QLineEdit(TraverseDialog);
        FromMinutesLineEdit->setObjectName(QStringLiteral("FromMinutesLineEdit"));

        horizontalLayout_4->addWidget(FromMinutesLineEdit);

        label_3 = new QLabel(TraverseDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        FromSecondsLineEdit = new QLineEdit(TraverseDialog);
        FromSecondsLineEdit->setObjectName(QStringLiteral("FromSecondsLineEdit"));

        horizontalLayout_4->addWidget(FromSecondsLineEdit);

        label_8 = new QLabel(TraverseDialog);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        FromMilisecondsLineEdit = new QLineEdit(TraverseDialog);
        FromMilisecondsLineEdit->setObjectName(QStringLiteral("FromMilisecondsLineEdit"));

        horizontalLayout_4->addWidget(FromMilisecondsLineEdit);

        label_4 = new QLabel(TraverseDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        ToHoursLineEdit = new QLineEdit(TraverseDialog);
        ToHoursLineEdit->setObjectName(QStringLiteral("ToHoursLineEdit"));

        horizontalLayout_4->addWidget(ToHoursLineEdit);

        label_5 = new QLabel(TraverseDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        ToMinutesLineEdit = new QLineEdit(TraverseDialog);
        ToMinutesLineEdit->setObjectName(QStringLiteral("ToMinutesLineEdit"));

        horizontalLayout_4->addWidget(ToMinutesLineEdit);

        label_6 = new QLabel(TraverseDialog);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        ToSecondsLineEdit = new QLineEdit(TraverseDialog);
        ToSecondsLineEdit->setObjectName(QStringLiteral("ToSecondsLineEdit"));

        horizontalLayout_4->addWidget(ToSecondsLineEdit);

        label_7 = new QLabel(TraverseDialog);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        ToMilisecondsLineEdit = new QLineEdit(TraverseDialog);
        ToMilisecondsLineEdit->setObjectName(QStringLiteral("ToMilisecondsLineEdit"));

        horizontalLayout_4->addWidget(ToMilisecondsLineEdit);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        SubtitleTextLineEdit = new QLineEdit(TraverseDialog);
        SubtitleTextLineEdit->setObjectName(QStringLiteral("SubtitleTextLineEdit"));

        horizontalLayout_2->addWidget(SubtitleTextLineEdit);

        EnterPushButton = new QPushButton(TraverseDialog);
        EnterPushButton->setObjectName(QStringLiteral("EnterPushButton"));

        horizontalLayout_2->addWidget(EnterPushButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        PreviousPushButton = new QPushButton(TraverseDialog);
        PreviousPushButton->setObjectName(QStringLiteral("PreviousPushButton"));
        PreviousPushButton->setEnabled(true);

        horizontalLayout_3->addWidget(PreviousPushButton);

        NextPushButton = new QPushButton(TraverseDialog);
        NextPushButton->setObjectName(QStringLiteral("NextPushButton"));

        horizontalLayout_3->addWidget(NextPushButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        InsertSubtitlePushButton = new QPushButton(TraverseDialog);
        InsertSubtitlePushButton->setObjectName(QStringLiteral("InsertSubtitlePushButton"));

        verticalLayout_3->addWidget(InsertSubtitlePushButton);

        DeletePushButton = new QPushButton(TraverseDialog);
        DeletePushButton->setObjectName(QStringLiteral("DeletePushButton"));

        verticalLayout_3->addWidget(DeletePushButton);


        retranslateUi(TraverseDialog);

        QMetaObject::connectSlotsByName(TraverseDialog);
    } // setupUi

    void retranslateUi(QDialog *TraverseDialog)
    {
        TraverseDialog->setWindowTitle(QApplication::translate("TraverseDialog", "Traverse", Q_NULLPTR));
        label->setText(QApplication::translate("TraverseDialog", "From:", Q_NULLPTR));
        label_2->setText(QApplication::translate("TraverseDialog", ":", Q_NULLPTR));
        label_3->setText(QApplication::translate("TraverseDialog", ":", Q_NULLPTR));
        label_8->setText(QApplication::translate("TraverseDialog", ":", Q_NULLPTR));
        label_4->setText(QApplication::translate("TraverseDialog", "To:", Q_NULLPTR));
        label_5->setText(QApplication::translate("TraverseDialog", ":", Q_NULLPTR));
        label_6->setText(QApplication::translate("TraverseDialog", ":", Q_NULLPTR));
        label_7->setText(QApplication::translate("TraverseDialog", ":", Q_NULLPTR));
        EnterPushButton->setText(QApplication::translate("TraverseDialog", "Enter", Q_NULLPTR));
        PreviousPushButton->setText(QApplication::translate("TraverseDialog", "<<", Q_NULLPTR));
        NextPushButton->setText(QApplication::translate("TraverseDialog", ">>", Q_NULLPTR));
        InsertSubtitlePushButton->setText(QApplication::translate("TraverseDialog", "Insert New Subtitle Here", Q_NULLPTR));
        DeletePushButton->setText(QApplication::translate("TraverseDialog", "Delete This Subtitle", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TraverseDialog: public Ui_TraverseDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVERSEDIALOG_H
