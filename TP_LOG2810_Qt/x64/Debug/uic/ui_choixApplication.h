/********************************************************************************
** Form generated from reading UI file 'choixApplication.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
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

class Ui_DialogChoixApplication
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *boutonJeuInstructif;
    QPushButton *boutonExploration;

    void setupUi(QDialog *DialogChoixApplication)
    {
        if (DialogChoixApplication->objectName().isEmpty())
            DialogChoixApplication->setObjectName(QString::fromUtf8("DialogChoixApplication"));
        DialogChoixApplication->resize(582, 550);
        gridLayout = new QGridLayout(DialogChoixApplication);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DialogChoixApplication);
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

        boutonJeuInstructif = new QPushButton(DialogChoixApplication);
        boutonJeuInstructif->setObjectName(QString::fromUtf8("boutonJeuInstructif"));
        QFont font1;
        font1.setPointSize(11);
        boutonJeuInstructif->setFont(font1);

        gridLayout->addWidget(boutonJeuInstructif, 2, 2, 1, 1);

        boutonExploration = new QPushButton(DialogChoixApplication);
        boutonExploration->setObjectName(QString::fromUtf8("boutonExploration"));
        boutonExploration->setFont(font1);

        gridLayout->addWidget(boutonExploration, 2, 1, 1, 1);


        retranslateUi(DialogChoixApplication);

        QMetaObject::connectSlotsByName(DialogChoixApplication);
    } // setupUi

    void retranslateUi(QDialog *DialogChoixApplication)
    {
        DialogChoixApplication->setWindowTitle(QCoreApplication::translate("DialogChoixApplication", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogChoixApplication", "Veuillez choisir une application", nullptr));
        boutonJeuInstructif->setText(QCoreApplication::translate("DialogChoixApplication", "Jeu instructif", nullptr));
        boutonExploration->setText(QCoreApplication::translate("DialogChoixApplication", "Exploration du monde", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogChoixApplication: public Ui_DialogChoixApplication {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOIXAPPLICATION_H
