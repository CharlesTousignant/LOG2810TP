#include <iostream>
#include <string>
#include <stdio.h>

#include <assert.h>
#include <sstream>  

#include "sommet.h"
#include "carte.h"
#include "test.cpp"
#include "explorationDuMonde.h"
using namespace std;

int main() {
	char optionChoisie = '0';
	string choixEntre;

	while (optionChoisie != 'c') {
		cout << "\n===========================\n"
			<< "a. Exploration du monde\n"
			<< "b. Jeu instructif\n"
			<< "c. Quitter" << endl
			<< "Veuillez choisir une options:\n";

		cin >> choixEntre;
		if (choixEntre.length() == 1) { 
			optionChoisie = choixEntre[0];
		}else{
			optionChoisie = '0';
		}
		ExplorationDuMonde explorationDuMonde;

		switch (optionChoisie) {
			case 'a':		
				explorationDuMonde.lancer();
				break;
			case 'b':
				//JeuInstructif jeuInstructif;
				//jeuInstructif.lancer();
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