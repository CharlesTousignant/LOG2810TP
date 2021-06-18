#pragma once
#include "automate.h"

#include <QtWidgets/QMainWindow>
#include "ChoixModesJeux.h"
#include "explorationDuMonde.h"
#include "ui_jeuxInstructif.h"

#include <vector>




class JeuxInstructif : public QMainWindow
{
    Q_OBJECT

public:
    JeuxInstructif(QWidget* parent = Q_NULLPTR);
    void start();
private:
    Ui::JeuxInstructif_Class ui;

    void closeEvent(QCloseEvent* event) override;

    void creerAutomate(std::string nomFichier);

    void showChoices() const ;
    void keyPressed();
    void addSuggestions(std::vector<std::string> suggestionsMots);
    //void eventFilter(QEvent event);


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
