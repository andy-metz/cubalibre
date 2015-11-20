#include "Segment.hpp"

/**
*   Constructeur par recopie de segment
*	@param S: le segment a recopier.
*/
Segment::Segment(const Segment &S) :Forme(S), a(S.a), b(S.b)
{}

/**
*	Constructeur littérale de segment
*	@param	A le point x de segment
*	@param	B le point y de segment
*	@param couleur la couleur du segment
*/
Segment::Segment(const Vecteur2D A ,const Vecteur2D B, const Color couleur):Forme(couleur){
	a = A;
	b = B;
}

/**
*   Construit un segment à partir d'une chaîne de charactères.
*   @param s: la chaîne à partir de laquelle construire.
*   Doit avoir le format .*Segment((x1,y1),(x2,y2)).*
*/
Segment::Segment(const string&s)
{
    int segPos=s.find("Segment(");
    if(segPos==string::npos)
        cout<<"segPos"<<endl;// TODO throw exception
    int vpos=s.find(",",segPos);
    vpos=s.find(",",vpos+1); // La 1ere virgule fait partie du vecteur et parasite.
    if(vpos==string::npos)
        cout<<"vpos"<<endl;// TODO throw exception
    int segFin=s.find(")");
    segFin=s.find(")",segFin+1);
    if(segFin==string::npos)
        cout<<"segFin"<<endl;// TODO throw exception
    string p1=s.substr(segPos+8,vpos-segPos-8);
    string p2=s.substr(vpos+1,segFin-vpos);
    Vecteur2D v1(p1),v2(p2);
    a=v1; b=v2;
}

Segment::~Segment()
{

}

/**
*   Méthode accept permet de se faire visiter par un FormeVisiteur
*   @param fv: la classe dérivée de FormeVisiteur
*   implémentant la fonctionnalité souhaitée.
*/
void Segment::accept(FormeVisiteur*fv)
{
    fv->visit(this);
}

/**
*	Getter de taille.
*	@return La taille du segment.
*/
double Segment::getTaille() const{
	return (b - a).getLength();
}

/**
* Getter de a un point du segment.
* @return Le point a du segment.
*/
const Vecteur2D Segment::getA()const{
	return a;
}

/**
* Getter de b un point du segment.
* @return Le point a du segment.
*/
const Vecteur2D Segment::getB()const{
	return b;
}

/**
*	Setter de a un point du segment.
*	@param A:  la nouvelle valeur de a.
*/
void Segment::setA(const Vecteur2D &A){
	a = A;
}

/**
*	Setter de b un point ud segment.
*	@param B:  la nouvelle valeur de b.
*/
void Segment::setB(const Vecteur2D &B){
	b = B;
}

/**
*   Opérateur de convertion d'un segment en chaîne de caractères.
*   @return Le segment sous forme de chaîne.
*/
Segment::operator string()const
{
    stringstream ss;
    ss<<"Segment("<<a<<","<<b<<")"<<endl;
    string s=ss.str();
    return s;
}

/**
*   Permet d'afficher un Segment.
*   @param stream: le flux dans lequel afficher.
*   @param s: le segment à afficher.
*   @return Renvoie le flux modifié.
*/
ostream&operator<<(ostream&stream,const Segment&s)
{
    stream<<(string)s;
    return stream;
}
