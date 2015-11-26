#ifndef TRANSFORMERVISITEUR_HPP_INCLUDED
#define TRANSFORMERVISITEUR_HPP_INCLUDED

#include"FormeVisiteur.hpp"
#include"Transformation.hpp"

#include"Cercle.hpp"
#include"Segment.hpp"
#include"Polygone.hpp"
#include"Triangle.hpp"
//#include"Goupe.hpp"


class TransformerVisiteur: public FormeVisiteur
{
    private:
    Transformation*t;
    public:
    TransformerVisiteur(const Transformation*t_);
    void visit( Triangle * triangle);
	void visit( Polygone * polygone);
	void visit( Segment * segment);
	void visit( Cercle * cercle);
};

#endif // TRANSFORMERVISITEUR_HPP_INCLUDED
