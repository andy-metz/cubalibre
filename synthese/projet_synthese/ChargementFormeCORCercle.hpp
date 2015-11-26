#ifndef CHARGEMENTFORMECORCERCLE_HPP_INCLUDED
#define CHARGEMENTFORMECORCERCLE_HPP_INCLUDED
#include"ChargementFormeCOR.hpp"
#include"Cercle.hpp"
/**
*   @file    ChargementFormeCORCercle.hpp ChargementFormeCORCercle.cpp
*   @author  Jérôme Lartillot Olivier Mertz André Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -ChargementFormeCOR.hpp
*   -Cercle.hpp
*
*   @section DESCRIPTION
*
*   Classe ChargementFormeCORCercle pour définir un expert cercle du design pattern COR
*
*/
class ChargementFormeCORCercle : public ChargementFormeCOR{
	ChargementFormeCOR * suivant;
public :
	ChargementFormeCORCercle(ChargementFormeCOR * suivant);

	Forme * chargeExpertise(const string texte) const;
	
};
#endif