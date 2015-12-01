#include "ChargementFormeCOR.hpp"
/**
*	Enchaine le maillon à suivant en le plaçant en tête
*	@param suivant : le maillon qui devient la tête de la liste
*/
ChargementFormeCOR::ChargementFormeCOR(ChargementFormeCOR * suivant) :suivant(suivant){}

/**
*	Transforme texte en un objet Forme
*	En cas d'échec retourne NULL
*	@param texte: le texte a transformé
*	@return La forme chargé ou NULL si le format n'est pas reconnu
*/
Forme * ChargementFormeCOR::charge(const string texte) const{
	Forme * resultat;
	resultat = this->chargeExpertise(texte);

	if (resultat!=NULL)
	{	return resultat;}
	else
	{	if (this->suivant!=NULL)
		{
		return (this->suivant->charge(texte));}
		else
		{
			throw Erreur("Le fichier recherche n existe pas");
			return NULL;}
	}
}