#include "ChargementFormeCOR.hpp"
/**
*	Enchaine le maillon � suivant en le pla�ant en t�te
*	@param suivant : le maillon qui devient la t�te de la liste
*/
ChargementFormeCOR::ChargementFormeCOR(ChargementFormeCOR * suivant) :suivant(suivant){}

/**
*	Transforme texte en un objet Forme
*	En cas d'�chec retourne NULL
*	@param texte: le texte a transform�
*	@return La forme charg� ou NULL si le format n'est pas reconnu
*/
Forme * ChargementFormeCOR::charge(const string texte) const{
	Forme * resultat;
	resultat = this->chargeExpertise(texte);

	if (resultat)
	{	return resultat;}
	else
	{	if (this->suivant)
		{	return this->suivant->chargeExpertise(texte);}
		else
		{	return NULL;}
	}
}