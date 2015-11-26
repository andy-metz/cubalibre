#include "ChargementFormaCORPolygone.hpp"
/**
*	Enchaine le maillon � suivant en le pla�ant en t�te
*	@param suivant : le maillon qui devient la t�te de la liste
*/
ChargementFormeCORPolygone::ChargementFormeCORPolygone(ChargementFormeCOR * suivant) :ChargementFormeCOR(suivant) {}
/**
*	Methode qui verifie si "texte" est de la forme "Polygone" et se trouve au d�but de la chaine
*	@param texte : la chaine � v�rifier
*	@return un Polygone construit par string
*/
Forme * ChargementFormeCORPolygone::chargeExpertise(const string texte) const{
	string string_to_extract;

	int pos = texte.find("Polygone");
	if ((pos == string::npos) || (pos>0))
	{	return NULL;
	}
	else
	{	ifstream file_to_open(texte, ios::in);
		if (!file_to_open)
		{	return NULL;
		}
		getline(file_to_open, string_to_extract);
		Polygone P(string_to_extract);
		return &P;
	}
}