#include <iostream>
#include <string>
#include <ctype.h>
#include "jeuInstructif.h"

using namespace std;

JeuInstructif::JeuInstructif() : lexiqueLu_(false)
{
	//automate = make_unique<automate_>();
};

void JeuInstructif::lancer()
{
	char choix = '0';

	while (choix != 'f') {
		choix = choisirOptionMenu();

		switch (choix) {
		case 'a':
			initialiserJeu();
			break;
		case 'b':
			saisirTexte(true, false);
			break;
		case 'c':
			saisirTexte(false, true);
			break;
		case 'd':
			saisirTexte(true, true);
			break;
		case 'e':
			// option retour???
			break;
		case 'f':
			cout << "Fin du jeu instructif\n";
			break;
		default:
			cout << "Choix invalide\n";
			break;
		}
	}
}


// interface graphique qui permet à l'utilisateur de saisir du texte
void JeuInstructif::saisirTexte(bool isSuggerer, bool isCorriger)
{
	if (lexiqueLu_) {
		bool isMotFini = false;
		string mot = "";

		while (!isMotFini) {
			entrerLettre(mot);

			if (isSuggerer) {
				cout << "\nsuggestion de mots...\n"; //automate->suggererMots(mot);
			}
			isMotFini = verifierMotFini();
		}

		if (isCorriger) {
			cout << "\ncorrection du mot...\n"; //automate->corrigerMot(mot);
		}

	}
	else {
		cout << "Veuillez lire un lexique au prealable (option a)\n";
	}

}

char JeuInstructif::choisirOptionMenu() {
	cout << "\n===========================\n";
	cout << "a. Initialiser le programme\n";
	cout << "b. Fonctionnalite suggestion\n";
	cout << "c. Fonctionnalite correction\n";
	cout << "d. Fonctionnalite suggestion et correction\n";
	cout << "e. Retour\n";
	cout << "f. Quitter\n";
	cout << "Veuillez choisir une options: ";

	char optionChoisie = '0';
	string choixEntre;
	cin >> choixEntre;

	if (choixEntre.length() == 1) {
		optionChoisie = choixEntre[0];
	}
	return optionChoisie;
}



void JeuInstructif::initialiserJeu() {
	string nomFichier;

	if (lexiqueLu_) {
		//reinitialiser lexique de l'automate?
	}
	while (!lexiqueLu_) {
		cout << "Entrez le nom du fichier de la carte a lire (par exemple:\"lexique1.txt\"): ";
		cin >> nomFichier;

		lexiqueLu_ = true; //lexiqueLu_ = automate_->creerLexique(nomFichier);

		if (lexiqueLu_) {
			cout << "Lexique lu\n";
		}
	}
}


bool JeuInstructif::verifierMotFini() {
	string reponseUtilisateur = "non";

	do {
		cout << "\nAvez-vous fini d'entrer un mot? (oui/non): ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> reponseUtilisateur;
	} while (reponseUtilisateur != "non" && reponseUtilisateur != "oui");

	if (reponseUtilisateur == "oui") {
		return true;
	}
	return false;
}

void JeuInstructif::entrerLettre(std::string& mot) {
	char lettreEntree = ' ';
	bool islettreValide = false;
	while (!islettreValide) {
		cout << "Entrer une lettre: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> lettreEntree;
		islettreValide = isalpha(lettreEntree);
	}
	mot.push_back(tolower(lettreEntree));
	cout << "Le mot entre est: " << mot << endl;
}