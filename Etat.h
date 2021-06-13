#ifndef ETAT
#define ETAT

#include <string>
#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <map>

class Etat;

class Etat {
public:
	Etat(char name, bool isValidWord);
	void addTransition(char charTransition, bool isTerminal);
	void addTransition(char charTransition, std::string nomTransition, bool isTerminal);
	Etat addTransition(char charTransition, std::shared_ptr<Etat> etat);

	std::map <char, std::shared_ptr<Etat>>& getTransitions();
	std::string getNom() const;
	bool isTerminal() const;

private:
	std::map <char, std::shared_ptr<Etat>> transitions_;
	std::string name_;
	bool isTerminal_;
};

#endif