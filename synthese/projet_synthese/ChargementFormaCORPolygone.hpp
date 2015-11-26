#ifndef CHARGEMENTFORMECORPOLYGONE_HPP_INCLUDED
#define CHARGEMENTFORMECORPOLYGONE_HPP_INCLUDED
#include"ChargementFormeCOR.hpp"
#include"Polygone.hpp"
/**
*   @file    ChargementFormeCORPolygone.hpp ChargementFormeCORPolygone.cpp
*   @author  Jérôme Lartillot Olivier Mertz André Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -ChargementFormeCOR.hpp
*   -Polygone.hpp
*
*   @section DESCRIPTION
*
*   Classe ChargementFormeCORPolygone pour définir un expert polygone du design pattern COR
*
*/
class ChargementFormeCORPolygone : public ChargementFormeCOR{
public:
	ChargementFormeCORPolygone(ChargementFormeCOR * suivant);

	Forme * chargeExpertise(const string texte) const;

};
#endif