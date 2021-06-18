


#include "TP_LOG2810_Qt.h"
#include "ui_choixModesJeux.h"
#include <vector>
#include <fstream>
#include <sstream>

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


TP_LOG2810_Qt::TP_LOG2810_Qt(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    creerAutomate("lexique1.txt");
    
    connect(ui.textEdit, &QTextEdit::textChanged, this, &TP_LOG2810_Qt::keyPressed);
    connect(ui.pushButton, &QPushButton::pressed, this, & TP_LOG2810_Qt::showChoices);

    // on creer et initialise le dialog pour choisir l'application
    choixApp_ = make_unique<ChoixApplication>();
    dialog_ = make_unique<MyDialog>();
    exploration_ = make_unique<ExplorationDuMonde>();

    connect(choixApp_.get(), &ChoixApplication::choiceSelected, this, &TP_LOG2810_Qt::startNewApp);
    choixApp_->show();

    connect(dialog_.get(), &MyDialog::choiceSelected, this, &TP_LOG2810_Qt::setNewState);
    connect(dialog_.get(), &MyDialog::choiceLexique, this, &TP_LOG2810_Qt::creerAutomate);
}

void TP_LOG2810_Qt::creerAutomate(std::string nomFichier) {
    vector<shared_ptr<string>> lexique = creerLexique(nomFichier);
    automateLexique = Automate(lexique);
}

void TP_LOG2810_Qt::startNewApp(selectedApplication selectedApp) {
    switch (selectedApp)
    {
    case explorationDuMonde:
        // start exploration du monde
        exploration_->show();
        break;
    case jeuInstructif:
        showChoices();
        break;
    default:
        break;
    }
    choixApp_->accept();
}

void TP_LOG2810_Qt::showChoices() const {
    dialog_->show();
}

void TP_LOG2810_Qt::setNewState(possibleGameState state) {
    if (state == shouldExit) {
        choixApp_->show();
    }
    gameState_ = state;
    ui.textEdit->clear();
    ui.listWidget->clear();
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
     if (posWordStart == newTextSize - 1 ) {
         if (gameState_ == correct || gameState_ == suggestCorrect) {
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
                 currentWord = text.substr(startIndex, (posWordStart - startIndex + 1));
             }
             string correctionWord = automateLexique.corrigerMot(currentWord);

             // If there is no correction found, leave it as is
             if (correctionWord.length() == 0) {
                 correctionWord = currentWord;
             }
             string newText = text.substr(0, startIndex) + correctionWord + " ";
             ui.textEdit->blockSignals(true);
             ui.textEdit->setText(QString::fromStdString(newText));

             // put back cursor where it was
             auto cursor = &ui.textEdit->textCursor();
             cursor->movePosition(QTextCursor::MoveOperation::End);
             cursor->NoMove(true);
             ui.textEdit->blockSignals(false);
         }
     }

     else if (gameState_ == suggest || gameState_ == suggestCorrect) {
         currentWord = text.substr(posWordStart + 1);
         vector<string> suggestionsMots = automateLexique.suggererMots(currentWord);
         addSuggestions(suggestionsMots);
     }
}

void TP_LOG2810_Qt::addSuggestions(vector<string> suggestionsMots) {
    ui.listWidget->clear();

    for (auto mot : suggestionsMots) {
        ui.listWidget->addItem(QString::fromStdString(mot));
    }
}