#ifndef CHARGEMENT_HPP_INCLUDED
#define CHARGEMENT_HPP_INCLUDED
#include "Forme.hpp"
/**
*   @file    ChargementForme.hpp 
*   @author  J�r�me Lartillot Olivier Mertz Andr� Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -Forme.hpp
*   -std namespace
*
*   @section DESCRIPTION
*
*   Classe abstratie ChargementForme pour d�finir une chaine de responsabilit�
*
*/
class ChargementForme {

public:	
	/**
	*transforme texte en une forme par une chaine de responsabilit�
	*Convention : en cas d'�chec (format non reconnu) retourne NULL
	*/
	virtual Forme* charge(const string texte) const = 0;



};
#endif