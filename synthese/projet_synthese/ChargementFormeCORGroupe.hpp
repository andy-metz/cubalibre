#ifndef CHARGEMENTFORMECORGROUPE_HPP_INCLUDED
#define CHARGEMENTFORMECORGROUPE_HPP_INCLUDED
#include "ChargementFormeCOR.hpp"
#include "Groupe.hpp"
/**
*   @file    ChargementFormeCORGroupe.hpp ChargementFormeCORGroupe.cpp
*   @author  Jérôme Lartillot Olivier Mertz André Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -ChargementFormeCOR.hpp
*   -Groupe.hpp
*
*   @section DESCRIPTION
*
*   @class ChargementFormeCORGroupe pour définir un expert groupe du design pattern COR
*/
class ChargementFormeCORGroupe : public ChargementFormeCOR{
	ChargementFormeCOR * suivant;
public:
	ChargementFormeCORGroupe(ChargementFormeCOR * suivant);

	Groupe * chargeExpertise(const string texte) const;

};
#endif