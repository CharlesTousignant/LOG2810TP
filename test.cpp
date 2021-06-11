//#include <assert.h>
//#include <sstream>  

//#include "sommet.h"
//#include "carte.h"

//using namespace std;


//void testCreationSommet(){
//    //Sommet canada("Canada");
//    //Sommet usa("USA");

//	shared_ptr<Sommet> canada = make_shared<Sommet>("Canada");
//    shared_ptr<Sommet> usa = make_shared<Sommet>("USA");

//    canada->addNeighbor(usa, 1);
//    usa->addNeighbor(canada, 1);

//    stringstream attendu;
//    stringstream recu;

//    attendu << "(Canada, n, (USA))";
//    canada->afficher(recu);

//    assert(attendu.str() == recu.str());

//    attendu.clear();
//    recu.clear();
//    attendu << "(USA, n, (Canada))";
//    usa->afficher(recu);

//    assert(attendu.str() == recu.str());
//}


////void runAllTests(){
////    testCreationSommet();
////}