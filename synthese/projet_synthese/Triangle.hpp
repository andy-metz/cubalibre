#ifndef TRIANGLE_HPP_INCLUDED
#define TRIANGLE_HPP_INCLUDED


/**
*   @file    Triangle.hpp Triangle.cpp
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
*   Classe Triangle pour représenter un triangle en 2D.
*
*
*/

#include"Forme.hpp"
#include"Vecteur2D.hpp"
/**
*
*	@class Triangle
*	Représente un Triangle
*
*/
class Triangle : public Forme{
private:
	Vecteur2D p1,p2,p3;

public :
		Triangle();
		Triangle(Vecteur2D point1, Vecteur2D point2, Vecteur2D point3, Color couleur);
		Triangle(const Triangle &T);
		Triangle(const string &s);
		~Triangle();

        void accept(FormeVisiteur*fv);

		void setPoints1(const Vecteur2D &point1);
		void setPoints2(const Vecteur2D &point2);
		void setPoints3(const Vecteur2D &point3);

		const Vecteur2D getPoints1() const;
		const Vecteur2D getPoints2() const;
		const Vecteur2D getPoints3() const;

		double calculerAire() const;

		operator string()const;
		friend ostream&operator<<(ostream&stream, const Triangle &t);
};




#endif //TRIANGLE_HPP_INCLUDED
