#ifndef SOMMET
#define SOMMET

#include <string>
#include <stdio.h>
#include <vector>
#include <utility>
#include <memory>
#include <iostream>
//using namespace std;

class Sommet;

std::ostream& operator<<(std::ostream& os, const Sommet& sommet);


class Sommet {

public:
	Sommet(std::string nom);
	~Sommet() = default;

	bool addNeighbor(std::shared_ptr<Sommet> sommet, int distance );

	char getCouleur() const;
	void setCouleur(char couleur);

	std::string getNom() const;
	void setNom(std::string nom);

	std::shared_ptr<Sommet> removeNeighbor(char color);

	void afficher(std::ostream& os = std::cout) const;

	int getSize() const;

	bool adjacentACouleur(char couleur);
	std::vector<std::pair<std::shared_ptr<Sommet>, int>> getArretes() const;

	std::vector<std::pair<std::shared_ptr<Sommet>, int>> getArretes() const;

private:
	std::vector<std::pair<std::shared_ptr<Sommet>, int>> arretes_;
	char couleur_;
	std::string nom_;
};



#endif
