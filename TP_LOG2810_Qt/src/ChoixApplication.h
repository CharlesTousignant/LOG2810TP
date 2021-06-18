#pragma once
#include "ui_choixApplication.h"
#include <QtWidgets/QDialog>
#include <memory.h>

enum selectedApplication {
    explorationDuMonde,
    jeuInstructif
};
class ChoixApplication : public QDialog {

    Q_OBJECT

public:
    ChoixApplication();

    void show();
    void buttonClicked();

    std::unique_ptr<Ui_choixAppliaction> uiDialog;

signals:
    void choiceSelected(selectedApplication selectedApp);
};