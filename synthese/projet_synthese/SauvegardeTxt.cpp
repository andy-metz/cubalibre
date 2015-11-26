#include "SauvegardeTxt.hPP"

/**
*	Methode pour incrémenter le compteur
*	@return augumentée de 1
*/
void SauvegardeTxt::setCompteur() {
	SauvegardeTxt::x++;
}
/*
*	Methode de sauvegarde du cercle
*	@param C le cercle à enregistrer
*/

void SauvegardeTxt::visit(Cercle * C){
	setCompteur();
	ofstream file_to_save("cercle" + to_string(x) + ".txt", ios::out);
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
	ofstream file_to_save("triangle" + to_string(x) + ".txt", ios::out);
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
	ofstream file_to_save("segment" + to_string(x) + ".txt", ios::out);
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
	ofstream file_to_save("polygone" + to_string(x) + ".txt", ios::out);
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

