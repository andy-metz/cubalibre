#ifndef SEGMENT_HPP_INCLUDED
#define SEGMENT_HPP_INCLUDED

/**
*   @file    Segment.hpp Segment.cpp
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
*   Classe segment pour représenter un segment en 2D.
*
*/

#include "Forme.hpp"
#include "Vecteur2D.hpp"

class Segment : public Forme{
private :
	Vecteur2D a, b;

public :

	Segment();
	Segment(const Segment &S);
	Segment(const Vecteur2D A,const Vecteur2D B, Color couleur=CYAN);
	Segment(const string&s);
	~Segment();

	void accept(FormeVisiteur*fv);

	double getTaille() const;
	const Vecteur2D getA() const;
	const Vecteur2D getB() const;

	void setA(const Vecteur2D &A);
	void setB(const Vecteur2D &B);

    operator string()const;
	friend ostream&operator<<(ostream&stream,const Segment&s);
};


#endif // SEGMENT_HPP_INCLUDED
