#include "SauvegardeTxt.hPP"

/**
*	Methode pour incr�menter le compteur
*	@return augument�e de 1
*/
void SauvegardeTxt::setCompteur() {
	SauvegardeTxt::x++;
}
/*
*	Methode de sauvegarde du cercle
*	@param C le cercle � enregistrer
*/

void SauvegardeTxt::visit(Cercle * C){
	setCompteur();
	stringstream ss;
	ss<<x;
	string xs=ss.str();
	ofstream file_to_save("cercle" + xs + ".txt", ios::out);
	if (!file_to_save)
	{
		cerr << "Erreur a l'ouverture du fichier" << endl;
		system("pause");
		exit(1);
		//throw exception
	}

	file_to_save << (Cercle)* C << endl;
	file_to_save.close();
}
/**
*	Methode de sauvegarde du Triangle
*	@param T le triangle a enregistrer
*/
void SauvegardeTxt::visit(Triangle* T){
	setCompteur();
	stringstream ss;
	ss<<x;
	string xs=ss.str();
	ofstream file_to_save("triangle" + xs + ".txt", ios::out);
	if (!file_to_save)
	{
		cerr << "Erreur a l'ouverture du fichier" << endl;
		system("pause");
		exit(1);
		//throw exception
	}

	file_to_save << (Triangle)* T << endl;
	file_to_save.close();
}
/**
*	Methode de sauvegarde Segment
*	@param S le segment a enregistrer
*/
void SauvegardeTxt::visit(Segment * S){
	setCompteur();
	stringstream ss;
	ss<<x;
	string xs=ss.str();
	ofstream file_to_save("segment" + xs + ".txt", ios::out);
	if (!file_to_save)
	{
		cerr << "Erreur a l'ouverture du fichier" << endl;
		system("pause");
		exit(1);
		//throw exception
	}

	file_to_save << (Segment)* S << endl;
	file_to_save.close();
}
/**
*	Methode de sauvegarde du Polygone
*	@param P le polygone a enregistrer
*/
void SauvegardeTxt::visit(Polygone *P){
	setCompteur();
	stringstream ss;
	ss<<x;
	string xs=ss.str();
	ofstream file_to_save("polygone" + xs + ".txt", ios::out);
	if (!file_to_save)
	{
		cerr << "Erreur a l'ouverture du fichier" << endl;
		system("pause");
		exit(1);
		//throw exception
	}

	file_to_save << (Polygone)* P << endl;
	file_to_save.close();
}

