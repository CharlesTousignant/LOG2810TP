
#ifndef JEUINSTRUCTIF
#define JEUINSTRUCTIF

#include <string>
//#include "automate.h"

class JeuInstructif {
public:
	JeuInstructif();
	void lancer();
	void saisirTexte(bool isSuggerer, bool isCorriger);

private:
	char choisirOptionMenu();
	void initialiserJeu();
	bool verifierMotFini();
	void entrerLettre(std::string& mot);


	bool lexiqueLu_;
	//std::shared_ptr<Automate> automate_;
};



#endif