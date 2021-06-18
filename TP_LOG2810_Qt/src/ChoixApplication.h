#pragma once
#include "ui_choixApplication.h"
#include "JeuxInstructif.h"
#include "ChoixModesJeux.h"
#include "explorationDuMonde.h"

//#include <QtWidgets/QDialog>
#include <memory.h>

enum selectedApplication {
    explorationDuMonde,
    jeuInstructif
};

class ChoixApplication : public QDialog
{

    Q_OBJECT

public:
    ChoixApplication();

    void startNewApp(selectedApplication selectedApp);
    void buttonClicked();

    void showApps();

    std::unique_ptr<Ui_choixApplication> uiDialog_;
    std::unique_ptr<JeuxInstructif> jeuxInstructif_;
    std::unique_ptr<ExplorationDuMonde> exploration_;

//signals:
//    void choiceSelected(selectedApplication selectedApp);
};