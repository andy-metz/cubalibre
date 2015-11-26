#include"TransformerVisiteur.hpp"

/*
class TransformerVisiteur: public FormeVisiteur
{
    TransformerVisiteur(const Transformation*t);
    void visite(const Triangle * Forme);
	void visite(const Polygone * Forme);
	void visite(const Segment * Forme);
	void visite(const Cercle * Forme);
};
*/

TransformerVisiteur::TransformerVisiteur(const Transformation*t_)
{
    t=const_cast<Transformation*>(t_);
}
void TransformerVisiteur::visit(Triangle * triangle)
{
    Vecteur2D p1=triangle->getPoints1(),
              p2=triangle->getPoints2(),
              p3=triangle->getPoints3();

    p1=t->applyTo(p1);
    p2=t->applyTo(p2);
    p3=t->applyTo(p3);

    Triangle resultat(p1,p2,p3,triangle->getColor());

    (*triangle)=resultat;
}
void TransformerVisiteur::visit(Polygone * polygone)
{
    vector<Vecteur2D>pts=polygone->getPoints();
    vector<Vecteur2D>::iterator i=pts.begin();
    for(i;i < pts.end();i++)
    {
        (*i)=t->applyTo(*i);
    }
}
void TransformerVisiteur::visit(Segment * segment)
{
    Vecteur2D v1=segment->getA();
    Vecteur2D v2=segment->getB();
    v1=t->applyTo(v1);
    v2=t->applyTo(v2);
    segment->setA(v1);
    segment->setB(v2);
}
void TransformerVisiteur::visit(Cercle * cercle)
{

}




















