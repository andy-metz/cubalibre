#ifndef FORME_HPP_INCLUDED
#define FORME_HPP_INCLUDED

#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<cmath>
//#include<cstdio>
#include<stdio.h>
#include<stdlib.h>
#include<vector>

#include"FormeVisiteur.hpp"
using namespace std;

/**
*   @file    Forme.hpp Forme.cpp
*   @author  J�r�me Lartillot Olivier Mertz André Erba
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
*   Classe abstraite Forme, repr�sente une forme.
*   Classe groupe, repr�sente un groupe de formes.
*
*
*/

/*
#define BLACK  0
#define BLUE   1
#define RED    2
#define GREEN  3
#define YELLOW 4
#define CYAN   5
typedef unsigned char Color;
*/

/**
*   @enum Color
*   Type d�finissant la couleur.
*   Valeurs possibles:
*   BLACK 0 BLUE 1 RED 2 GREEN 3 YELLOW 4 CYAN 5
*/
typedef enum name{BLACK,BLUE,RED,GREEN,YELLOW,CYAN} Color;
/**
*   @class Forme
*   Définit une forme et les méthodes qu'elle doit avoir.
*/
class Forme
{
private:
    Color color;
    public:
    Forme(const Color c=CYAN);
	Forme(const Forme &F);

	virtual void accept(FormeVisiteur*fv)=0;

    Color getColor()const;
    string getColorAsString()const;
    void setColor(const Color&c);
    void setColor(const string&s);

	virtual double calculerAire() const;
};









#endif // FORME_HPP_INCLUDED













