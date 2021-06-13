#include "explorationDuMonde.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


ExplorationDuMonde::ExplorationDuMonde(): carteLue_(false), frontieresDeterminees_(false)
{
	carte_ = make_shared<Carte>();
};


void ExplorationDuMonde::lancer()
{
	string nomFichier;
	char choix = '0';

	while (choix != '5') {
		choix = choisirOptionMenu();

		switch (choix) {
			case '1':
				lireCarte();
				break;
			case '2':
				afficherCarte();
				break;
			case '3':
				determinerFrontieres();
				break;
			case '4':
				determinerPlusCourtChemin();
				break;
			case '5':
				cout << "Fin du jeu Exploration du monde\n";
				break;
			default:
				cout << "Choix invalide\n";
				break;
		}
	}
}

char ExplorationDuMonde::choisirOptionMenu() {
	cout << "\n===========================\n";
	cout << "1. Lire une carte\n";
	cout << "2. Afficher une carte\n";
	cout << "3. Determiner les frontieres" << endl;
	cout << "4. Determiner le plus court chemin" << endl;
	cout << "5. Quitter" << endl;
	cout << "Veuillez choisir une options: ";

	char optionChoisie = '0';
	string choixEntre;
	cin >> choixEntre;
	
	if (choixEntre.length() == 1) { 
		optionChoisie = choixEntre[0];
	}
	return optionChoisie;
}


void ExplorationDuMonde::lireCarte() {
	string nomFichier;
	if (carteLue_) {
		reinitialiserJeu();
	}
	while (!carteLue_) {
		cout << "Entrez le nom du fichier de la carte a lire (par exemple:\"grapheCanada.txt\"): ";
		cin >> nomFichier;

		carteLue_ = carte_->creerGraphe(nomFichier);
		if(carteLue_) {
			cout << "Carte lue\n";
		}
	}
}


void ExplorationDuMonde::afficherCarte() {
	if (!carteLue_) {
		cout << "Commencer par lire une carte (option 1)\n";
	}
	else {
		carte_->lireGraphe();
	}
}

void ExplorationDuMonde::determinerFrontieres() {
	if (!carteLue_) { cout << "Commencer par lire une carte (option 1)\n"; }
	else {
		carte_->colorierGraphe();
		cout << "Frontieres determinees:\n";
		frontieresDeterminees_ = true;
		carte_->lireGraphe();
	}
}


void ExplorationDuMonde::determinerPlusCourtChemin(){
	if (!carteLue_) { cout << "Commencer par lire une carte (option 1)\n"; }
	else if (!frontieresDeterminees_) { cout << "Commencer par determiner les frontieres (option 3)\n"; }
	else {
		string paysDestination;
		string paysOrigine;
		char couleurARetirer;
		
		cout << "Entrer le pays d'origine: ";
		cin >> paysOrigine;
		cout << "Entrer le pays de destination: ";
		cin >> paysDestination;
		string isRetirerCouleur;

		do {
			cout << "Voulez-vous retirer une couleur? (oui/non): ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> isRetirerCouleur;
		} while (isRetirerCouleur != "non" && isRetirerCouleur != "oui");
		
		if(isRetirerCouleur == "oui") {
			cout << "Entrer la couleur a retirer: ";
			cin >> couleurARetirer;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			carte_->extractionGraphe(couleurARetirer).plusCourtChemin(paysOrigine, paysDestination);
		}
		else {
			carte_->plusCourtChemin(paysOrigine, paysDestination);
		}
	}
}


void ExplorationDuMonde::reinitialiserJeu()
{
	carteLue_ = false;
	frontieresDeterminees_ = false;
	carte_ = make_shared<Carte>();
}
