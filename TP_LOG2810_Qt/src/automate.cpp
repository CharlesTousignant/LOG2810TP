#include "automate.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;


Automate::Automate(vector<shared_ptr<string>>& lexique) :
	startState_(make_shared<Etat>("", false)) {
	for (auto mot : lexique) {
		lexique_.insert(*mot.get());
	}

	for (shared_ptr<string> mot : lexique) {
		ajouterMot(*mot.get());
	}
	
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
	shared_ptr<Etat> currStateToModify = startState_;
	string::iterator it = mot.begin();

	for (int i = 0; i < mot.length() - 1; i++, it++) {
		currStateToModify = currStateToModify->addTransition(*it, false);
	}

	// On rajoute le dernier caractere qui est un etat terminal
	currStateToModify->addTransition(*it, true);
}

vector<string> Automate::suggererMots(const string& motACompleter)
{	
	
	currState_ = startState_;
	vector<string> motsToReturn;

	if (motACompleter.empty())
		return motsToReturn;

	for (char c : motACompleter) {
		if (currState_->hasTransition(c)) {
			currState_ = currState_->transition(c);
		}
		else {
			// On retourne rien si le motACompleter n'est pas dans l'automate
			return motsToReturn;
		}
	}


	//queue<shared_ptr<Etat>> etatsAEssayer;
	//for (int i = 0; i < 10; i++) {
	//	// Trouver les lettres restantes
	//	while (!currState_->isTerminal()) {
	//		etatsAEssayer.push(currState_);
	//		auto transitions = currState_->getTransitions();
	//		currState_ = currState_->transition(transitions.begin()->first);
	//	}
	//	motsToReturn.push_back(currState_->getNom());
	//	currState_ = etatsAEssayer.front();
	//}

	suggererMots(currState_, motsToReturn);
	return 	motsToReturn;
}

void Automate::suggererMots(const shared_ptr<Etat>& etatDepart, vector<string>& motsToReturn) {

	
	auto transitionsPossible = etatDepart->getTransitions();
	shared_ptr<Etat> found;

	for (auto charTransition : transitionsPossible) {

		if (motsToReturn.size() < 10) {
			found = etatDepart->transition(charTransition.first);
			if (found->isTerminal()) {
				motsToReturn.push_back(found->getNom());
			}
			suggererMots(etatDepart->transition(charTransition.first), motsToReturn);
		}
	}
}

string Automate::corrigerMot(const string& mot)
{   
	// Si le mot est bien ecrit, rien retourner
	if (lexique_.count(mot) > 0) {
		return "";
	}

	//creation de la machine a etat du mot
	shared_ptr<Etat> startStateCorrection = make_shared<Etat>("", false);
	currState_ = startStateCorrection;
	int motLength = mot.length();
	for (int i = 0; i < motLength - 1; i++) {
		currState_->addTransition(mot.at(i), false);
		currState_->addTransition('0', currState_->getNom() + mot.at(i), false);
		transition(mot.at(i));
	}
	currState_->addTransition('0', mot, true);
	
	currState_ = startStateCorrection;
	for (int i = 0; i < motLength - 1; i++) {
		shared_ptr<Etat> stateToLink = currState_->getTransitions().find(mot.at(i))->second
			->getTransitions().find('0')->second;
		currState_->getTransitions().find('0')->second->addTransition(mot.at(i + 1), stateToLink);
		transition(mot.at(i));
	}
	
	shared_ptr<Etat> finalState = make_shared<Etat>("", true);
	currState_ = startStateCorrection;
	transition('0');
	for (int i = 1; i <= motLength - 1; i++) {
		currState_->addTransition('0', finalState);
		transition(mot.at(i));
	}

	vector<shared_ptr<string>> suggestions = vector<shared_ptr<string>>();
	for (string correction : lexique_) {
//		shared_ptr<string> correction = lexique_.at(i);
		if (motLength == correction.length()) {
			if (mot != correction) {
				currState_ = startStateCorrection;
				bool correctionValide = true;
				for (int i = 0; i < motLength; i++) {
					if (mot.at(i) == correction.at(i)) {
						transition(mot.at(i));
					}
					else {
						transition('0');
					}
					
				}
				if (currState_->getNom() != "") {
					return correction;
				}
			}
			else {
				continue;
			}
		}
	}

	return "";
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
