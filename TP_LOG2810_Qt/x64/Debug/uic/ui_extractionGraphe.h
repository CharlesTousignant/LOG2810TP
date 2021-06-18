/********************************************************************************
** Form generated from reading UI file 'extractionGraphe.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXTRACTIONGRAPHE_H
#define UI_EXTRACTIONGRAPHE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog_Extraction
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *v;
    QPushButton *j;
    QPushButton *b;
    QPushButton *r;
    QPushButton *continuer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(336, 300);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(30, 30));
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        gridLayout->addWidget(label, 0, 0, 1, 4);

        v = new QPushButton(Dialog);
        v->setObjectName(QString::fromUtf8("v"));

        gridLayout->addWidget(v, 1, 2, 1, 1);

        j = new QPushButton(Dialog);
        j->setObjectName(QString::fromUtf8("j"));

        gridLayout->addWidget(j, 1, 3, 1, 1);

        b = new QPushButton(Dialog);
        b->setObjectName(QString::fromUtf8("b"));

        gridLayout->addWidget(b, 1, 1, 1, 1);

        r = new QPushButton(Dialog);
        r->setObjectName(QString::fromUtf8("r"));

        gridLayout->addWidget(r, 1, 0, 1, 1);

        continuer = new QPushButton(Dialog);
        continuer->setObjectName(QString::fromUtf8("continuer"));

        gridLayout->addWidget(continuer, 2, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Choisisser une couleur \303\240 extraire,                        ou appuyez sur continuer.", nullptr));
        v->setText(QCoreApplication::translate("Dialog", "v", nullptr));
        j->setText(QCoreApplication::translate("Dialog", "j", nullptr));
        b->setText(QCoreApplication::translate("Dialog", "b", nullptr));
        r->setText(QCoreApplication::translate("Dialog", "r", nullptr));
        continuer->setText(QCoreApplication::translate("Dialog", "Continuer", nullptr));
    } // retranslateUi

};

namespace Ui {
    // class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRACTIONGRAPHE_H
