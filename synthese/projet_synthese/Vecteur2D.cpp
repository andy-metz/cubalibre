#include"Vecteur2D.hpp"

/*
class Vecteur2D
{
    private:
    double a[3];

    public:
    inline Vecteur2D(const double& x=0,const double& y=0);
    inline Vecteur2D(const Vecteur2D&v);
    inline Vecteur2D(const string&s);
    inline ~Vecteur2D();

    inline double getX()const;
    inline double getY()const;
    inline void setX(const double&x);
    inline void setY(const double&y);
    inline void set(const double&x, const double&y);

    inline double getLength(const Vecteur2D&v)const;
    inline double getLengthSquared(const Vecteur2D&v)const;
    inline Vecteur2D& normalise();
    inline double dot(const Vecteur2D&v)const;
    inline double cross(const Vecteur2D&v)const;

    inline Vecteur2D&operator=(const Vecteur2D&v);
    inline bool operator==(const Vecteur2D&v)const;
    inline bool operator!=(const Vecteur2D&v)const;


    inline Vecteur2D& operator+=(const Vecteur2D&v);
	inline Vecteur2D& operator-=(const Vecteur2D&v);
	inline Vecteur2D& operator*=(const Vecteur2D&v);
	inline Vecteur2D& operator/=(const Vecteur2D&v);

	inline Vecteur2D operator-(const Vecteur2D&v) const;
	inline Vecteur2D operator+(const Vecteur2D&v) const;

	inline Vecteur2D operator-() const;
	inline Vecteur2D operator+() const;

	inline Vecteur2D operator*(const Vecteur2D&v) const;
	inline Vecteur2D operator/(const Vecteur2D&v) const;


    inline operator string()const;
    inline ostream&operator<<(ostream&stream,Vecteur2D v)const;
};
*/



/**
*   Creates a 2D point/vector with coords (x,y).
*   @param x of the new vector.
*   @param y of the new vector.
*/
Vecteur2D::Vecteur2D(const double&x,const double&y)
{
    a[0]=x;
    a[1]=y;
}
/**
*   Constructeur par copy.
*   @param Le vecteur à copier.
*/
Vecteur2D::Vecteur2D(const Vecteur2D&v)
{
    a[0]=v.getX();
    a[1]=v.getY();
}
/**
*   Constructeur à partir d'une chaine de caractères.
*   @param doit avoir le format suivant: $.*(x,y).*^
*/
Vecteur2D::Vecteur2D(const string&s)
{
    a[0]=1.0;
    a[1]=2.0;
    int popos=s.find("("); // position de la premiere parenthèse ouvrante
    if(popos==string::npos)
        cout<<"popos"<<endl;/// TODO throw exception
    int vpos =s.find(",",popos+1); // position de la première virgule
    if(vpos==string::npos)
        cout<<"vpos"<<endl;/// TODO throw exception
    int pfpos=s.find(")",vpos+1); // position de la 1ere parenthèse fermante
    if(pfpos==string::npos)
        cout<<"pfpos"<<endl;/// TODO throw exception
    const char*str=s.c_str();
    string x=s.substr(popos+1,vpos-popos-1);
    string y=s.substr(vpos+1,pfpos-vpos-1);
    stringstream sx(x);
    stringstream sy(y);
    sx>>a[0];
    sy>>a[1];
}
/**
*   Destructeur
*/
Vecteur2D::~Vecteur2D()
{

}
/**
*   Getteur de x
*   @return La composante x du vecteur.
*/
double Vecteur2D::getX()const
{
    return a[0];
}
/**
*   Getteur de Y
*   @return La composante Y du vecteur.
*/
double Vecteur2D::getY()const
{
    return a[1];
}
/**
*   Setteur de x
*   @param x a nouvelle valeur de x.
*/
void Vecteur2D::setX(const double&x)
{
    a[0]=x;
}
/**
*   Setteur de y
*   @param y la nouvelle valeur de y.
*/
void Vecteur2D::setY(const double&y)
{
    a[1]=y;
}
/**
*   Setteur global.
*   @param x la nouvelle valeur de x.
*   @param y la nouvelle valeur de y.
*/
void Vecteur2D::set(const double&x, const double&y)
{
    a[0]=x;
    a[1]=y;
}
/**
*   Retourne la longueur du vecteur.
*   @return La longueur de ce vecteur.
*/
double Vecteur2D::getLength()const
{
    return sqrt(a[0]*a[0]+a[1]*a[1]);
}
/**
*   Retourne la longeur au carré de ce vecteur.
*   Permet de comparer des distances sans l'usage de sqrt().
*   @return La longueur au carré de ce vecteur.
*/
double Vecteur2D::getLengthSquared()const
{
    return a[0]*a[0]+a[1]*a[1];
}
/**
*   Normalise le vecteur.
*   @return Une copie du vecteur normalisé.
*/
Vecteur2D Vecteur2D::normalise()
{
    double len = this->getLength();
    double li = len!=0.0?1/len:0.0;
    a[0]*=li;
    a[1]*=li;
    return *this;
}
/**
*   Effectue un produit scalaire.
*   @return |v1|*|v2|*cos((v1,v2))
*/
double Vecteur2D::dot(const Vecteur2D&v)const
{
    return a[0]*v.getX()+ a[1]*v.getY();
}
/**
*   Effectue un produit vectoriel.
*   @return |v1|*|v2|*sin((v1,v2))
*/
double Vecteur2D::cross(const Vecteur2D&v)const
{
    return a[0]*v.getY() -a[1]*v.getX();
}
/**
*   Opérateur d'affectation.
*   @param v Le vecteur à affecter.
*   @return Une copie de ce vecteur.
*/
const Vecteur2D Vecteur2D::operator=(const Vecteur2D&v)
{
    //cout<<"got"<<v<<endl;
    a[0]=v.getX();
    a[1]=v.getY();
    Vecteur2D r(v);
    //cout<<"returned"<<v<<endl;
    return r;
}
/**
*   Opérateur de comparaision.
*   @param v le vecteur à comparer à celui-ci.
*   @return true ci les vecteurs sont égaux, false sinon.
*/
bool Vecteur2D::operator==(const Vecteur2D&v)const
{
    return (a[0]==v.getX()+a[1]==v.getY());
}
/**
*   Opérateur de comparaision.
*   @param v le vecteur à comparer à celui-ci.
*   @return false ci les vecteurs sont égaux, true sinon.
*/
bool Vecteur2D::operator!=(const Vecteur2D&v)const
{
    return !operator==(v);
}

/**
*   Opérateur d'addition
*   @param v le vecteur à additionner à celui-ci.
*   @return Une copie du résultat.
*/
Vecteur2D Vecteur2D::operator+=(const Vecteur2D&v)
{
    a[0]+=v.getX();
    a[1]+=v.getY();
    Vecteur2D r(*this);
    return r;
}
/**
*   Opérateur de soustraction
*   @param v le vecteur à soustraire à celui-ci.
*   @return Une copie du résultat.
*/
Vecteur2D Vecteur2D::operator-=(const Vecteur2D&v)
{
    a[0]-=v.getX();
    a[1]-=v.getY();
    Vecteur2D r(*this);
    return r;
}
/**
*   Opérateur de multiplication
*   @param v le vecteur à multiplier avec celui-ci.
*   @return Une copie du résultat.
*/
Vecteur2D Vecteur2D::operator*=(const Vecteur2D&v)
{
    a[0]*=v.getX();
    a[1]*=v.getY();
    Vecteur2D r(*this);
    return r;
}
/**
*   Opérateur de division
*   @param v le vecteur par lequel diviser celui-ci.
*   @return Une copie du résultat.
*/
Vecteur2D Vecteur2D::operator/=(const Vecteur2D&v)
{
    if(v.getX()!=0.0)
        a[0]/=v.getX();
    if(v.getY()!=0.0)
        a[1]/=v.getY();
    Vecteur2D r(*this);
    return r;
}
/**
*   Opérateur de soustraction.
*   @return Le résultat.
*/
Vecteur2D Vecteur2D::operator-(const Vecteur2D&v) const
{
    Vecteur2D r(a[0]-v.getX(),a[1]-v.getY());
    return r;
}
/**
*   Opérateur d'addition.
*   @return Le résultat.
*/
Vecteur2D Vecteur2D::operator+(const Vecteur2D&v) const
{
    Vecteur2D r(a[0]+v.getX(),a[1]+v.getY());
    return r;
}
/**
*   Pour obtenir l'opposé.
*   @return L'opposé de ce vecteur.
*/
Vecteur2D Vecteur2D::operator-() const
{
    Vecteur2D r(-a[0],-a[1]);
    return r;
}
/**
*   Ne change rien.
*   @return Ce vecteur.
*/
Vecteur2D Vecteur2D::operator+() const
{
    Vecteur2D r(*this);
    return r;
}

Vecteur2D Vecteur2D::operator*(const Vecteur2D&v) const
{
    Vecteur2D r(a[0]*v.getX(),a[1]*v.getY());
    return r;
}
Vecteur2D Vecteur2D::operator/(const Vecteur2D&v) const
{
    Vecteur2D r(a[0]/v.getX(),a[1]/v.getY());
    return r;
}


Vecteur2D::operator string()const
{
    stringstream ss;
    ss<<"("<<a[0]<<","<<a[1]<<")";
    string s=ss.str();
    return s;
}
ostream&operator<<(ostream&stream,const Vecteur2D&v)
{
    stream<<(string)v;
    return stream;
}





















