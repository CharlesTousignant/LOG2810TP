


#include "TP_LOG2810_Qt.h"
#include "ui_choix.h"

#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<shared_ptr<string>> creerLexique(const string& nomFichier)
{
    ifstream fichier;
    fichier.open(".\\data_partie1\\" + nomFichier);
    string mot;
    vector<shared_ptr<string>> lexique = vector<shared_ptr<string>>();

    if (fichier) {
        while (!fichier.eof()) {
            getline(fichier, mot);
            lexique.push_back(make_shared<string>(mot));
        }
    }
    else {
        // cout << "Erreur d'ouverture." << endl;
    }
    return lexique;
}


TP_LOG2810_Qt::TP_LOG2810_Qt(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // ui.textEdit->installEventFilter(this);
    vector<shared_ptr<string>> lexique = creerLexique("lexique6.txt");
    automateLexique = Automate(lexique);
    showChoices();
    connect(ui.textEdit, &QTextEdit::textChanged, this, &TP_LOG2810_Qt::keyPressed);
    connect(ui.pushButton, &QPushButton::pressed, this, & TP_LOG2810_Qt::showChoices);

    MyDialog* dialog_ = new MyDialog();

}

void TP_LOG2810_Qt::showChoices() const {
    dialog_->show();
}

void TP_LOG2810_Qt::keyPressed() {
    string text = ui.textEdit->toPlainText().toStdString();
    size_t newTextSize = text.length();

     string currentWord;

     int posWordStart = text.find_last_of(' ');

     // If there is no space, then the word is the whole text.
     if (posWordStart == -1) {
         currentWord = text;
     }

     // If we just entered a space
     else if (posWordStart == newTextSize - 1) {
         // check if we should give corrction

         // find the position of the last space before we find a letter
         while (posWordStart >= 0 && text[posWordStart] == ' ') { posWordStart--; };

         int startIndex = 0;
         // If there is only spaces in the text
         if (posWordStart == -1) {
             currentWord = "";
         }

         // If there is only one character
         else if (posWordStart == 0) {
             currentWord = text[posWordStart];
         }

         // find the last written word
         else {
             // le mot commence 1 apres le dernier espace
             startIndex = text.find_last_of(' ', posWordStart) + 1;
             currentWord = text.substr(startIndex, posWordStart + 1);
         }
         string correctionWord = automateLexique.corrigerMot(currentWord);

         // If there is no correction found, leave it as is
         if (correctionWord.length() == 0) {
             correctionWord = currentWord;
         }

         ui.textEdit->setText(QString::fromStdString(text.substr(0, startIndex) + correctionWord));

     }

     else {
         currentWord = text.substr(posWordStart + 1);
     }



    //if (newTextSize == 0) {
    //    currentWord = "";
    //    currTextSize = 0;
    //}
    //    
    //else {
    //    char keyPressed = text.back();

    //    //char keyPressed = event->KeyPress;

    //    // Si il y a moins de char dans le texte, retirer un char du mot courant
    //    if (newTextSize < currTextSize) {
    //        if (!currentWord.empty())
    //            currentWord.erase(currentWord.length() - (currTextSize - newTextSize));
    //    }

    //    else if (keyPressed == ' ') {
    //        currentWord = "";
    //    }

    //    else {
    //        currentWord += keyPressed;

    //    }
    //}

    vector<string> suggestionsMots = automateLexique.suggererMots(currentWord);
    addSuggestions(suggestionsMots);

    currTextSize = newTextSize;
}

void TP_LOG2810_Qt::addSuggestions(vector<string> suggestionsMots) {
    ui.listWidget->clear();

    for (auto mot : suggestionsMots) {
        ui.listWidget->addItem(QString::fromStdString(mot));
    }
}