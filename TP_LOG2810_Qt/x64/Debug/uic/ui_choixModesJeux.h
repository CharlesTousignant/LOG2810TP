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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_DialogChoixModesJeux
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *buttonCreerAutomate;
    QLineEdit *lineEdit;
    QPushButton *buttonExit;
    QPushButton *buttonCorrection;
    QPushButton *buttonSuggestCorrect;
    QPushButton *buttonSuggestion;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *DialogChoixModesJeux)
    {
        if (DialogChoixModesJeux->objectName().isEmpty())
            DialogChoixModesJeux->setObjectName(QString::fromUtf8("DialogChoixModesJeux"));
        DialogChoixModesJeux->resize(637, 300);
        gridLayout = new QGridLayout(DialogChoixModesJeux);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DialogChoixModesJeux);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 2);

        buttonCreerAutomate = new QPushButton(DialogChoixModesJeux);
        buttonCreerAutomate->setObjectName(QString::fromUtf8("buttonCreerAutomate"));

        gridLayout->addWidget(buttonCreerAutomate, 0, 1, 1, 1);

        lineEdit = new QLineEdit(DialogChoixModesJeux);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAutoFillBackground(false);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        buttonExit = new QPushButton(DialogChoixModesJeux);
        buttonGroup = new QButtonGroup(DialogChoixModesJeux);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(buttonExit);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));

        gridLayout->addWidget(buttonExit, 3, 1, 1, 1);

        buttonCorrection = new QPushButton(DialogChoixModesJeux);
        buttonGroup->addButton(buttonCorrection);
        buttonCorrection->setObjectName(QString::fromUtf8("buttonCorrection"));

        gridLayout->addWidget(buttonCorrection, 2, 1, 1, 1);

        buttonSuggestCorrect = new QPushButton(DialogChoixModesJeux);
        buttonGroup->addButton(buttonSuggestCorrect);
        buttonSuggestCorrect->setObjectName(QString::fromUtf8("buttonSuggestCorrect"));

        gridLayout->addWidget(buttonSuggestCorrect, 2, 2, 1, 1);

        buttonSuggestion = new QPushButton(DialogChoixModesJeux);
        buttonGroup->addButton(buttonSuggestion);
        buttonSuggestion->setObjectName(QString::fromUtf8("buttonSuggestion"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonSuggestion->sizePolicy().hasHeightForWidth());
        buttonSuggestion->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonSuggestion, 2, 0, 1, 1);


        retranslateUi(DialogChoixModesJeux);

        QMetaObject::connectSlotsByName(DialogChoixModesJeux);
    } // setupUi

    void retranslateUi(QDialog *DialogChoixModesJeux)
    {
        DialogChoixModesJeux->setWindowTitle(QCoreApplication::translate("DialogChoixModesJeux", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogChoixModesJeux", "Choisissez le mode voulu.", nullptr));
        buttonCreerAutomate->setText(QCoreApplication::translate("DialogChoixModesJeux", "Creer automate", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("DialogChoixModesJeux", "Entrez le nom du lexique a utiliser. (Lexique1.txt par defautl)", nullptr));
        buttonExit->setText(QCoreApplication::translate("DialogChoixModesJeux", "Exit", nullptr));
        buttonCorrection->setText(QCoreApplication::translate("DialogChoixModesJeux", "Correction", nullptr));
        buttonSuggestCorrect->setText(QCoreApplication::translate("DialogChoixModesJeux", "Suggestion + Correction", nullptr));
        buttonSuggestion->setText(QCoreApplication::translate("DialogChoixModesJeux", "Suggestion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogChoixModesJeux: public Ui_DialogChoixModesJeux {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOIXMODESJEUX_H
