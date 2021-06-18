
#ifndef CARTE
#define CARTE

#include <string>
#include <stdio.h>
#include <vector>
#include <string>
#include <memory>
#include "sommet.h"
#include <map>

class Carte {
public:
	Carte() = default;
	Carte(const Carte& carte);
	bool creerGraphe(const std::string& nomFichier);
	void lireGraphe(std::ostream& os) const;
	void colorierGraphe();

	Carte extractionGraphe(char colorToExtract);
	void plusCourtChemin(std::string source, std::string destination, std::ostream& os);

private:
	//void removeColor(char colorToRemove);
	void addSommet(Sommet& sommet);
	void addSommet(std::shared_ptr<Sommet> sommet);

	std::map<std::string, std::shared_ptr<Sommet>> sommets_;
};



#endif