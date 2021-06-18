/********************************************************************************
** Form generated from reading UI file 'JeuxInstructif.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JEUXINSTRUCTIF_H
#define UI_JEUXINSTRUCTIF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TP_LOG2810_QtClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *listWidget;
    QPushButton *pushButton;
    QLabel *label;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TP_LOG2810_QtClass)
    {
        if (TP_LOG2810_QtClass->objectName().isEmpty())
            TP_LOG2810_QtClass->setObjectName(QString::fromUtf8("TP_LOG2810_QtClass"));
        TP_LOG2810_QtClass->resize(795, 562);
        centralWidget = new QWidget(TP_LOG2810_QtClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(18);
        listWidget->setFont(font);

        gridLayout->addWidget(listWidget, 2, 1, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setPointSize(10);
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setUnderline(true);
        font2.setWeight(50);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font3;
        font3.setPointSize(19);
        textEdit->setFont(font3);
        textEdit->setMouseTracking(false);
        textEdit->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(textEdit, 2, 0, 1, 1);

        TP_LOG2810_QtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TP_LOG2810_QtClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 795, 21));
        TP_LOG2810_QtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TP_LOG2810_QtClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TP_LOG2810_QtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TP_LOG2810_QtClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TP_LOG2810_QtClass->setStatusBar(statusBar);

        retranslateUi(TP_LOG2810_QtClass);

        QMetaObject::connectSlotsByName(TP_LOG2810_QtClass);
    } // setupUi

    void retranslateUi(QMainWindow *TP_LOG2810_QtClass)
    {
        TP_LOG2810_QtClass->setWindowTitle(QCoreApplication::translate("TP_LOG2810_QtClass", "TP_LOG2810_Qt", nullptr));
        pushButton->setText(QCoreApplication::translate("TP_LOG2810_QtClass", "Retour", nullptr));
        label->setText(QCoreApplication::translate("TP_LOG2810_QtClass", "Jeux instructif", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TP_LOG2810_QtClass: public Ui_TP_LOG2810_QtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JEUXINSTRUCTIF_H
