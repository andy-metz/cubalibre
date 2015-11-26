#ifndef CHARGEMENTFORMECORTRIANGLE_HPP_INCLUDED
#define CHARGEMENTFORMECORTRIANGLE_HPP_INCLUDED
#include"ChargementFormeCOR.hpp"
#include"Triangle.hpp"
/**
*   @file    ChargementFormeCORTriangle.hpp ChargementFormeCORTriangle.cpp
*   @author  Jérôme Lartillot Olivier Mertz André Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -ChargementFormeCor.hpp
*   -Triangle.hpp
*
*   @section DESCRIPTION
*
*   Classe ChargementFormeCORTriangle pour définir un expert triangle du design pattern COR
*
*/
class ChargementFormeCORTriangle : public ChargementFormeCOR{
public:
	ChargementFormeCORTriangle(ChargementFormeCOR * suivant);

	Forme * chargeExpertise(const string texte) const;

};
#endif