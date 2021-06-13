#include "automate.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


Automate::Automate(vector<unique_ptr<string>> lexique) {
	lexique_ = lexique;
}


//bool Automate::creerLexique(const string& nomFichier)
//{
//	std::ifstream fichier;
//	fichier.open(".\\data_partie1\\" + nomFichier);
//	string mot;
//
//	if (fichier) {
//		while(!fichier.eof()) {
//			getline(fichier, mot);
//			lexique_.push_back(make_unique<string>(mot));
//		}
//		return true;
//	}
//	else {
//		cout << "Erreur d'ouverture." << endl;
//		return false;
//	}
//}

void Automate::ajouterMot(string mot) {
	Etat currStateToModify = startState_;
	for (char& c : mot) {
		currStateToModify.addTransition(c, false);
		
	}
}

void Automate::suggererMots()
{
}

void Automate::corrigerMot(const string& mot)
{
	startState_ = make_shared<Etat>("", false);
	for ()
}

bool Automate::transition(char charTransition) {
	map<char, shared_ptr<Etat>> transitonsPossibles = currState_.getTransitions();
	map<char, shared_ptr<Etat>>::iterator found = transitonsPossibles.find(charTransition);

	// si transition etait valide
	if (found != transitonsPossibles.end()) {
		currState_ = *(found->second.get());
		return true;
	}

	return false;
}
