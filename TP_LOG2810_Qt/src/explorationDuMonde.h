
#ifndef EXPLORATIONDUMONDE
#define EXPLORATIONDUMONDE

#include <string>
#include <qwidget.h>
#include "ui_Exploration du monde.h"
#include "ExtractionGraphe.h"
#include "carte.h"

class ExplorationDuMonde : public QWidget{
	Q_OBJECT
public:
	ExplorationDuMonde();
	~ExplorationDuMonde() = default;
	void lancer();

	void closeEvent(QCloseEvent* event) override;

private:
	char choisirOptionMenu();
	void lireCarte();
	void afficherCarte();
	void determinerFrontieres();
	void determinerPlusCourtChemin();
	void reinitialiserJeu();

	void setCouleurAEviter(char couleurAEviter);

	bool carteLue_;
	bool frontieresDeterminees_;
	std::string nomFichier_;
	std::string paysOrigine_;
	std::string paysDestination_;
	char couleurAEviter_;
	std::shared_ptr<Carte> carte_;

	std::unique_ptr<Ui_Form_Exploration> uiExploration_;
	std::unique_ptr<ExtractionGraphe> extractionDialog_;

signals:
	void windowClosed();
};



#endif