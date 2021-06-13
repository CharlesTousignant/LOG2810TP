#include <iostream>
#include <string>
#include <stdio.h>

#include "explorationDuMonde.h"
#include "jeuInstructif.h"
using namespace std;

int main() {
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
		}else{
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