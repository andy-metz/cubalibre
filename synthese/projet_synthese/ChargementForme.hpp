#ifndef CHARGEMENT_HPP_INCLUDED
#define CHARGEMENT_HPP_INCLUDED
#include "Forme.hpp"
/**
*   @file    ChargementForme.hpp 
*   @author  Jérôme Lartillot Olivier Mertz André Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -Forme.hpp
*   -std namespace
*
*   @section DESCRIPTION
*
*   Classe abstratie ChargementForme pour définir une chaine de responsabilité
*
*/
class ChargementForme {

public:	
	/**
	*transforme texte en une forme par une chaine de responsabilité
	*Convention : en cas d'échec (format non reconnu) retourne NULL
	*/
	virtual Forme* charge(const string texte) const = 0;



};
#endif