/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *LoadPushButton;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *SavePushButton;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *TraversePushButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer;
    QPushButton *ToolsPushButton;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(492, 371);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));

        verticalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        LoadPushButton = new QPushButton(centralWidget);
        LoadPushButton->setObjectName(QStringLiteral("LoadPushButton"));

        horizontalLayout_7->addWidget(LoadPushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_6->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);

        SavePushButton = new QPushButton(centralWidget);
        SavePushButton->setObjectName(QStringLiteral("SavePushButton"));
        SavePushButton->setEnabled(false);
        SavePushButton->setCheckable(false);

        horizontalLayout_11->addWidget(SavePushButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_7);


        verticalLayout_7->addLayout(horizontalLayout_11);


        verticalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        TraversePushButton = new QPushButton(centralWidget);
        TraversePushButton->setObjectName(QStringLiteral("TraversePushButton"));
        TraversePushButton->setEnabled(false);

        horizontalLayout_8->addWidget(TraversePushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        horizontalLayout_8->addLayout(horizontalLayout_2);


        verticalLayout_8->addLayout(horizontalLayout_8);


        verticalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer);

        ToolsPushButton = new QPushButton(centralWidget);
        ToolsPushButton->setObjectName(QStringLiteral("ToolsPushButton"));
        ToolsPushButton->setEnabled(false);

        horizontalLayout_14->addWidget(ToolsPushButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_8);


        verticalLayout_9->addLayout(horizontalLayout_14);


        verticalLayout_3->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_15->addItem(verticalSpacer);


        verticalLayout_10->addLayout(horizontalLayout_15);


        verticalLayout_3->addLayout(verticalLayout_10);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Subtitle Editor", Q_NULLPTR));
        LoadPushButton->setText(QApplication::translate("MainWindow", "Load Subtitle File", Q_NULLPTR));
        SavePushButton->setText(QApplication::translate("MainWindow", "Save Subtitle FIle", Q_NULLPTR));
        TraversePushButton->setText(QApplication::translate("MainWindow", "Traverse Subtitles", Q_NULLPTR));
        ToolsPushButton->setText(QApplication::translate("MainWindow", "Other Tools", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
