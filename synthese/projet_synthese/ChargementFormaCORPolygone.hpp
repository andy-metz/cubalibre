#ifndef CHARGEMENTFORMECORPOLYGONE_HPP_INCLUDED
#define CHARGEMENTFORMECORPOLYGONE_HPP_INCLUDED
#include"ChargementFormeCOR.hpp"
#include"Polygone.hpp"
/**
*   @file    ChargementFormeCORPolygone.hpp ChargementFormeCORPolygone.cpp
*   @author  J�r�me Lartillot Olivier Mertz Andr� Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -ChargementFormeCOR.hpp
*   -Polygone.hpp
*
*   @section DESCRIPTION
*
*   Classe ChargementFormeCORPolygone pour d�finir un expert polygone du design pattern COR
*
*/
class ChargementFormeCORPolygone : public ChargementFormeCOR{
public:
	ChargementFormeCORPolygone(ChargementFormeCOR * suivant);

	Forme * chargeExpertise(const string texte) const;

};
#endif