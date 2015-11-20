#include"Transformation.hpp"

/**
*   Cr�e une rotation CCW � partir d'un angle.
*   @param angle: L'angle de rotation EN RADIANS
*/
Rotation::Rotation(const double angle):
    cosinus(cos(angle)),
    sinus(sin(angle))
{}

/**
*   Cr��e une rotation CCW � partir d'un point.
*   @param v: le point du plan.
*   La rotation sera d�finie par l'angle (O(1,0),Ov);
*/
Rotation::Rotation(const Vecteur2D&v):
    cosinus(cos(atan2(v.getY(),v.getX()))),
    sinus(sin(atan2(v.getY(),v.getX())))
{}

/**
*   Applique une rotation � un vecteur.
*   @param v: le vecteur � tourner.
*   @return Le vecteur tourn�.
*/
const Vecteur2D Rotation::applyTo(Vecteur2D&v)const
{
    Vecteur2D resultat(v.getX()*cosinus-v.getY()*sinus,
                       v.getX()*sinus+v.getY()*cosinus);
    v=resultat;
    return resultat;
}


/**
*   Cr�e une Translation.
*   @param x_: la composante horizontale de la translation.
*   @param y_: la composante Verticale de la translation.
*/
Translation::Translation(const double x_,const double y_):
    x(x_),
    y(y_)
{}

/**
*   Applique une translation � un vecteur.
*   @param v: le vecteur � d�placer.
*   @return Le vecteur d�plac�.
*/
const Vecteur2D Translation::applyTo(Vecteur2D&v)const{
    Vecteur2D resultat(v.getX()+x,v.getY()+y);
    v=resultat;
    return resultat;
}

/**
*   Cr��e une homoth�tie.
*   @param xscale: le multiplicateur sur x.
*   @param yscale: le multiplicateur sur y.
*/
Homothetie::Homothetie(const double xscale,const double yscale):
    x(xscale),
    y(yscale)
{}

/**
*   Applique une homoth�tie � un vecteur.
*   @param v: le vecteur � redimensionner.
*   @return Le vecteur redimensionn�.
*/
const Vecteur2D Homothetie::applyTo(Vecteur2D&v)const{
    Vecteur2D resultat(v.getX()*x,v.getY()*y);
    v=resultat;
    return resultat;
}
