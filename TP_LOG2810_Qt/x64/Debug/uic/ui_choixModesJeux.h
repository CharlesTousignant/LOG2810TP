/********************************************************************************
** Form generated from reading UI file 'choixModesJeux.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOIXMODESJEUX_H
#define UI_CHOIXMODESJEUX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QPushButton *buttonSuggestion;
    QPushButton *buttonCorrection;
    QPushButton *buttonSuggestCorrect;
    QPushButton *buttonExit;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        buttonSuggestion = new QPushButton(Dialog);
        buttonGroup = new QButtonGroup(Dialog);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(buttonSuggestion);
        buttonSuggestion->setObjectName(QString::fromUtf8("buttonSuggestion"));

        gridLayout->addWidget(buttonSuggestion, 0, 0, 1, 1);

        buttonCorrection = new QPushButton(Dialog);
        buttonGroup->addButton(buttonCorrection);
        buttonCorrection->setObjectName(QString::fromUtf8("buttonCorrection"));

        gridLayout->addWidget(buttonCorrection, 0, 1, 1, 1);

        buttonSuggestCorrect = new QPushButton(Dialog);
        buttonGroup->addButton(buttonSuggestCorrect);
        buttonSuggestCorrect->setObjectName(QString::fromUtf8("buttonSuggestCorrect"));

        gridLayout->addWidget(buttonSuggestCorrect, 0, 2, 1, 1);

        buttonExit = new QPushButton(Dialog);
        buttonGroup->addButton(buttonExit);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));

        gridLayout->addWidget(buttonExit, 1, 1, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        buttonSuggestion->setText(QCoreApplication::translate("Dialog", "Suggestion", nullptr));
        buttonCorrection->setText(QCoreApplication::translate("Dialog", "Correction", nullptr));
        buttonSuggestCorrect->setText(QCoreApplication::translate("Dialog", "Suggestion + Correction", nullptr));
        buttonExit->setText(QCoreApplication::translate("Dialog", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOIXMODESJEUX_H
