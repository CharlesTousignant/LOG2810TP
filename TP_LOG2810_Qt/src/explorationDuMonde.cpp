#include "explorationDuMonde.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


ExplorationDuMonde::ExplorationDuMonde(): carteLue_(false), frontieresDeterminees_(false)
{	
	carte_ = make_shared<Carte>();
	uiExploration_ = make_unique<Ui_Form_Exploration>();
	extractionDialog_ = make_unique<ExtractionGraphe>();

	uiExploration_->setupUi(this);
	connect(uiExploration_->LireCarte, &QPushButton::clicked, this, &ExplorationDuMonde::lireCarte);
	connect(uiExploration_->AfficherCarte, &QPushButton::clicked, this, &ExplorationDuMonde::afficherCarte);
	connect(uiExploration_->DeterminerFrontieres, &QPushButton::clicked, this, &ExplorationDuMonde::determinerFrontieres);
	connect(uiExploration_->PlusCourtChemin, &QPushButton::clicked, this, &ExplorationDuMonde::determinerPlusCourtChemin);

	//connect(extractionDialog_.get(), &ExtractionGraphe::choixCouleur, this, ExplorationDuMonde:)
};


void ExplorationDuMonde::lireCarte() {
	string nomFichier = uiExploration_->textEdit->toPlainText().toStdString();

	if (carteLue_) {
		reinitialiserJeu();
	}

	carteLue_ = carte_->creerGraphe(nomFichier);
	if(!carteLue_) {
		uiExploration_->textEdit->clear();
		uiExploration_->textEdit->setPlaceholderText(QString("Erreur. Verifier le nom du fichier et reessayez."));
	}
}


void ExplorationDuMonde::afficherCarte() {
	if (!carteLue_) {
		uiExploration_->textBrowser->append("Commencer par lire une carte");
	}
	else {
		stringstream os;
		carte_->lireGraphe(os);

		string line;
		while (getline(os, line)) {
			uiExploration_->textBrowser->append(QString::fromStdString(line));
		}
	}
}

void ExplorationDuMonde::determinerFrontieres() {
	if (!carteLue_) {
		uiExploration_->textBrowser->append("Commencer par lire une carte");
	}
	else {
		carte_->colorierGraphe();
		uiExploration_->textBrowser->append("Frontieres determinees:");
		frontieresDeterminees_ = true;
		//carte_->lireGraphe();
	}
}


void ExplorationDuMonde::determinerPlusCourtChemin(){
	if (!carteLue_) {
		uiExploration_->textBrowser->append("Commencer par lire une carte");
	}

	else if (!frontieresDeterminees_) { 
		uiExploration_->textBrowser->append("Commencer par determiner les frontieres"); 
	}

	else {
		string paysDestination = uiExploration_->paysDepart->toPlainText().toStdString();
		string paysOrigine = uiExploration_->paysArrivee->toPlainText().toStdString();
		char couleurARetirer;

		string isRetirerCouleur;

		// Afficher Extraction graphe dialog
		stringstream os;
		string line;
		if(isRetirerCouleur == "oui") {
			carte_->extractionGraphe(couleurARetirer).plusCourtChemin(paysOrigine, paysDestination, os);
		}
		else {
			
			carte_->plusCourtChemin(paysOrigine, paysDestination, os);
			while (getline(os, line)) {
				uiExploration_->textBrowser->append(QString::fromStdString(line));
			}
		}
	}
}



void ExplorationDuMonde::reinitialiserJeu()
{
	carteLue_ = false;
	frontieresDeterminees_ = false;
	carte_ = make_shared<Carte>();
}
