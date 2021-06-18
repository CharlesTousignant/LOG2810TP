/********************************************************************************
** Form generated from reading UI file 'choixApplication.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOIXAPPLICATION_H
#define UI_CHOIXAPPLICATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_choixApplication
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *boutonJeuInstructif;
    QPushButton *boutonExploration;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(582, 550);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(23);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 1, 1, 2);

        boutonJeuInstructif = new QPushButton(Dialog);
        boutonJeuInstructif->setObjectName(QString::fromUtf8("boutonJeuInstructif"));
        QFont font1;
        font1.setPointSize(11);
        boutonJeuInstructif->setFont(font1);

        gridLayout->addWidget(boutonJeuInstructif, 2, 2, 1, 1);

        boutonExploration = new QPushButton(Dialog);
        boutonExploration->setObjectName(QString::fromUtf8("boutonExploration"));
        boutonExploration->setFont(font1);

        gridLayout->addWidget(boutonExploration, 2, 1, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Veillez choisir un mode test", nullptr));
        boutonJeuInstructif->setText(QCoreApplication::translate("Dialog", "Jeu instructif", nullptr));
        boutonExploration->setText(QCoreApplication::translate("Dialog", "Exploration du monde", nullptr));
    } // retranslateUi

};

namespace Ui {
    //class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOIXAPPLICATION_H
