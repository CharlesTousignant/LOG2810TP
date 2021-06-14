#include "automate.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


Automate::Automate(vector<shared_ptr<string>>& lexique) {
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

vector<shared_ptr<string>> Automate::corrigerMot(const string& mot)
{
	//creation de la machine a etat du mot
	startState_ = make_shared<Etat>("", false);
	currState_ = startState_;
	int motLength = mot.length();
	for (int i = 0; i < motLength - 1; i++) {
		currState_->addTransition(mot.at(i), false);
		currState_->addTransition('0', currState_->getNom() + mot.at(i), false);
		transition(mot.at(i));
	}
	currState_->addTransition('0', mot, true);
	
	currState_ = startState_;
	for (int i = 0; i < motLength - 1; i++) {
		shared_ptr<Etat> stateToLink = currState_->getTransitions().find(mot.at(i))->second
			->getTransitions().find('0')->second;
		currState_->getTransitions().find('0')->second->addTransition(mot.at(i + 1), stateToLink);
		transition(mot.at(i));
	}
	
	shared_ptr<Etat> finalState = make_shared<Etat>("", true);
	currState_ = startState_;
	transition('0');
	for (int i = 1; i <= motLength - 1; i++) {
		currState_->addTransition('0', finalState);
		transition(mot.at(i));
	}

	vector<shared_ptr<string>> suggestions = vector<shared_ptr<string>>();
	for (shared_ptr<string> correction : lexique_) {
//		shared_ptr<string> correction = lexique_.at(i);
		if (motLength == correction->length()) {
			if (mot != *(correction.get())) {
				currState_ = startState_;
				bool correctionValide = true;
				for (int i = 0; i < motLength; i++) {
					if (mot.at(i) == correction->at(i)) {
						transition(mot.at(i));
					}
					else {
						transition('0');
					}
					
				}
				if (currState_->getNom() != "") {
					suggestions.push_back(correction);
				}
			}
			else {
				return vector<shared_ptr<string>>();
			}
		}
	}
	return suggestions;
}

bool Automate::transition(char charTransition) {
	map<char, shared_ptr<Etat>> transitonsPossibles = currState_->getTransitions();
	map<char, shared_ptr<Etat>>::iterator found = transitonsPossibles.find(charTransition);

	// si transition etait valide
	if (found != transitonsPossibles.end()) {
		currState_ = found->second;
		return true;
	}

	return false;
}
