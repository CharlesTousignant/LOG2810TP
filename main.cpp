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
		unique_ptr<Automate> correcteur = make_unique<Automate>(lexique);
		while (true) {
			string motACorriger;
			cin >> motACorriger;
			vector<shared_ptr<string>> corrections = correcteur->corrigerMot(motACorriger);
			for (shared_ptr<string> mot : corrections) {
				cout << *mot << '\n';
			}
		}
		
	}
	#endif
}