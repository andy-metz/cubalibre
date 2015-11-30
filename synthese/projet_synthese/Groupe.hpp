#ifndef GROUPE_HPP_INCLUDED
#define GROUPE_HPP_INCLUDED

#include <vector>
#include "Cercle.hpp"
#include "Segment.hpp"
#include "Triangle.hpp"
#include "Polygone.hpp"

using namespace std;

/**
*   @file    Groupe.hpp Groupe.cpp
*   @author  Jérôme Lartillot Olivier Mertz André Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -Forme
*   -vector
*	-string
*   -std namespace
*
*   @section DESCRIPTION
*
*   @class Groupe
*	Classe pour représenter un groupe , qui représente un sensemble de formes simples
*
*/
class Groupe :public Forme{
private: vector<Forme*> liste_forme;

public:
	Groupe();
	Groupe(const Groupe &G);
	Groupe(const vector<Forme*> liste);
	Groupe(const vector<Forme*> liste, Color couleur);
	Groupe(const string &s);
	~Groupe();

	void accept(FormeVisiteur*fv);

	void setFormes(const vector<Forme*> liste);
	void addForme(Forme * F);
	const vector<Forme*> getFormes()const;

	double calculerAire() const;

	operator string() const;
	friend ostream&operator<<(ostream&stream, const Groupe &G);
};
#endif