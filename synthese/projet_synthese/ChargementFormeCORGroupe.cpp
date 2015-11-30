#include"ChargementFormeCORGroupe.hpp"
/**
*	Enchaine le maillon à suivant en le plaçant en tête
*	@param suivant : le maillon qui devient la tête de la liste
*/
ChargementFormeCORGroupe::ChargementFormeCORGroupe(ChargementFormeCOR * suivant) :ChargementFormeCOR(suivant) {}
/**
*	Methode qui verifie si "texte" est de la forme "Groupe" et se trouve au début de la chaine
*	@param texte : la chaine à vérifier
*	@return un Groupe construit par string
*/
Groupe * ChargementFormeCORGroupe::chargeExpertise(const string texte) const{
	string string_to_extract;
	int pos = texte.find("groupe");
	if ((pos == string::npos) || (pos>0))
	{
		return NULL;
	}
	else
	{
		ifstream file_to_open(texte, ios::in);
		if (!file_to_open)
		{
			return NULL;
		}
		getline(file_to_open, string_to_extract);
		return new Groupe(string_to_extract);
	}
}
