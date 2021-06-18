#include "MyDialog.h"
#include <iostream>

using namespace std;

MyDialog::MyDialog() {
    uiDialog = make_unique<Ui_Dialog>();
    uiDialog->setupUi(this);
    connect(uiDialog->buttonSuggestion, &QPushButton::clicked, this, &MyDialog::buttonClicked);
    connect(uiDialog->buttonCorrection, &QPushButton::clicked, this, &MyDialog::buttonClicked);
    connect(uiDialog->buttonSuggestCorrect, &QPushButton::clicked, this, &MyDialog::buttonClicked);
    connect(uiDialog->buttonExit, &QPushButton::clicked, this, &MyDialog::buttonClicked);
};

void MyDialog::show() {
    this->exec();
}

void MyDialog::buttonClicked() {
    QPushButton* buttonPressed = dynamic_cast<QPushButton*>(QObject::sender());
    string buttonPressedName = QObject::sender()->objectName().toStdString();

    if (buttonPressedName == "buttonSuggestion")
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
