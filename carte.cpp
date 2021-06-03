#include "carte.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std; 


Carte::Carte(const Carte& carte)
{	
	
	if (this != &carte) {
		for (const auto &sommet : carte.sommets_) {
			sommets_.insert(make_pair(sommet.second->getNom(), make_shared<Sommet>(sommet.second->getNom())));
		}
	}
}

// cr�er le graphe � partir du fichier de donn�es
void Carte::creerGraphe(const std::string& nomFichier){
	std::ifstream fichier;
	fichier.open(".\\data_partie2\\" + nomFichier);
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
		while (iss.peek()!=EOF) {
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
	for(const auto& sommet: sommets_){
		sommet.second->afficher();
	}
}

// affecter une couleur aux sommets
void Carte::colorierGraphe() {
	auto compare = [](const std::shared_ptr<Sommet> &a,const std::shared_ptr<Sommet> &b) -> bool {
		return a->getSize() > b->getSize();
	};

	vector<shared_ptr<Sommet>> carteCopie;
	for (auto& sommet: sommets_) {
		carteCopie.push_back(sommet.second);
	}

	sort(carteCopie.begin(), carteCopie.end(), compare);
	for (char couleur : {'r', 'b', 'v', 'j'}) {
		for (shared_ptr<Sommet> &sommet : carteCopie) {
			if (sommet->getCouleur() == 'n' && !sommet->adjacentACouleur(couleur)) {
				sommet->setCouleur(couleur);
			}
		}
	}
}

void Carte::addSommet(Sommet& sommet){
	sommets_.insert(pair<string, shared_ptr<Sommet>>(sommet.getNom(), make_shared<Sommet>(sommet.getNom())));
}

//void Carte::removeColor(char colorToRemove) {
//	for(auto sommet : sommets_){
//		if (sommet.second->getCouleur() == colorToRemove) { 
//			sommets_.erase(sommet.first); 
//		}
//	}
//}

/* Extraire le sous-graphe resultant d�un
graphe colore, auquel on veut retirer une certaine couleur pass�ee en param`etre. Si la couleur
passee en parametre n�a pas ete utilisee, afficher une erreur. */
Carte Carte::extractionGraphe(char colorToExtract){
	bool foundColor = false;
	Carte carteExtraite = Carte();

	for(auto &sommet : sommets_){
		Sommet* sommetToAdd = sommet.second->removeNeighbor(colorToExtract);
		// Si le sommet n'etait pas lui-meme de la mauvaise couleure, on le garde
		if (sommetToAdd) {
			carteExtraite.addSommet(make_shared<Sommet>(sommetToAdd));
		}
	}

	return Carte(carteExtraite);
}

// retourner le plus court chemin
void Carte::plusCourtChemin() {};