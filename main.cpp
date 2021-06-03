#include <iostream>
#include <string>
#include <stdio.h>

#include <assert.h>
#include <sstream>  

#include "sommet.h"
#include "carte.h"
#include "test.cpp"
using namespace std;

int main() {
	shared_ptr<Sommet> canada = make_shared<Sommet>("Canada");
    shared_ptr<Sommet> usa = make_shared<Sommet>("USA");

    canada->addNeighbor(usa, 1);
    usa->addNeighbor(canada, 1);

    stringstream attendu;
    stringstream recu;

    attendu << "(Canada, n, (USA))\n";
    canada->afficher(recu);

    assert(attendu.str() == recu.str());

    attendu.clear();
    recu.clear();
    attendu << "(USA, n, (Canada))\n";
    usa->afficher(recu);

    assert(attendu.str() == recu.str());



	shared_ptr<Carte> carteTest = make_shared<Carte>();
	carteTest->creerGraphe("grapheCanada.txt");
	//carteTest->lireGraphe();
	
	carteTest->colorierGraphe();
	//carteTest->lireGraphe();

	Carte carteSansRouge = carteTest->extractionGraphe('r');
	carteSansRouge.lireGraphe();


    // runAllTests();
}