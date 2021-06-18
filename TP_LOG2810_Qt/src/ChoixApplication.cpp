#include "ui_choixApplication.h"
#include "ChoixApplication.h"

using namespace std;

ChoixApplication::ChoixApplication() {
    uiDialog = make_unique<Ui_choixApplication>();
    uiDialog->setupUi(this);
    connect(uiDialog->boutonExploration, &QPushButton::clicked, this, &ChoixApplication::buttonClicked);
    connect(uiDialog->boutonJeuInstructif, &QPushButton::clicked, this, &ChoixApplication::buttonClicked);
}

void ChoixApplication::show() {
    this->exec();
}

void ChoixApplication::buttonClicked() {
    string buttonPressedName = QObject::sender()->objectName().toStdString();
    if (buttonPressedName == "boutonExploration") {
        emit(choiceSelected(explorationDuMonde));
    }
    if (buttonPressedName == "boutonJeuInstructif") {
        emit(choiceSelected(jeuInstructif));
    }
}