
#ifndef AUTOMATE
#define AUTOMATE

#include <string>
#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <hash_map>

class Etat {
public:
	Etat(char name, bool isValidWord);
	void addTransition(char charTransition, Etat etatArrive);

	std::pair<bool, Etat> transition(char charTransition);
	std::string getNom() const;
	bool isTerminal() const;
private:
	std::hash_map <char, std::shared_ptr<Etat>> transitions_;
	std::string nom_;
	bool isTerminal;
};

class Automate {
public:
	Automate();
	bool creerLexique(const std::string& nomFichier);
	void suggererMots();
	void corrigerMot(const std::string& mot);

private:
	std::vector<std::unique_ptr<std::string>> lexique_;
	Etat startState_;
};



#endif