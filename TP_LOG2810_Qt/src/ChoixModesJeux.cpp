//#include "ui_choixModesJeux.h"
#include "ChoixModesJeux.h"
#include <iostream>

using namespace std;

ChoixModesJeux::ChoixModesJeux() {
    uiDialog = make_unique<Ui_DialogChoixModesJeux>();
    uiDialog->setupUi(this);
    connect(uiDialog->buttonSuggestion, &QPushButton::clicked, this, &ChoixModesJeux::buttonClicked);
    connect(uiDialog->buttonCorrection, &QPushButton::clicked, this, &ChoixModesJeux::buttonClicked);
    connect(uiDialog->buttonSuggestCorrect, &QPushButton::clicked, this, &ChoixModesJeux::buttonClicked);
    connect(uiDialog->buttonExit, &QPushButton::clicked, this, &ChoixModesJeux::buttonClicked);

    connect(uiDialog->buttonCreerAutomate, &QPushButton::clicked, this, &ChoixModesJeux::buttonClicked);

    this->setModal(true);
};

void ChoixModesJeux::show() {
    this->exec();
}

void ChoixModesJeux::afficherErreur(string erreur) {
    uiDialog->lineEdit->clear();
    uiDialog->lineEdit->setPlaceholderText(QString::fromStdString(erreur));
}

void ChoixModesJeux::buttonClicked() {
    QPushButton* buttonPressed = dynamic_cast<QPushButton*>(QObject::sender());
    string buttonPressedName = QObject::sender()->objectName().toStdString();
    if (buttonPressedName == "buttonCreerAutomate") {
        emit(choiceLexique(uiDialog->lineEdit->text().toStdString()));
        return;
    }

    else if (buttonPressedName == "buttonSuggestion")
        emit(choiceSelected(suggest));
    else if (buttonPressedName == "buttonCorrection")
        emit(choiceSelected(correct));
    else if (buttonPressedName == "buttonSuggestCorrect")
        emit(choiceSelected(suggestCorrect));
    else
        emit(choiceSelected(shouldExit));
    // Close window
    this->accept();
}

void ChoixModesJeux::closeEvent(QCloseEvent* event) {
    emit(choiceSelected(shouldExit));
}
