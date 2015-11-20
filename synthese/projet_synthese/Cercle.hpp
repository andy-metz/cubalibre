#ifndef CERCLE_HPP_INCLUDED
#define CERCLE_HPP_INCLUDED
#define M_PI       3.14159265358979323846

/**
*   @file    Cercle.hpp Cercle.cpp
*   @author  Jérôme Lartillot Olivier Mertz Alain Erba
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
*   Classe Cercle pour définir un cercle.
*
*/


#include "Forme.hpp"
#include "Vecteur2D.hpp"

using namespace std;

/**
*
*	@class Cercle
*	Représente un cercle
*
*/
class Cercle : public Forme{

	private:
	Vecteur2D centre;
	double rayon;

public:
	Cercle();
	Cercle(Color couleur, Vecteur2D point, double r);
	Cercle(const Cercle &c);
	Cercle(const string&s);
	~Cercle();

    void accept(FormeVisiteur*fv);

	const double getRayon() const;
	const Vecteur2D getCentre() const;

	void setCentre(const Vecteur2D &nouv_point);
	void setRayon(const double &nouv_rayon);

	double calculerAire() const;

	operator string()const;
	friend ostream&operator<<(ostream&stream,const Cercle&c);
};

#endif CERCLE_HPP_INCLUDED

