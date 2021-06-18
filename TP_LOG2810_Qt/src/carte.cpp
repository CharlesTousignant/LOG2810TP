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
		for (const auto& sommet : carte.sommets_) {
			sommets_.insert(pair<string, shared_ptr<Sommet>>(sommet.second->getNom(), sommet.second));
		}
	}
}

// cr�er le graphe � partir du fichier de donn�es
bool Carte::creerGraphe(const std::string& nomFichier) {
	std::ifstream fichier;
	fichier.open(".\\data_partie1\\" + nomFichier);
	string line;

	if (fichier) {
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
		while (iss.peek() != EOF) {
			getline(iss, nomSommet1, ',');
			getline(iss, nomSommet2, ',');
			iss >> distance;
			iss.ignore();

			shared_ptr<Sommet> sommet1 = sommets_.find(nomSommet1)->second;
			shared_ptr<Sommet> sommet2 = sommets_.find(nomSommet2)->second;
			sommet1->addNeighbor(sommet2, distance);
			sommet2->addNeighbor(sommet1, distance);
		}
		return true;
	}
	else {
		cout << "Erreur d'ouverture." << endl;
		return false;
	}
}

// afficher le graphe
void Carte::lireGraphe() const {
	for (const auto& sommet : sommets_) {
		sommet.second->afficher();
	}
}

// affecter une couleur aux sommets
void Carte::colorierGraphe() {
	auto compare = [](const std::shared_ptr<Sommet>& a, const std::shared_ptr<Sommet>& b) -> bool {
		return a->getSize() > b->getSize();
	};

	vector<shared_ptr<Sommet>> carteCopie;
	for (auto& sommet : sommets_) {
		carteCopie.push_back(sommet.second);
	}

	sort(carteCopie.begin(), carteCopie.end(), compare);
	for (char couleur : {'r', 'b', 'v', 'j'}) {
		for (shared_ptr<Sommet>& sommet : carteCopie) {
			if (sommet->getCouleur() == 'n' && !sommet->adjacentACouleur(couleur)) {
				sommet->setCouleur(couleur);
			}
		}
	}
}

void Carte::addSommet(Sommet& sommet) {
	sommets_.insert(pair<string, shared_ptr<Sommet>>(sommet.getNom(), make_shared<Sommet>(sommet.getNom())));
}

void Carte::addSommet(shared_ptr<Sommet> sommet) {
	sommets_.insert(pair<string, shared_ptr<Sommet>>(sommet->getNom(), sommet));
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
Carte Carte::extractionGraphe(char colorToExtract) {
	bool foundColor = false;
	Carte carteExtraite = Carte();

	for (auto& sommet : sommets_) {
		if (sommet.second->getCouleur() != colorToExtract) {
			shared_ptr<Sommet> sommetToAdd = sommet.second->removeNeighbor(colorToExtract);
			carteExtraite.addSommet(sommetToAdd);
		}
		else {
			foundColor = true;
		}
	}

	if (!foundColor) {
		cout << "La couleur '" << colorToExtract << "' n'a pas ete trouvee. \n";
	}
	return Carte(carteExtraite);
}

// retourner le plus court chemin
void Carte::plusCourtChemin(string source, string destination) {

	bool sourceExiste = false;
	bool destinationExiste = false;
	
	for (auto& sommet: sommets_) {
		if (sommet.second->getNom() == source) {
			sourceExiste = true;
		}
		if (sommet.second->getNom() == destination) {
			destinationExiste = true;
		}
	}

	if (!sourceExiste & !destinationExiste) {
		cout << "Veuillez entrer une source et une destination valides.\n";
		return;
	} else if (!sourceExiste) {
		cout << "Veuillez entrer une source valide.\n";
		return;
	} else if (!destinationExiste) {
		cout << "Veuillez enter une destination valide.\n";
		return;
	}

	map<string, shared_ptr<pair<int, vector<string>>>> longueurs;
	for (auto& sommet : sommets_) {
		longueurs.insert(make_pair(sommet.first, make_shared<pair<int, vector<string>>>(make_pair(INT_MAX, vector<string>()))));
	}
	map<string, shared_ptr<pair<int, vector<string>>>>::iterator sommetSource = longueurs.find(source);
	sommetSource->second->first = 0;
	sommetSource->second->second.push_back(sommetSource->first);

	map<string, shared_ptr<pair<int, vector<string>>>> ensemble;
	//ensemble.insert(*it);

	while (ensemble.find(destination) == ensemble.end()) {
		//trouver le sommet non dans ensemble avec chemin minimal
		pair<string, shared_ptr<pair<int, vector<string>>>> sommetMinimal = make_pair(" ", make_shared<pair<int, vector<string>>>(make_pair(INT_MAX, vector<string>())));
		sommetMinimal.second->first = INT_MAX;
		for (auto& sommet : longueurs) {
			if (ensemble.find(sommet.first) == ensemble.end()) {
				if (sommet.second->first < sommetMinimal.second->first) {
					sommetMinimal = sommet;
				}
			}
		}
		//si la longueur reste INT_MAX, le graphe n'est pas connexe 
		if (sommetMinimal.second->first == INT_MAX) {
			cout << "Il n'existe pas de chemin entre votre origine est votre destination. \n" ;
			return;
		}
		ensemble.insert(sommetMinimal);

		//map<string, shared_ptr<Sommet>>::iterator itMin = sommets_.find(sommetMinimal.first);
		for (auto& voisin : sommets_.find(sommetMinimal.first)->second->getArretes()) {
			if (ensemble.find(voisin.first->getNom()) == ensemble.end()) {
				if (longueurs.find(sommetMinimal.first)->second->first + voisin.second < longueurs.find(voisin.first->getNom())->second->first) {
					longueurs.find(voisin.first->getNom())->second->first = longueurs.find(sommetMinimal.first)->second->first + voisin.second;
					longueurs.find(voisin.first->getNom())->second->second = longueurs.find(sommetMinimal.first)->second->second;
					longueurs.find(voisin.first->getNom())->second->second.push_back(voisin.first->getNom());
				}
			}
		}
	}
	cout << "Le chemin de cout minimal est: \n";
	vector<string> chemin = ensemble.find(destination)->second->second;
	for (int i = 0; i < chemin.size() - 1; i++) {
		cout << chemin.at(i) << " -> ";
	}
	cout << chemin.at(chemin.size() - 1) << ".\n";
};