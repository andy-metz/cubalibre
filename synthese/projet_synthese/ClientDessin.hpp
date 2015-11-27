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
// A Andr�:
// Le client n'a pas besoin de se pr�occuper de comment le serveur g�re l'affichega,
// l'ouverture de la fen�tre peut �tre automatis�e lors d'une connection entrante.
// Rien dans le sujet ne demande de remplir une �lipse, il n'y a que des cercles et
// il faut en tracer le contour uniquement.
//
// ClientDessin ajoute une fonctionnalit�e � notre ensemble de formes.
// Par cons�quent c'est une classe qui h�rite de FormeVisiteur et
// impl�mente chacune de ses fonctions abstraites.
// Ce sont ses fonctions qui doivent �tre utilis�es,
// traceSegment est donc aussi inutile.
// Pour finir, les formes contiennent un op�rateur de conversion en string d�j� cod�,
// qui permet de les envoyer sans avoir plus � coder.
// Fin du client, le reste est � �crire dans la partie java.
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

	void ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur);

	/**
	envoie sur une seule ligne les 5 param�tres au serveur.
	* Les 5 param�tres drawLine, ... , y2 sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", "
	*  * */
	void traceSegment(const int x1, const int y1, const int x2, const int y2);

	/**
	envoie sur une seule ligne les 5 param�tres au serveur.
	* Les 5 param�tres fillOval, ... , hauteur sont au pr�alable encod�s en 1 seule String. Les param�tres sont s�par�s par ", "
	*  * */
	void remplitEllipse(const int bordGauche, const int bordHaut, const int largeur, const int hauteur);
};


