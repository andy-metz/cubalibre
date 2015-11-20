#include"Transformation.hpp"

/**
*   Crée une rotation CCW à partir d'un angle.
*   @param angle: L'angle de rotation EN RADIANS
*/
Rotation::Rotation(const double angle):
    cosinus(cos(angle)),
    sinus(sin(angle))
{}

/**
*   Créée une rotation CCW à partir d'un point.
*   @param v: le point du plan.
*   La rotation sera définie par l'angle (O(1,0),Ov);
*/
Rotation::Rotation(const Vecteur2D&v):
    cosinus(cos(atan2(v.getY(),v.getX()))),
    sinus(sin(atan2(v.getY(),v.getX())))
{}

/**
*   Applique une rotation à un vecteur.
*   @param v: le vecteur à tourner.
*   @return Le vecteur tourné.
*/
const Vecteur2D Rotation::applyTo(Vecteur2D&v)const
{
    Vecteur2D resultat(v.getX()*cosinus-v.getY()*sinus,
                       v.getX()*sinus+v.getY()*cosinus);
    v=resultat;
    return resultat;
}


/**
*   Crée une Translation.
*   @param x_: la composante horizontale de la translation.
*   @param y_: la composante Verticale de la translation.
*/
Translation::Translation(const double x_,const double y_):
    x(x_),
    y(y_)
{}

/**
*   Applique une translation à un vecteur.
*   @param v: le vecteur à déplacer.
*   @return Le vecteur déplacé.
*/
const Vecteur2D Translation::applyTo(Vecteur2D&v)const{
    Vecteur2D resultat(v.getX()+x,v.getY()+y);
    v=resultat;
    return resultat;
}

/**
*   Créée une homothétie.
*   @param xscale: le multiplicateur sur x.
*   @param yscale: le multiplicateur sur y.
*/
Homothetie::Homothetie(const double xscale,const double yscale):
    x(xscale),
    y(yscale)
{}

/**
*   Applique une homothétie à un vecteur.
*   @param v: le vecteur à redimensionner.
*   @return Le vecteur redimensionné.
*/
const Vecteur2D Homothetie::applyTo(Vecteur2D&v)const{
    Vecteur2D resultat(v.getX()*x,v.getY()*y);
    v=resultat;
    return resultat;
}
