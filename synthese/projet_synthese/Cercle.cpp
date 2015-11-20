#include <math.h>
#include "Cercle.hpp"





/**
*   Méthode accept permet de se faire visiter par un FormeVisiteur
*   @param fv: la classe dérivée de FormeVisiteur
*   implémentant la fonctionnalité souhaitée.
*/
void Cercle::accept(FormeVisiteur*fv)
{
    fv->visit(this);
}

/**
*	Constructeur litteral du cercle
*	@param couleur est la couleur du cercle
*	@param point est le centre du cercle
*	@param r est le rayon du cercle
*/
Cercle::Cercle(Color couleur, Vecteur2D point, double r):
    Forme(couleur),
	centre ( point),
	rayon (r)
{

}
/**
*	Constructeur par reocpie  du cercle
*	@param Le cercle à copier
*/
Cercle::Cercle(const Cercle &c):
	Forme(c),
	rayon(c.rayon),
	centre(c.centre){
}

/**
*   Constructeur du cercle à partir d'une chaîne de caractères.
*   Reconnait qqch de la forme .*Cercle(.*rayon(r).*centre(x,y).*
*   ou .*Cercle(.*centre(x,y).*rayon(r).*
*/
Cercle::Cercle(const string&s):
    Forme(BLACK)// will be changed later in this constructor
{
    int cerclePos=s.find("Cercle(");
    if(cerclePos==string::npos)
        cout<<"error"<<endl;/// TODO throw exception
    int rayonPos=s.find("rayon(",cerclePos+6);
    int centrePos=s.find("centre(",cerclePos+6);
    if(rayonPos==string::npos||centrePos==string::npos)
        cout<<"error"<<endl;/// TODO throw exception
    int rayonFin=s.find(")",rayonPos+6);
    int centreFin=s.find(")",centrePos+7);
    if(rayonFin==string::npos||centreFin==string::npos)
        cout<<"error"<<endl;/// TODO throw exception
    string rayonString=s.substr(rayonPos+6,rayonFin-1);
    string centreString=s.substr(centrePos+6,centreFin-centrePos-6+1);
    stringstream rayonSS(rayonString);
    rayonSS>>rayon;
    Vecteur2D v(centreString);
    centre=v;
}

/**
*	Destructeur du cercle.
*/
Cercle::~Cercle(){

}

/**
*
*  Calcule l'aire d'un cercle
*	@return l'aire du cercle
*/

double Cercle::calculerAire()const{
	return 2 * M_PI*rayon*rayon;
}

/**
*	getter du rayon
*	@return le rayon du cercle
*/
const double Cercle::getRayon()const{

	return rayon;
}

/**
*	getter du centre
*	@return le centre du cercle
*/

const Vecteur2D Cercle::getCentre() const {

	return centre;
}

/**
*
*  setter du rayon
*  @param Le nouveau rayon du cercle
*/

void Cercle::setRayon(const double &nouv_rayon){

	rayon = nouv_rayon;
}

/**
*
* setter du centre
* @param Le nouveau centre
**/

void Cercle::setCentre(const Vecteur2D &nouv_point){

	centre = nouv_point;
}

/**
*   Opérateur de convertion d'un cercle en chaîne de caractères.
*   @return Le cercle sous forme de chaîne.
*/
Cercle::operator string()const
{
    stringstream ss;
    ss<<"Cercle(centre"<<(string)centre<<",rayon("<<rayon<<"))";
    string s=ss.str();
    return s;
}

/**
*   Permet d'afficher un Cercle.
*   @param stream: le flux dans lequel afficher.
*   @param c: le cercle à afficher.
*   @return Renvoie le flux modifié.
*/
ostream&operator<<(ostream&stream,const Cercle&c)
{
    stream<<(string)c;
    return stream;
}
