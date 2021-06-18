#pragma once
#include <stdio.h>

#include "SelectionMode.h"
#include "TP_LOG2810_Qt.h"

using namespace std;

int choisirMode() {
	cout << "\n===========================\n";
	cout << "1. Exploration du monde\n";
	cout << "2. Jeu Instructif\n";
	cout << "Veuillez choisir une options: ";

	string optionChoisie = "";
	cin >> optionChoisie;

	if ( optionChoisie == "0") {
		return 0;
	}

	else if (optionChoisie == "1") {
		return 1;
	}

	else {
		"Choix Invalide. Veuillez reessayer. \n";
		//choisirMode();
	}
}

void lancerMode(int modeChoisi, int argc, char *argv[]) {

}