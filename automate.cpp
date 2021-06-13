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
	startState_ = make_shared<Etat>("", false);
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
	Etat currStateToModify = *startState_.get();
	string::iterator it = mot.begin();

	for (int i = 0; i < mot.length() - 1; i++, it++) {
		currStateToModify = currStateToModify.addTransition(*it, false);
	}

	// On rajoute le dernier caractere qui est un etat terminal
	currStateToModify.addTransition(*it, true);
}

void Automate::suggererMots()
{
}

void Automate::corrigerMot(const string& mot)
{
	//startState_ = make_shared<Etat>("", false);
	currState_ = startState_;
	for (int i = 0; i < mot.length() - 1; i++) {
		currState_->addTransition(mot.at(i), false);
		currState_->addTransition('0', currState_->getNom() + mot.at(i), false);
		transition(mot.at(i));
	}
	currState_->addTransition('0', mot, true)
	
	currState_ = startState_;

}

bool Automate::transition(char charTransition) {
	map<char, shared_ptr<Etat>> transitonsPossibles = currState_.getTransitions();
	map<char, shared_ptr<Etat>>::iterator found = transitonsPossibles.find(charTransition);

	// si transition etait valide
	if (found != transitonsPossibles.end()) {
		currState_ = found->second;
		return true;
	}

	return false;
}
