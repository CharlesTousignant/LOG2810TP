/********************************************************************************
** Form generated from reading UI file 'Exploration du monde.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPLORATION_20_DU_20_MONDE_H
#define UI_EXPLORATION_20_DU_20_MONDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_Exploration
{
public:
    QGridLayout *gridLayout;
    QPushButton *DeterminerFrontieres;
    QTextBrowser *textBrowser;
    QPushButton *LireCarte;
    QPushButton *AfficherCarte;
    QPushButton *PlusCourtChemin;
    QPushButton *Quitter;
    QTextEdit *textEdit;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(700, 448);
        gridLayout = new QGridLayout(Form);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        DeterminerFrontieres = new QPushButton(Form);
        DeterminerFrontieres->setObjectName(QString::fromUtf8("DeterminerFrontieres"));

        gridLayout->addWidget(DeterminerFrontieres, 2, 3, 1, 1);

        textBrowser = new QTextBrowser(Form);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMinimumSize(QSize(30, 30));
        QFont font;
        font.setPointSize(14);
        textBrowser->setFont(font);

        gridLayout->addWidget(textBrowser, 3, 1, 1, 5);

        LireCarte = new QPushButton(Form);
        LireCarte->setObjectName(QString::fromUtf8("LireCarte"));

        gridLayout->addWidget(LireCarte, 2, 1, 1, 1);

        AfficherCarte = new QPushButton(Form);
        AfficherCarte->setObjectName(QString::fromUtf8("AfficherCarte"));

        gridLayout->addWidget(AfficherCarte, 2, 2, 1, 1);

        PlusCourtChemin = new QPushButton(Form);
        PlusCourtChemin->setObjectName(QString::fromUtf8("PlusCourtChemin"));

        gridLayout->addWidget(PlusCourtChemin, 2, 4, 1, 1);

        Quitter = new QPushButton(Form);
        Quitter->setObjectName(QString::fromUtf8("Quitter"));

        gridLayout->addWidget(Quitter, 2, 5, 1, 1);

        textEdit = new QTextEdit(Form);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy1);
        textEdit->setMaximumSize(QSize(16777215, 37));

        gridLayout->addWidget(textEdit, 1, 1, 1, 1);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        DeterminerFrontieres->setText(QCoreApplication::translate("Form", "Determiner les frontieres", nullptr));
        LireCarte->setText(QCoreApplication::translate("Form", "Lire une carte", nullptr));
        AfficherCarte->setText(QCoreApplication::translate("Form", "Afficher un carte", nullptr));
        PlusCourtChemin->setText(QCoreApplication::translate("Form", "Determiner le plus court chemin", nullptr));
        Quitter->setText(QCoreApplication::translate("Form", "Quitter", nullptr));
        textEdit->setPlaceholderText(QCoreApplication::translate("Form", "Entrez le nom du fichier contenant la carte", nullptr));
    } // retranslateUi

};

namespace Ui {
    //class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPLORATION_20_DU_20_MONDE_H
