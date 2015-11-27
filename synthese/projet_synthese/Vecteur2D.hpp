#ifndef VECTEUR2D_HPP_INCLUDED
#define VECTEUR2D_HPP_INCLUDED

#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<cmath>
//#include<cstdio>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

/**
*   @file    Vecteur2D.hpp Vecteur2D.cpp
*   @author  J�r�me Lartillot Olivier Mertz Alain Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -iostream
*   -string
*   -cmath
*   -cstdio
*   -std namespace
*
*   @section DESCRIPTION
*
*   Classe vecteur 2D, pour g�rer un vecteur � deux dimensions.
*
*   @section CODE POUR TESTER
    Vecteur2D v1(1.0,2.0);
    Vecteur2D v2(-2.0,1.0);
    Vecteur2D v3=v1+v2;
    Vecteur2D v4("v4 = (518.23,-452.3254) and it's cool!");

    v3-=v1;
    v3*=v2;

    cout<<"V1: "<<v1<<endl;
    cout<<v1.getLength()<<endl;
    cout<<v1.normalise()<<endl<<endl;

    cout<<"V2: "<<v2<<endl;
    cout<<v2.getLength()<<endl;
    cout<<v2.normalise()<<endl<<endl;

    cout<<"V3: "<<v3<<endl;
    cout<<v3.getLength()<<endl;
    cout<<v3.normalise()<<endl<<endl;

    cout<<"V4: "<<v4<<endl;

    cout<<"Dot and cross products tests:"<<endl;
    cout<<v1.dot(v2)<<endl;
    cout<<v1.cross(v2)<<endl;
*/


/**
*   @class Vector2D
*   Repr�sente un vecteur � 2 dimensions.
*   permet toutes les op�rations courrantes.
*/
class Vecteur2D
{
    private:
    double a[2];

    public:
    Vecteur2D(const double&x=0,const double&y=0);
    Vecteur2D(const Vecteur2D&v);
    Vecteur2D(const string&s);
    ~Vecteur2D();

    double getX()const;
    double getY()const;
    void setX(const double&x);
    void setY(const double&y);
    void set(const double&x, const double&y);

    double getLength()const;
    double getLengthSquared()const;
    Vecteur2D normalise();
    double dot(const Vecteur2D&v)const;
    double cross(const Vecteur2D&v)const;

    const Vecteur2D operator=(const Vecteur2D&v);
    bool operator==(const Vecteur2D&v)const;
    bool operator!=(const Vecteur2D&v)const;


    Vecteur2D operator+=(const Vecteur2D&v);
	Vecteur2D operator-=(const Vecteur2D&v);
	Vecteur2D operator*=(const Vecteur2D&v);
	Vecteur2D operator/=(const Vecteur2D&v);

	Vecteur2D operator-(const Vecteur2D&v) const;
	Vecteur2D operator+(const Vecteur2D&v) const;

	Vecteur2D operator-() const;
	Vecteur2D operator+() const;

	Vecteur2D operator*(const Vecteur2D&v) const;
	Vecteur2D operator/(const Vecteur2D&v) const;


    operator string()const;
    friend ostream&operator<<(ostream&stream,const Vecteur2D&v);
};

#endif // VECTEUR2D_HPP_INCLUDED
