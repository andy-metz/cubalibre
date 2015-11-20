#include"Forme.hpp"


/**
*   Constructeur de forme.
*   @param color: set color � cyan si undef.
*/
Forme::Forme(const Color c):
    color(c)
{}

/**
*	Constructeur par recopie de forme
*	@param Forme à recopier
*
*/
Forme::Forme(const Forme &F){
	color = F.color;
}


/**
*   Retourne la couleur de la forme.
*   @return la couleur.
*/
Color Forme::getColor()const{
    return color;
}
/**
*   Retourne la couleur de la forme au format string.
*   @return la couleur.
*/
string Forme::getColorAsString()const
{
    switch(color){
        case BLACK: return "black";
        case BLUE: return "blue";
        case RED: return "red";
        case GREEN: return "green";
        case YELLOW: return "yellow";
        case CYAN: return "cyan";
    }
}
/**
*   Définit la couleur.
*   @param c la nouvelle couleur.
*/
void Forme::setColor(const Color&c){
    color=c;
}

/**
*   Permet de définir la couleur d'une forme.
*   @param s: la couleur.
*   Doit être black blue red green yellow ou cyan.
*   Peut être utilisée avec getColorAsString.
*/
void Forme::setColor(const string&s)
{
    if(s=="black"){
        color=BLACK;
    }
    if(s=="blue"){
        color=BLUE;
    }
    if(s=="red"){
        color=RED;
    }
    if(s=="green"){
        color=GREEN;
    }
    if(s=="yellow"){
        color=YELLOW;
    }
    if(s=="cyan"){
        color=CYAN;
    }
}
/**
*
* Retourne l'aire d'une forme
*
*/
double Forme::calculerAire()const{
	return 0;
}




















