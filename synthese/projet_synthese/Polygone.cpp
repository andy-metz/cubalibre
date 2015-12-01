#include "Polygone.hpp"

/**
*	Destructueur du Polygone.
*/
Polygone::~Polygone()
{}

/**
*	Constructeur litterale de Polygone
*	@param tab_point: vector des points du polygone à construire
*/
Polygone::Polygone(const vector<Vecteur2D> tab_point,Color nouv_couleur):
    Forme(nouv_couleur),
    points(tab_point)
{}
/**
*	Constructeur par string du Polyogone
*	@param s : la string qui permet de construire le polygone
*	format:"Polygone:p0(x0,y0),p1(x1,y1),p2(x2,y2),...,pi(xi,yi),end"
*/
Polygone::Polygone(const string &s){
	int p_count = 0;// on compte le nombre de points dans le chaine
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'p')
			p_count++;
	}
	int polyPos = s.find("Polygone:");
	if (polyPos == string::npos)
	{
		throw Erreur("La chaine n'est pas bien formaté");
	}

	string vect_courant;
	int decalage = 0;//on compte le decalage de l'avancement dans la chaine
	int pos = 0;
	int vpos;
	for (int i = 0; i < p_count; i++)
	{
		pos = s.find("p");// on arrive sur un vecteur
		if (pos == string::npos)
			throw Erreur("Le chaine n'est pas bien formaté");
		vpos = s.find(",", pos +decalage);
		vpos = s.find(",", vpos+1 );
		if (vpos == string::npos)
			throw Erreur("Le chaine n'est pas bien formaté");
		vect_courant = s.substr(polyPos + pos + 1 + decalage, vpos + decalage - polyPos);
		decalage = decalage + 7;
		Vecteur2D  vect2D(vect_courant);
		points.push_back(vect2D);
	}
}

/**
*	Constructeur par recopie du Polygone
*	@param P le polygone à recopier
*/
Polygone::Polygone(const Polygone &P):Forme(P),points(P.points)
{}


/**
*   Méthode accept permet de se faire visiter par un FormeVisiteur
*   @param fv: le classe dérivée de FormeVisiteur
*   implémentant la fonctionnalité souhaitée.
*/
void Polygone::accept(FormeVisiteur*fv){
    fv->visit(this);
}

/**
*	Setteur de points du Polygone
*	@param nouv_points: les nouveaux points du polygone.
*/
void Polygone::setPoints(const vector<Vecteur2D> &nouv_points){
	if (nouv_points.size() < 3){
		throw Erreur("Un polygone possêde au moins 3 points");
	}
	else
	{	points = nouv_points;
	}
}
/**
*	Getteur de points du Polygone.
*	@return Les points du poylgone.
*/
const vector<Vecteur2D> Polygone::getPoints() const{
	return points;
}
/**
*	Calcule l'aire du polygone, convexe ou concave, mais sans auto-intersection
*	Calcule fait selon la formule de shoelace ( formule d'aire de gauss)
*	@return l'aire du polygone
*/
double Polygone::calculerAire() const {
	// rajouter fonction déterminant dans vecteur2D cpp
	double somme1 = 0, somme2 = 0, somme_resultante = 0, area = 0, end_term1 = 0, end_term2 = 0;
	int size_max = points.size();
	//rajouter le premier terme de la somme + et le dernier terme de le somme -
	for (int i = 1; i < size_max; i++)
	{
		somme1 = somme1 + points[i - 1].getX() * points[i].getY();
		somme2 = somme2 - points[i].getX() * points[i - 1].getY();
	}
	end_term1 = points[size_max].getX()*points[0].getY();
	end_term2 = points[0].getX()*points[size_max].getY();

	somme_resultante = somme1 + somme2 + end_term1 - end_term2;
	area = 0.5*fabs(somme_resultante);
	return area;
}

/**
*	Operator de conversion d'un polygone en chaine de caractères
*	@return le polygone sous forme de chaine de caractères
*/
Polygone::operator string() const{
	
	stringstream ss;
	ss << "Polygone:";
	for (int i = 0; i<points.size(); i++)
	{
		ss << "p" << i << points[i] << ",";
	}
	ss << "end";
	string s = ss.str();
	return s;
}
/**
*	Renvoie le Polygone sous forme de string dans un flux
*	@param stream: le flux à modifié
*	@param p : le polygone à mettre dans le flux
*	@return le flux modifié
*/
ostream&operator<<(ostream&stream,const Polygone &p){ 
	stream << (string)p;
	return stream;
}