/********************************************************************************
** Form generated from reading UI file 'extractionGraphe.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
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

class Ui_DialogExtractionGraphe
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *v;
    QPushButton *j;
    QPushButton *b;
    QPushButton *r;
    QPushButton *continuer;

    void setupUi(QDialog *DialogExtractionGraphe)
    {
        if (DialogExtractionGraphe->objectName().isEmpty())
            DialogExtractionGraphe->setObjectName(QString::fromUtf8("DialogExtractionGraphe"));
        DialogExtractionGraphe->resize(1005, 690);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DialogExtractionGraphe->sizePolicy().hasHeightForWidth());
        DialogExtractionGraphe->setSizePolicy(sizePolicy);
        DialogExtractionGraphe->setMinimumSize(QSize(30, 30));
        gridLayout = new QGridLayout(DialogExtractionGraphe);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(DialogExtractionGraphe);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 100));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        gridLayout->addWidget(label, 0, 0, 1, 4);

        v = new QPushButton(DialogExtractionGraphe);
        v->setObjectName(QString::fromUtf8("v"));

        gridLayout->addWidget(v, 1, 2, 1, 1);

        j = new QPushButton(DialogExtractionGraphe);
        j->setObjectName(QString::fromUtf8("j"));

        gridLayout->addWidget(j, 1, 3, 1, 1);

        b = new QPushButton(DialogExtractionGraphe);
        b->setObjectName(QString::fromUtf8("b"));

        gridLayout->addWidget(b, 1, 1, 1, 1);

        r = new QPushButton(DialogExtractionGraphe);
        r->setObjectName(QString::fromUtf8("r"));

        gridLayout->addWidget(r, 1, 0, 1, 1);

        continuer = new QPushButton(DialogExtractionGraphe);
        continuer->setObjectName(QString::fromUtf8("continuer"));

        gridLayout->addWidget(continuer, 2, 0, 1, 1);


        retranslateUi(DialogExtractionGraphe);

        QMetaObject::connectSlotsByName(DialogExtractionGraphe);
    } // setupUi

    void retranslateUi(QDialog *DialogExtractionGraphe)
    {
        DialogExtractionGraphe->setWindowTitle(QCoreApplication::translate("DialogExtractionGraphe", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogExtractionGraphe", "Choisisser une couleur \303\240 extraire,                        ou appuyez sur continuer.", nullptr));
        v->setText(QCoreApplication::translate("DialogExtractionGraphe", "v", nullptr));
        j->setText(QCoreApplication::translate("DialogExtractionGraphe", "j", nullptr));
        b->setText(QCoreApplication::translate("DialogExtractionGraphe", "b", nullptr));
        r->setText(QCoreApplication::translate("DialogExtractionGraphe", "r", nullptr));
        continuer->setText(QCoreApplication::translate("DialogExtractionGraphe", "Continuer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogExtractionGraphe: public Ui_DialogExtractionGraphe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXTRACTIONGRAPHE_H
