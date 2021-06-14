#include "Etat.h"

using namespace std;

Etat::Etat(string name, bool isValidWord) {
	name_ = name;
	isTerminal_ = isValidWord;
}


string Etat::getNom() const { return name_; };
bool Etat::isTerminal() const { return isTerminal_; };

map <char, std::shared_ptr<Etat>>& Etat::getTransitions() {
	return transitions_;
}

shared_ptr<Etat> Etat::addTransition(char charTransition, bool isTerminal) {
	auto it = transitions_.find(charTransition);
	// If transition doesn't exist
	if (it == transitions_.end()) {
		shared_ptr<Etat> etatTransition = make_shared<Etat>(name_ + charTransition, isTerminal);
		transitions_.insert(make_pair(charTransition, etatTransition));
		return etatTransition;
	}
	else {
		return it->second;
	}
}

void Etat::addTransition(char charTransition, string nomTransition, bool isTerminal) {

	// If transition doesn't exist
	if (transitions_.count(charTransition) == 0) {
		shared_ptr<Etat> etatTransition = make_shared<Etat>(nomTransition, isTerminal);
		transitions_.insert(make_pair(charTransition, etatTransition));
	}
}

void Etat::addTransition(char charTransition, shared_ptr<Etat> etat) {

	// If transition doesn't exist
	if (transitions_.count(charTransition) == 0) {
		transitions_.insert(make_pair(charTransition, etat));
	}
}

bool Etat::hasTransition(const char& charTransition) const {
	return transitions_.count(charTransition) != 0;
}

shared_ptr<Etat>& Etat::transition(const char& charTransition) {
	return transitions_.find(charTransition)->second;
}