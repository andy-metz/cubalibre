#include "Triangle.hpp"

/**
*	Destructeur de la classe Triangle
*/
Triangle::~Triangle()
{}

/**
*   Méthode accept permet de se faire visiter par un FormeVisiteur.
*   @param fv: la classe dérivée de FormeVisiteur
*   implémentant la fonctionnalité souhaitée.
*/
void Triangle::accept(FormeVisiteur*fv)
{
    fv->visit(this);
}
/**
*	Constructeur litterale de la classe Triangle.
*	@param point1: Le premier point du triangle.
*	@param point2: Le deuxième point du triangle.
*	@param point3: Le troisième point du triangle.
*	@param Couleur La couleur du triangle.
**/
Triangle::Triangle(Vecteur2D point1, Vecteur2D point2, Vecteur2D point3, Color couleur):
    Forme(couleur)
{
	p1=point1;
	p2=point2;
	p3=point3;
}

/**
*	Constructeur par recopie de la classe Triangle.
*	@param T: le triangle a recopier.
*/
Triangle::Triangle(const Triangle &T):Forme(T),p1(T.p1),p2(T.p2),p3(T.p3)
{}

/**
*	Constructeur par string de la classe Triangle
*	@param s: la string qui permet de construire le triangle
*	format:"triangle:p1(x1,y1),p2(x2,y2),p3(x3,y3)"
*/
Triangle::Triangle(const string &s){

	int triPos = s.find("triangle:");
	if (triPos == string::npos)
		cout << "error" << endl;

	int s1Pos = s.find("p1");//p1 s1Pos=9
	if (s1Pos == string::npos)
		cout << "error" << endl;
	int v1Pos=s.find(",",s1Pos);//la virgule de p1(x1,y1) 
	v1Pos = s.find(",",v1Pos);//on va cherher la virgule suivante p1(x1,y1),
	if (v1Pos == string::npos)
		cout << "error" << endl;

	int s2Pos = s.find("p2");//p1(x1,y1),p2
	if (s2Pos == string::npos)
		cout << "error" << endl;
	int v2Pos = s.find(",", s2Pos );//la virgule de p2(x2,y2) 
	v2Pos = s.find(",", v2Pos + 1);//p2(x2,y2),
	if (v2Pos == string::npos)
		cout << "error" << endl;

	int s3Pos = s.find("p3");//p2(x2,y2),p3
	if (s3Pos == string::npos)
		cout << "error" << endl;
	int triFin = s.find(",", s3Pos);//la virgule de p3(x3,y3) 
	triFin = s.find(")", triFin);//la ")" de p3(x3,y3)
	if (triFin == string::npos)
		cout << "error" << endl;

	string s1 = s.substr(triPos + 11, v1Pos - triPos - 8);
	string s2 = s.substr(s2Pos, v2Pos);
	string s3 = s.substr(s3Pos,triFin);
	Vecteur2D v1(s1), v2(s2), v3(s3);
	p1 = v1;
	p2 = v2;
	p3 = v3;

}
/**
*	Setter du premier point de Triangle.
*	@param point1: Le nouveau premier point du triangle.
*/
void Triangle::setPoints1(const Vecteur2D &point1){
	p1=point1;
}

/**
*	Setter du deuxième point de Triangle.
*	@param point2: Le nouveau premier point du triangle.
*/
void Triangle::setPoints2(const Vecteur2D &point2){
	p2=point2;
}

/**
*	Setter du troisième point de Triangle.
*	@param point3: Le nouveau premier point du triangle.
*/
void Triangle::setPoints3(const Vecteur2D &point3){
	p3=point3;
}

/**
*	Getter du premier point du triangle.
*	@return Le premier point du triangle.
*/
const Vecteur2D Triangle::getPoints1() const{
	return p1;
}
/**
*	Getter du deuxième point du triangle
*	@return Le deuxième point du triangle
*/

const Vecteur2D Triangle::getPoints2() const{
	return p2;
}

/**
*	Getter du troisième point du triangle.
*	@return Le troisième point du triangle.
*/
const Vecteur2D Triangle::getPoints3() const{
	return p3;
}

/**
*	Calcule l'aire du triangle
*	On utilise la formule de Lacet (shoelace en anglais).
*	@return L'aire du triangle.
*/
double Triangle::calculerAire() const{
	double x1,y1,x2,y2,x3,y3,area;
	x1=p1.getX();
	y1=p1.getY();

	x2=p2.getX();
	y2=p2.getY();

	x3=p3.getX();
	y3=p3.getY();

	area=(0.5) * fabs( ( (x1*y2)+(x2*y3)+(x3*y1) ) - (	(x3*y1)+( x3*y2)+(x1*y3)	) );

	return area;
}

/**
*	Opérateur de conversion d'un triangle en chaine de caractère
*	@return le triangle sous forme de chaines de charactères
*/
Triangle::operator string()const
{
	stringstream ss;
	ss << "triangle:p1"<<p1<<",p2"<<p2<<",p3"<<p3;
	string s = ss.str();
	return s;
}
/**
*	Renvoie le triangle sous forme de string dans un flux
*	@param stream : le flux à modifié
*	@param t : le triangle à mettre dans le flux
*	@return le flux
*/
ostream&operator<<(ostream&stream, const Triangle &t){
	stream << (string)t;
	return stream;
}
