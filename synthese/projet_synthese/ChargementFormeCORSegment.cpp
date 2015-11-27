#include"ChargementFormeCORSegment.hpp"
/**
*	Enchaine le maillon à suivant en le plaçant en tête
*	@param suivant : le maillon qui devient la tête de la liste
*/
ChargementFormeCORSegment::ChargementFormeCORSegment(ChargementFormeCOR * suivant) :ChargementFormeCOR(suivant) {}
/**
*	Methode qui verifie si "texte" est de la forme "Segment" et se trouve au début de la chaine
*	@param texte : la chaine à vérifier
*	@return un Segment construit par string
*/

Segment * ChargementFormeCORSegment::chargeExpertise(const string texte) const{
	string string_to_extract;
	int pos = texte.find("segment");
	if ((pos == string::npos) || (pos>0))
	{	return NULL;
	}
	else
	{	ifstream file_to_open;
		file_to_open.open(texte, ios::in);
		if (!file_to_open)
		{	return NULL;
		}
		getline(file_to_open, string_to_extract);
		Segment S(string_to_extract);
		return &S;
	}
}