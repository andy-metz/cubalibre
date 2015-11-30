#ifndef SAUVEGARDETXT_HPP_INCLUDED
#define SAUVEGARDETXT_HPP_INCLUDED
#include "FormeVisiteur.hpp"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Cercle.hpp"
#include "Triangle.hpp"
#include "Segment.hpp"
#include "Polygone.hpp"
#include "Groupe.hpp"
/**
*	@file SauvegardeTxt.hpp
*	@author Lartillot mertz erba
*
*	@class sauvegarde
*	Class permettant de sauvegarder une forme
*
*/

class SauvegardeTxt : public FormeVisiteur{
private:
	int x = 0;
	void setCompteur();
public:
	/*virtual*/	void visit(Triangle * T);
	/*virtual*/	void visit(Polygone * P);
	/*virtual*/	void visit(Segment * S);
	/*virtual*/	void visit(Cercle * C);
	/*virutal*/ void visit(Groupe *G);


};

#endif
