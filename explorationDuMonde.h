
#ifndef EXPLORATIONDUMONDE
#define EXPLORATIONDUMONDE

#include <string>
#include "carte.h"

class ExplorationDuMonde {
public:
	ExplorationDuMonde();
	void lancer();

private:
	char choisirOptionMenu();
	void lireCarte();
	void afficherCarte();
	void determinerFrontieres();
	void determinerPlusCourtChemin();
	void reinitialiserJeu();

	bool carteLue_;
	bool frontieresDeterminees_;
	std::string nomFichier;
	std::string paysOrigine_;
	std::string paysDestination_;
	char couleurAEviter_;
	std::shared_ptr<Carte> carte_;
};



#endif