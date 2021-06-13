
#ifndef AUTOMATE
#define AUTOMATE

#include "Etat.h"

#include <string>
#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <memory>
#include <unordered_map>



class Automate {

public:
	Automate(std::vector<std::unique_ptr<std::string>> lexique);
	//bool creerLexique(const std::string& nomFichier);
	void suggererMots();
	void corrigerMot(const std::string& mot);

private:
	void ajouterMot(std::string mot);
	bool transition(char charTransition);
	std::vector<std::unique_ptr<std::string>> lexique_;

	std::shared_prt<Etat> currState_;
	std::shared_prt<Etat> startState_;
};



#endif