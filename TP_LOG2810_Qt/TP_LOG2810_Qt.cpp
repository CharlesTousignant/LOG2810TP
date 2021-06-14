


#include "TP_LOG2810_Qt.h"
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
    connect(ui.textEdit, &QTextEdit::textChanged, this, &TP_LOG2810_Qt::keyPressed);
}

//void TP_LOG2810_Qt::eventFilter(QEvent event) {
//    if(event.KeyPress )
//}

void TP_LOG2810_Qt::keyPressed() {
    string text = ui.textEdit->toPlainText().toStdString();
    int newTextSize = text.length();

    if (newTextSize == 0) {
        currentWord = "";
        currTextSize = 0;
    }
        
    else {
        char keyPressed = text.back();

        //char keyPressed = event->KeyPress;

        // Si il y a moins de char dans le texte, retirer un char du mot courant
        if (newTextSize < currTextSize) {
            if (!currentWord.empty())
                currentWord.erase(currentWord.length() - (currTextSize - newTextSize));
        }

        else if (keyPressed == ' ') {
            currentWord = "";
        }

        else {
            currentWord += keyPressed;

        }
    }

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