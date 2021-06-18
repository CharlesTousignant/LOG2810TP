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

class Ui_Dialog
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

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(637, 300);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 1, 0, 1, 2);

        buttonCreerAutomate = new QPushButton(Dialog);
        buttonCreerAutomate->setObjectName(QString::fromUtf8("buttonCreerAutomate"));

        gridLayout->addWidget(buttonCreerAutomate, 0, 1, 1, 1);

        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAutoFillBackground(false);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        buttonExit = new QPushButton(Dialog);
        buttonGroup = new QButtonGroup(Dialog);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(buttonExit);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));

        gridLayout->addWidget(buttonExit, 3, 1, 1, 1);

        buttonCorrection = new QPushButton(Dialog);
        buttonGroup->addButton(buttonCorrection);
        buttonCorrection->setObjectName(QString::fromUtf8("buttonCorrection"));

        gridLayout->addWidget(buttonCorrection, 2, 1, 1, 1);

        buttonSuggestCorrect = new QPushButton(Dialog);
        buttonGroup->addButton(buttonSuggestCorrect);
        buttonSuggestCorrect->setObjectName(QString::fromUtf8("buttonSuggestCorrect"));

        gridLayout->addWidget(buttonSuggestCorrect, 2, 2, 1, 1);

        buttonSuggestion = new QPushButton(Dialog);
        buttonGroup->addButton(buttonSuggestion);
        buttonSuggestion->setObjectName(QString::fromUtf8("buttonSuggestion"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonSuggestion->sizePolicy().hasHeightForWidth());
        buttonSuggestion->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonSuggestion, 2, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Choisissez le mode voulu.", nullptr));
        buttonCreerAutomate->setText(QCoreApplication::translate("Dialog", "Creer automate", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Dialog", "Entrez le nom du lexique a utiliser. (Lexique1.txt par defautl)", nullptr));
        buttonExit->setText(QCoreApplication::translate("Dialog", "Exit", nullptr));
        buttonCorrection->setText(QCoreApplication::translate("Dialog", "Correction", nullptr));
        buttonSuggestCorrect->setText(QCoreApplication::translate("Dialog", "Suggestion + Correction", nullptr));
        buttonSuggestion->setText(QCoreApplication::translate("Dialog", "Suggestion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOIXMODESJEUX_H
