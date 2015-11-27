#include"ChargementFormeCORSegment.hpp"
/**
*	Enchaine le maillon � suivant en le pla�ant en t�te
*	@param suivant : le maillon qui devient la t�te de la liste
*/
ChargementFormeCORSegment::ChargementFormeCORSegment(ChargementFormeCOR * suivant) :ChargementFormeCOR(suivant) {}
/**
*	Methode qui verifie si "texte" est de la forme "Segment" et se trouve au d�but de la chaine
*	@param texte : la chaine � v�rifier
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