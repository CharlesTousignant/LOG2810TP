#include "ui_choixApplication.h"
#include "ChoixApplication.h"

using namespace std;

ChoixApplication::ChoixApplication() {
    uiDialog_ = make_unique<Ui_choixApplication>();
    jeuxInstructif_ = make_unique<JeuxInstructif>();
    exploration_ = make_unique<ExplorationDuMonde>();

    uiDialog_->setupUi(this);
    connect(uiDialog_->boutonExploration, &QPushButton::clicked, this, &ChoixApplication::buttonClicked);
    connect(uiDialog_->boutonJeuInstructif, &QPushButton::clicked, this, &ChoixApplication::buttonClicked);
    //connect(this, &ChoixApplication::choiceSelected, this, &ChoixApplication::startNewApp);

    connect(jeuxInstructif_.get(), &JeuxInstructif::windowClosed, this, &ChoixApplication::showApps);
    connect(exploration_.get(), &ExplorationDuMonde::windowClosed, this, &ChoixApplication::showApps);
}

void ChoixApplication::showApps() {
    jeuxInstructif_->stackUnder(this);
    exploration_->hide();
    this->show();
}

void ChoixApplication::startNewApp(selectedApplication selectedApp) {
    switch (selectedApp)
    {
    case explorationDuMonde:
        // start exploration du monde
        exploration_->show();
        break;
    case jeuInstructif:
        jeuxInstructif_->start();
        break;
    default:
        break;
    }
    //this->hide();
}

void ChoixApplication::buttonClicked() {
    string buttonPressedName = QObject::sender()->objectName().toStdString();
    if (buttonPressedName == "boutonExploration") {
        startNewApp(explorationDuMonde);
    }
    if (buttonPressedName == "boutonJeuInstructif") {
        startNewApp(jeuInstructif);
    }
}