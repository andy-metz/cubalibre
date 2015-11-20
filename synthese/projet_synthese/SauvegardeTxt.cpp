#include "SauvegardeTxt.hPP"

/**
*	Methode de sauvegarde du cercle 
*	@param C le cercle à enregistrer
*	@return un pointeur sur le fichier enregistrer
*/
/*
void SauvegardeTxt::sauvegarder( Cercle * C){	

	fstream f;
	f.open("cercle.txt");
	f << "Rayon:" << C->getRayon() << "Centre: (";
	f << C->getCentre().getX() << "," << C->getCentre().getY() << ")";
	f.seekg(0);
	f.close();
}
/**
*	Methode de sauvegarde du Triangle
*	@param T le cercle a enregistrer
*//*
void SauvegardeTxt::sauvegarder( Triangle* T){
	fstream f;
	f.open("triangle.txt");
	f << "P1 :(";
	f << T->getPoints1().getX() << "," << T->getPoints1().getY() << ") \n";
	f << "P2 :(";
	f << T->getPoints2().getX() << "," << T->getPoints2().getY() << ") \n";
	f << "P3 :(";
	f << T->getPoints3().getX() << "," << T->getPoints3().getY() << ") \n";
	f.seekg(0);
	f.close();
}
/**
*	Methode de sauvegarde Segment
*	@param S le segment a enregistrer
*//*
void SauvegardeTxt::sauvegarder(Segment * S){
	fstream f;
	f.open("segment.txt");
	f << "P1:(";
	f << S->getA().getX() << "," << S->getA().getY() << ") \n";
	f << "P2:(";
	f << S->getB().getX() << ',' << S->getB().getY() << ") \n";
	f.seekg(0);
	f.close();
}
/**
*	Methode de sauvegarde du Polygone
*	@param P le polygone a enregistrer
*//*
void SauvegardeTxt::sauvegarder(Polygone *P){
	fstream f;
	vector < Vecteur2D > points_poly;
	points_poly = P->getPoints();
	f.open("polygone.txt");
	for (double i = 0; i < points_poly.size(); i++)
	{
		f << "Points" << i << "(" << points_poly[i].getX() << "," << points_poly[i].getY() << ") \n";
	}
	f.seekg(0);
	f.close();
}*/

