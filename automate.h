
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
	Automate(std::vector<std::shared_ptr<std::string>>& lexique);
	//bool creerLexique(const std::string& nomFichier);
	std::vector<std::string> suggererMots(const std::string& motACompleter);
	void suggererMots(const std::shared_ptr<Etat>& etatDepart, std::vector<std::string>& motsARetourner);

	std::vector<std::shared_ptr<std::string>> corrigerMot(const std::string& mot);

private:
	void ajouterMot(std::string mot);
	bool transition(char charTransition);
	std::vector<std::shared_ptr<std::string>> lexique_;

	std::shared_ptr<Etat> currState_;
	std::shared_ptr<Etat> startState_;
};



#endif