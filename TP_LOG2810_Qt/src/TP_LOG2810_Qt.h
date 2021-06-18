#pragma once
#include "automate.h"

#include <QtWidgets/QMainWindow>
#include "MyDialog.h"
#include "ChoixApplication.h"
#include "explorationDuMonde.h"
#include "ui_TP_LOG2810_Qt.h"

#include <vector>




class TP_LOG2810_Qt : public QMainWindow
{
    Q_OBJECT

public:
    TP_LOG2810_Qt(QWidget* parent = Q_NULLPTR);

private:
    Ui::TP_LOG2810_QtClass ui;

    void creerAutomate(std::string nomFichier);
    void showChoices() const ;
    void TP_LOG2810_Qt::keyPressed();
    void addSuggestions(std::vector<std::string> suggestionsMots);
    //void eventFilter(QEvent event);


    Automate automateLexique;
    std::string currentWord;

    std::unique_ptr<MyDialog> dialog_;
    std::unique_ptr<ChoixApplication> choixApp_;
    std::unique_ptr<ExplorationDuMonde> exploration_;
    possibleGameState gameState_;

public slots:
    void setNewState(possibleGameState state);
    void startNewApp(selectedApplication selectedApp);
};
