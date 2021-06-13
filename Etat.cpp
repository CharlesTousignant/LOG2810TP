#include "Etat.h"

using namespace std;

Etat::Etat(char name, bool isValidWord) {
	name_ = name;
	isTerminal_ = isValidWord;
}


string Etat::getNom() const { return name_; };
bool Etat::isTerminal() const { return isTerminal_; };

map <char, std::shared_ptr<Etat>>& Etat::getTransitions() {
	return transitions_;
}

Etat Etat::addTransition(char charTransition, bool isTerminal) {

	// If transition doesn't exist
	if (transitions_.count(charTransition) == 0) {
		shared_ptr<Etat> etatTransition = make_shared<Etat>(name_ + charTransition, isTerminal);
		transitions_.insert(charTransition, etatTransition);
		return etatTransition;
	}
}

void Etat::addTransition(char charTransition, string nomTransition, bool isTerminal) {

	// If transition doesn't exist
	if (transitions_.count(charTransition) == 0) {
		shared_ptr<Etat> etatTransition = make_shared<Etat>(nomTransition, isTerminal);
		transitions_.insert(charTransition, etatTransition);
	}
}

void Etat::addTransition(char charTransition, shared_ptr<Etat> etat) {

	// If transition doesn't exist
	if (transitions_.count(charTransition) == 0) {
		transitions_.insert(charTransition, etat);
	}
}