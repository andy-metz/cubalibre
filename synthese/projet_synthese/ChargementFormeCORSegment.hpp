#ifndef CHARGEMENTFORMECORSEGMENT_HPP_INCLUDED
#define CHARGEMENTFORMECORSEGMENT_HPP_INCLUDED
#include"ChargementFormeCOR.hpp"
#include"Segment.hpp"
/**
*   @file    ChargementFormeCORSegment.hpp ChargementFormeCORSegment.cpp
*   @author  J�r�me Lartillot Olivier Mertz Andr� Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -ChargementFormeCOR.hpp
*   -Segment.hpp
*
*   @section DESCRIPTION
*
*   Classe ChargementFormeCORSegment pour d�finir un expert segment du design pattern COR
*
*/
class ChargementFormeCORSegment : public ChargementFormeCOR{
public:
	ChargementFormeCORSegment(ChargementFormeCOR * suivant);

	Forme * chargeExpertise(const string texte) const;

};
#endif