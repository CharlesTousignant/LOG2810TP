#include "sommet.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, const Sommet& sommet){
    os << sommet.getNom();

	return os;
}

void Sommet::afficher(ostream& os) const{
    os << "(" << *this << ", " << couleur_ << ", (";

    // On itere jusqu'a 1 de la fin pour les virgules
    for (int i = 0; i < (int) arretes_.size() - 1; i++) {
        os << *(arretes_[i].first.get()) << ", ";
    }
    // On rajoute le dernier sommet
    os << *(arretes_[arretes_.size() - 1].first.get()) << "))" << '\n';
}

Sommet::Sommet(string nom) : couleur_('n'), nom_(nom) {};


//retourne false si le voisin a ajouter existe deja, true sinon
bool Sommet::addNeighbor(shared_ptr<Sommet>& sommet, int distance){

//    shared_ptr<Sommet> sommetAAjouter = make_shared<Sommet>(sommet);

    for (pair<shared_ptr<Sommet>, int> &arrete : arretes_) {
        if (arrete.first == sommet) {
            return false;
        }
    }

    arretes_.push_back(make_pair(sommet, distance));
    return true;
}

Sommet* Sommet::removeNeighbor(char color){
    
    if(couleur_ == color){
        return nullptr;
    }

    Sommet* sommetVoisinsEnleves = new Sommet(nom_);
    sommetVoisinsEnleves->setCouleur(couleur_);

    for(pair<shared_ptr<Sommet>, int> &arrete : arretes_){
        shared_ptr<Sommet> sommet = arrete.first;
        if(sommet.get()->getCouleur() != color){
			shared_ptr<Sommet> newSommet = make_shared<Sommet>(sommet->getNom());
            newSommet->setCouleur(sommet->getCouleur());

            sommetVoisinsEnleves->addNeighbor(newSommet, arrete.second);
        }
    }

    return sommetVoisinsEnleves;
}



char Sommet::getCouleur() const {
    return couleur_;
}

void Sommet::setCouleur(char couleur) {
    couleur_ = couleur;
}

std::string Sommet::getNom() const {
    return nom_;
}

void Sommet::setNom(std::string nom) {
    nom_ = nom;
}

int Sommet::getSize() const {
    return arretes_.size();
}

//retourne true si le sommet est adjacent a au moins un sommet de la couleur en parametre
bool Sommet::adjacentACouleur(char couleur) {
    for (std::pair<std::shared_ptr<Sommet>, int>& arrete : arretes_) {
        if (couleur == arrete.first->getCouleur()) {
            return true;
        }
    }

    return false;
}