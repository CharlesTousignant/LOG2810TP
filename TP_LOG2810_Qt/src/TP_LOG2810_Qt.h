#pragma once
#include "automate.h"

#include <QtWidgets/QMainWindow>
#include "MyDialog.h"
#include "ui_TP_LOG2810_Qt.h"

#include <vector>




class TP_LOG2810_Qt : public QMainWindow
{
    Q_OBJECT

public:
    TP_LOG2810_Qt(QWidget *parent = Q_NULLPTR);

private:
    Ui::TP_LOG2810_QtClass ui;
    void showChoices() const ;
    void TP_LOG2810_Qt::keyPressed();
    void addSuggestions(std::vector<std::string> suggestionsMots);
    //void eventFilter(QEvent event);


    Automate automateLexique;
    std::string currentWord;
    int currTextSize = 0;

    MyDialog* dialog_;
    possibleGameState gameState;
};
