
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
	Automate();
	bool creerLexique(const std::string& nomFichier);
	void suggererMots();
	void corrigerMot(const std::string& mot);

private:
	std::vector<std::unique_ptr<std::string>> lexique_;
	Etat startState_;
};



#endif