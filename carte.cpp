#include "carte.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// créer le graphe à partir du fichier de données
void Carte::creerGraphe(const std::string& nomFichier){
	std::ifstream fichier;
	fichier.open("data_partie1/" + nomFichier);
	string line;

    if(fichier){
		stringstream iss;
		string nomSommet;
		getline(fichier, line);
		iss << line;
		while (getline(iss, nomSommet, ';')) {
			sommets_.insert(make_pair(nomSommet, make_shared<Sommet>(nomSommet)));
		}
		
		string nomSommet1;
		string nomSommet2;
		int distance;

		getline(fichier, line);
		iss.clear();
		iss << line;
		while (!iss.eof()) {
			getline(iss, nomSommet1, ',');
			getline(iss, nomSommet2, ',');
			iss >> distance;
			iss.ignore();

			shared_ptr<Sommet> sommet1 = sommets_.find(nomSommet1)->second;
			shared_ptr<Sommet> sommet2 = sommets_.find(nomSommet2)->second;
			sommet1->addNeighbor(sommet2, distance);
			sommet2->addNeighbor(sommet1, distance);
		}
	}
	else {
		cout << "Erreur d'ouverture." << endl;
	}
}

// afficher le graphe
void Carte::lireGraphe() const {
	for(auto sommet: sommets_){
		sommet.second->afficher();
	}
}

// affecter une couleur aux sommets
void Carte::colorierGraphe() {
	auto compare = [](std::shared_ptr<Sommet> a, std::shared_ptr<Sommet> b) {
		return a->getSize() > b->getSize();
	};
	
	sort(sommets_.begin(), sommets_.end(), compare);
	for (char couleur : {'r', 'b', 'v', 'j'}) {
		for (pair<string, shared_ptr<Sommet>> sommet : sommets_) {
			if (sommet.second->getCouleur() == 'n' && !sommet.second->adjacentACouleur(couleur)) {
				sommet.second->setCouleur(couleur);
			}
		}
	}
}

void addSommet(Sommet& sommet){
	sommets_.insert({ sommet.getCouleur(), make_shared<Sommet>(&sommet) });
}

void Carte::removeColor(char colorToRemove) {
	for(auto sommet : sommets_){
		sommet.removeSommet(sommet);
	}
}

/* Extraire le sous-graphe resultant d’un
graphe colore, auquel on veut retirer une certaine couleur pass´ee en param`etre. Si la couleur
passee en parametre n’a pas ete utilisee, afficher une erreur. */
Carte Carte::extractionGraphe(char colorToExtract){
	bool foundColor = false;
	Carte* carteExtraite = new Carte();

	for(auto sommet : sommets_){
		Sommet* sommetToAdd = sommet.second->removeNeighbor(colorToExtract);
		// Si le sommet n'etait pas lui-meme de la mauvaise couleure, on le garde
		if (sommetToAdd) {
			carteExtraite.addSommet(sommetToAdd);
		}
	}

	return carteExtraite;
}

// retourner le plus court chemin
void Carte::plusCourtChemin();