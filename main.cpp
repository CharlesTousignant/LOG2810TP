#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <sstream>

#include "explorationDuMonde.h"
#include "jeuInstructif.h"
#include "automate.h"
using namespace std;

#define ACTIVER_MAIN false
#define ACTIVER_TESTS true


vector<shared_ptr<string>> creerLexique(const string& nomFichier)
{
	std::ifstream fichier;
	fichier.open(".\\data_partie1\\" + nomFichier);
	string mot;
	vector<shared_ptr<string>> lexique = vector<shared_ptr<string>>();

	if (fichier) {
		while(!fichier.eof()) {
			getline(fichier, mot);
			lexique.push_back(make_shared<string>(mot));
		}
	}
	else {
		cout << "Erreur d'ouverture." << endl;
	}
	return lexique;
}

int main() {
	#if ACTIVER_MAIN == true
	{
		char optionChoisie = '0';
		string choixEntre;

		while (optionChoisie != 'c') {
			cout << "\n===========================\n"
				<< "a. Exploration du monde\n"
				<< "b. Jeu instructif\n"
				<< "c. Quitter" << endl
				<< "Veuillez choisir une options: ";

			cin >> choixEntre;
			if (choixEntre.length() == 1) {
				optionChoisie = choixEntre[0];
			}
			else {
				optionChoisie = '0';
			}

			ExplorationDuMonde explorationDuMonde;
			JeuInstructif jeuInstructif;

			switch (optionChoisie) {
			case 'a':
				explorationDuMonde.lancer();
				break;
			case 'b':
				jeuInstructif.lancer();
				break;
			case 'c':
				cout << "Fin du programme\n";
				exit(0);
				break;
			default:
				cout << "Choix invalide\n";
				break;
			}
		}
	}
	#endif
	#if ACTIVER_TESTS == true
	{
		vector<shared_ptr<string>> lexique = creerLexique("lexique6.txt");
		unique_ptr<Automate> automate = make_unique<Automate>(lexique);
		cout << "Le lexique a ete lu \n";

		while (true) {
			string motACompleter;
			cout << "Entrez un mot a completer \n";
			cin >> motACompleter;
			vector<string> suggestions = automate->suggererMots(motACompleter);
			cout << "suggestions: \n";

			for (string mot : suggestions) {
				cout << mot << '\n';
			}

			cout << "\n===========================\n";

			cout << "Entrez un mot a corriger \n";
			string motacorriger;
			cin >> motacorriger;
			vector<shared_ptr<string>> corrections = automate->corrigerMot(motacorriger);
			cout << "correction: \n";
			for (shared_ptr<string> mot : corrections) {
				cout << *mot << '\n';
			}
		}


		while (true) {

		}

	}
	#endif
}