#pragma once
#include "automate.h"

#include <QtWidgets/QMainWindow>
#include "MyDialog.h"
#include "ChoixApplication.h"

#include "ui_TP_LOG2810_Qt.h"

#include <vector>




class TP_LOG2810_Qt : public QMainWindow
{
    Q_OBJECT

public:
    TP_LOG2810_Qt(std::string fichierLexique = "lexique6.txt", QWidget* parent = Q_NULLPTR);

private:
    Ui::TP_LOG2810_QtClass ui;
    void showChoices() const ;
    void TP_LOG2810_Qt::keyPressed();
    void addSuggestions(std::vector<std::string> suggestionsMots);
    //void eventFilter(QEvent event);


    Automate automateLexique;
    std::string currentWord;

    MyDialog* dialog_;
    ChoixApplication* choixApp_;
    possibleGameState gameState_;

public slots:
    void setNewState(possibleGameState state);
    void startNewApp(selectedApplication selectedApp);
};
