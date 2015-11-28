#ifndef TRANSFORMATION_HPP_INCLUDED
#define TRANSFORMATION_HPP_INCLUDED

#include "Vecteur2D.hpp"
#include<cmath>

/**
*   @file    Vecteur2D.hpp Vecteur2D.cpp
*   @author  J�r�me Lartillot Olivier Mertz Andr� Erba
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
*   Contient toutes les classes n�c�ssaires aux transformations.
*
*   @section CODE POUR TESTER
*
*
    Vecteur2D v(0.0,1.0);

    Translation t(1.0,-1.0);
    Homothetie h(2.0,2.0);
    Rotation r(3.14*0.25);

    cout<<v<<endl;
    t.applyTo(v);
    cout<<v<<endl;
    h.applyTo(v);
    cout<<v<<endl;
    r.applyTo(v);
    cout<<v<<endl;
*/

/**
*   @class Transformation
*   D�crit une transformation (rotation homoth�tie translation)
*   Et permet de l'appliquer � un Vecteur2D
*/
class Transformation
{
    public:
    virtual const Vecteur2D applyTo(Vecteur2D&v)const=0;
};

/**
*   @class Rotation
*   D�crit une rotation.
*   H�rite de Transformation.
*/
class Rotation:public Transformation
{
    double cosinus,sinus;
public:
    Rotation(const double angle=0);
    Rotation(const Vecteur2D&v);

    const Vecteur2D applyTo(Vecteur2D&v)const;
};

/**
*   @class Translation
*   D�crit une rotation.
*   H�rite de Translation.
*/
class Translation:public Transformation
{
    double x,y;
public:
    Translation(const double x_=0,const double y_=0);

    const Vecteur2D applyTo(Vecteur2D&v)const;
};

/**
*   @class Homothetie
*   D�crit une rotation.
*   H�rite de Homothetie.
*/
class Homothetie:public Transformation
{
    double x, y;
public:
    Homothetie(const double xscale=1.0,const double yscale=1.0);

    const Vecteur2D applyTo(Vecteur2D&v)const;
};




#endif // TRANSFORMATION_HPP_INCLUDED
