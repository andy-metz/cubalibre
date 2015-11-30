#ifndef POLYGONE_HPP_INCLUDED
#define POLYGONE_HPP_INCLUDED


/**
*   @file    Polygone.hpp Polygone.cpp
*   @author  Jérôme Lartillot Olivier Mertz André Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -iostream
*   -string
*   -cmath
*   -cstdio
*   -std namespace
*
*   @section DESCRIPTION
*
*   @class Polygone
*	Classe pour représenter un polygone en 2D.
*
*/


#include"Vecteur2D.hpp"
#include <vector>
#include "Forme.hpp"



using namespace std;

/**
*
*	@class Polygone
*	Représente un polygone
*
*/
class Polygone : public Forme
{
private:

	vector<Vecteur2D> points;

public :

	Polygone();
	Polygone(const vector<Vecteur2D> tab_point,Color couleur);
	Polygone(const Polygone &P);
	Polygone(const string &s);
	~Polygone();

    void accept(FormeVisiteur*fv);

	void setPoints(const vector<Vecteur2D> &nouv_points);
	const vector<Vecteur2D> getPoints() const;

	double calculerAire() const;

	operator string() const;
	friend ostream&operator<<(ostream&stream, const Polygone &p);
};

#endif
