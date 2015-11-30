#pragma once
/**
*   @file    Polygone.hpp Polygone.cpp
*   @author  J�r�me Lartillot Olivier Mertz Andr� Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -Winsock2
*   -string
*   -string.h
*
*   @section DESCRIPTION
*
*   Classe ClientDessin pour se connecter au server java et lui envoyer des instructions de dessin.
*
*/


#include <WinSock2.h>
#include <string>
#include <string.h>

#include"Cercle.hpp"
#include"Polygone.hpp"
#include"Segment.hpp"
#include"Triangle.hpp"
#include"Groupe.hpp"

using namespace std;

/**
* cr�e un client TCP/IP vers un serveur de dessin
*
* envoie 3 requ�tes possibles :
*
* ouvrir une fen�tre graphique
* tracer un segment
* tracer une ellipse pleine
*
* protocole : Chaque requ�te est cod�e sous forme d'une seule String se terminant par le caract�re fin de ligne.
* Sur la ligne, 2 param�tres cons�cutifs sont s�par�s par ", ".
*
* */
class ClientDessin: public FormeVisiteur
{
	SOCKET sock;  // informations concernant le socket � cr�er : famille d'adresses accept�es, mode connect� ou non, protocole
	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

	void envoyer(const string&str)const;

public:
	ClientDessin(const string & adresseServeurDessin, const int portServeurDessin);
	~ClientDessin();

	// h�rit�es de FormeVisiteur
    void visit( Triangle * triangle);
	void visit( Polygone * polygone);
	void visit( Segment * segment);
	void visit( Cercle * cercle);
	void visit(Groupe * groupe);

	void ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur);

	/**
	envoie sur une seule ligne les 5 param�tres au serveur.
	* Les 5 param�tres drawLine, ... , y2 sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", "
	*  * */
	void traceSegment(const int x1, const int y1, const int x2, const int y2);
};


