s#include "automate.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

pair<bool, Etat> Etat::transition(char charTransition){
	if(transitions_.containsKey(charTransition)){
		return { true, transitions_.get(charTransition) };
	}
	else{
		return { false, *this };
	}
}

Automate::Automate()
{
}


bool Automate::creerLexique(const std::string& nomFichier)
{
	std::ifstream fichier;
	fichier.open(".\\data_partie1\\" + nomFichier);
	string mot;

	if (fichier) {
		while(!fichier.eof()) {
			getline(fichier, mot);
			lexique_.push_back(make_unique<string>(mot));
		}
		return true;
	}
	else {
		cout << "Erreur d'ouverture." << endl;
		return false;
	}
}

void Automate::suggererMots()
{
}

void Automate::corrigerMot(const std::string& mot)
{
}


