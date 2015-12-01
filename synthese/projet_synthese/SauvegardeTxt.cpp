#include "SauvegardeTxt.hPP"

/**
*	Methode pour incrémenter le compteur
*	@return augumentée de 1
*/
void SauvegardeTxt::setCompteur() {
	SauvegardeTxt::x++;
}
/**
*	Methode de sauvegarde du groupe
*	@param G le groupe à enregistrer
*/
void::SauvegardeTxt::visit(Groupe *G){
	setCompteur();
	stringstream ss;
	ss << x;
	string xs = ss.str();
	ofstream file_to_save("groupe" + xs + ".txt", ios::out);
	if (!file_to_save)
	{
		throw Erreur("Erreur a la creation du fichier ");
		system("pause");
		exit(1);
	}
	file_to_save << (Groupe)* G << endl;
	file_to_save.close();
}

/*
*	Methode de sauvegarde du cercle
*	@param C le cercle à enregistrer
*/

void SauvegardeTxt::visit(Cercle * C){
	setCompteur();
	stringstream ss;
	ss<<x;
	string xs=ss.str();
	ofstream file_to_save("cercle" + xs + ".txt", ios::out);
	if (!file_to_save)
	{
		throw Erreur("Erreur a la creation du fichier ");
		system("pause");
		exit(1);
		
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
		throw Erreur("Erreur a la creation du fichier ");
		system("pause");
		exit(1);
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
		throw Erreur("Erreur a la creation du fichier ");
		system("pause");
		exit(1);
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
		throw Erreur("Erreur a la creation du fichier ");
		system("pause");
		exit(1);
	}

	file_to_save << (Polygone)* P << endl;
	file_to_save.close();
}

