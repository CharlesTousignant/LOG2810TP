
#ifndef EXPLORATIONDUMONDE
#define EXPLORATIONDUMONDE

#include <string>
#include <qwidget.h>
#include "ui_Exploration du monde.h"
#include "carte.h"

class ExplorationDuMonde : public QWidget{
public:
	ExplorationDuMonde();
	~ExplorationDuMonde() = default;
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
	std::string nomFichier_;
	std::string paysOrigine_;
	std::string paysDestination_;
	char couleurAEviter_;
	std::shared_ptr<Carte> carte_;

	std::unique_ptr<Ui_Form_Exploration> uiExploration_;
};



#endif