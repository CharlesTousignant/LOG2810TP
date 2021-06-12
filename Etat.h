//#ifndef ETAT
//#define ETAT
//
//#include <string>
//#include <stdio.h>
//#include <vector>
//#include <string>
//#include <utility>
//#include <memory>
//#include <unordered_map>
//
//class Etat;
//
//class Etat {
//public:
//	Etat(char name, bool isValidWord);
//	void addTransition(char charTransition, bool isTerminal);
//
//	pair<bool, Etat> transition(char charTransition, bool isTerminal);
//	std::string getNom() const;
//	bool isTerminal() const;
//private:
//	std::unordered_map <char, std::shared_ptr<Etat>> transitions_;
//	std::string nom_;
//	bool isTerminal;
//};
//
//#endif