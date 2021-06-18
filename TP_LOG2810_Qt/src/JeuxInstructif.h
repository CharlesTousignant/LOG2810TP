#pragma once
#include "automate.h"

#include <QtWidgets/QMainWindow>
#include "ChoixModesJeux.h"
#include "explorationDuMonde.h"
#include "../x64/Debug/uic/ui_jeuxInstructif.h"

#include <vector>




class JeuxInstructif : public QMainWindow
{
    Q_OBJECT

public:
    JeuxInstructif(QWidget* parent = Q_NULLPTR);
    void start();
private:
    Ui::JeuxInstructif ui;

    void closeEvent(QCloseEvent* event) override;

    void creerAutomate(std::string nomFichier);

    void showChoices() const ;
    void keyPressed();
    void addSuggestions(std::vector<std::string> suggestionsMots);
    
    void resetCursor();


    Automate automateLexique;
    std::string currentWord;

    std::unique_ptr<ChoixModesJeux> dialog_;
    std::unique_ptr<ExplorationDuMonde> exploration_;
    possibleGameState gameState_;

public slots:
    void setNewState(possibleGameState state);
    

signals:
    void windowClosed();
};
