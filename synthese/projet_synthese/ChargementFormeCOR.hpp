#ifndef CHARGEMENTCOR_HPP_INCLUDED
#define CHARGEMENTCOR_HPP_INCLUDED
#include "ChargementForme.hpp"
#include <iostream>
#include <fstream>

/**
*   @file    ChargementFormeCOR.hpp ChargementFormeCOR.cpp
*   @author  Jérôme Lartillot Olivier Mertz André Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -iostream
*   -string
*   -fstream
*   -std namespace
*
*   @section DESCRIPTION
*
*   Classe ChargementFormeCOR pour définir une chaine de responsabilité
*
*/
class ChargementFormeCOR : public ChargementForme{

	ChargementFormeCOR * suivant;
public :
	ChargementFormeCOR(ChargementFormeCOR * suivant);
	Forme * charge(const string texte) const;

	virtual Forme* chargeExpertise(const string texte) const = 0;
};


#endif