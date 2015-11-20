#ifndef SAUVEGARDE_HPP_INCLUDED
#define SAUVEGARDE_HPP_INCLUDED
#include "FormeVisiteur.hpp"
#include <sstream>
#include <fstream>




/**
*	@file SauvegardeTxt.hpp
*	@author Lartillot mertz erba
*
*	@Class sauvegarde
*	Class permettant de sauvegarder une forme
*
*/

class SauvegardeTxt : public FormeVisiteur{

public:
	//void sauvegarder(	);

	virtual void  sauvegarder( Cercle * C);
	virtual void  sauvegarder( Triangle * T);
	virtual void  sauvegarder( Polygone * P);
	virtual void  sauvegarder( Segment * S);
};

#endif