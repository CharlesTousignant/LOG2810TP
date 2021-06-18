


#include "JeuxInstructif.h"
#include "ui_choixModesJeux.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>

#include "qdebug.h"

using namespace std;

vector<shared_ptr<string>> creerLexique(const string& nomFichier)
{
    ifstream fichier;
    fichier.open(".\\data_partie2\\" + nomFichier);
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


JeuxInstructif::JeuxInstructif(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    creerAutomate("lexique1.txt");

    connect(ui.textEdit, &QTextEdit::textChanged, this, &JeuxInstructif::keyPressed);
    connect(ui.pushButton, &QPushButton::pressed, this, &JeuxInstructif::showChoices);

    // on creer et initialise le dialog pour choisir l'application
    dialog_ = make_unique<ChoixModesJeux>();
    exploration_ = make_unique<ExplorationDuMonde>();
    connect(dialog_.get(), &ChoixModesJeux::choiceSelected, this, &JeuxInstructif::setNewState);
    connect(dialog_.get(), &ChoixModesJeux::choiceLexique, this, &JeuxInstructif::creerAutomate);
}

void JeuxInstructif::start() {
    this->show();
    dialog_->show();
}

void JeuxInstructif::closeEvent(QCloseEvent* event) {
    emit(windowClosed());
}

void JeuxInstructif::creerAutomate(std::string nomFichier) {
    vector<shared_ptr<string>> lexique = creerLexique(nomFichier);
    if (lexique.empty()) {
        dialog_->afficherErreur("Nom du lexique invalide.Reessayez");
    }
    automateLexique = Automate(lexique);
}


void JeuxInstructif::showChoices() const {
    dialog_->show();
}

void JeuxInstructif::setNewState(possibleGameState state) {
    if (state == shouldExit) {
        this->close();
        return;
    }
    gameState_ = state;
    ui.textEdit->clear();
    ui.listWidget->clear();
}

void JeuxInstructif::keyPressed() {
     QString qString = ui.textEdit->toPlainText();
     bool lastEnteredPunctuation = false;
     QRegExp matchAllNonLetters("[^a-zA-Z]");

     if (matchAllNonLetters.lastIndexIn(qString) == qString.length() - 1) {
         lastEnteredPunctuation = true;
     }

     QStringList stringList;
     stringList = qString.split(matchAllNonLetters);

     string text = qString.toStdString();
     size_t newTextSize = text.length();


     int index = 0;
     for (int i = stringList.length() - 1; i > 0; i--) {
         if (stringList[i].size() != 0) {
             index = i;
             break;
         }
     }

     string currentWord = stringList[index].toStdString();

     if (lastEnteredPunctuation && (gameState_ == correct || gameState_ == suggestCorrect)) {
         string correctionWord = automateLexique.corrigerMot(currentWord);

         // If there is no correction found, leave it as is
         if (correctionWord.length() == 0) {
             return;
         }

         qString.chop(currentWord.length() + 1);
         qString.append(QString::fromStdString(correctionWord + ' '));
         ui.textEdit->blockSignals(true);
         ui.textEdit->setText(qString);

         // put back cursor where it was
         auto cursor = &ui.textEdit->textCursor();
         cursor->movePosition(QTextCursor::MoveOperation::End);
         ui.textEdit->blockSignals(false);
     }
     else if (gameState_ == suggest || gameState_ == suggestCorrect) {
         //currentWord = text.substr(posWordStart + 1);
         vector<string> suggestionsMots = automateLexique.suggererMots(currentWord);
         addSuggestions(suggestionsMots);
     }
}

void JeuxInstructif::addSuggestions(vector<string> suggestionsMots) {
    ui.listWidget->clear();

    for (auto mot : suggestionsMots) {
        ui.listWidget->addItem(QString::fromStdString(mot));
    }
}