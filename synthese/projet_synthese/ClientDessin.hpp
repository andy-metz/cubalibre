#pragma once
/**
*   @file    Polygone.hpp Polygone.cpp
*   @author  Jérôme Lartillot Olivier Mertz André Erba
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
* crée un client TCP/IP vers un serveur de dessin
*
* envoie 3 requêtes possibles :
*
* ouvrir une fenêtre graphique
* tracer un segment
* tracer une ellipse pleine
*
* protocole : Chaque requête est codée sous forme d'une seule String se terminant par le caractère fin de ligne.
* Sur la ligne, 2 paramètres consécutifs sont séparés par ", ".
*
* */
class ClientDessin: public FormeVisiteur
{
	SOCKET sock;  // informations concernant le socket à créer : famille d'adresses acceptées, mode connecté ou non, protocole
	SOCKADDR_IN sockaddr; // informations concernant le serveur avec lequel on va communiquer

	void envoyer(const string&str)const;

public:
	ClientDessin(const string & adresseServeurDessin, const int portServeurDessin);
	~ClientDessin();

	// héritées de FormeVisiteur
    void visit( Triangle * triangle);
	void visit( Polygone * polygone);
	void visit( Segment * segment);
	void visit( Cercle * cercle);
	void visit(Groupe * groupe);

	void ouvreFenetreGraphique(const string & titre, const int bordGauche, const int bordHaut, const int largeur, const int hauteur);

	/**
	envoie sur une seule ligne les 5 paramètres au serveur.
	* Les 5 paramètres drawLine, ... , y2 sont au préalable encodés en 1 seule String. Les paramètres sont séparés par ", "
	*  * */
	void traceSegment(const int x1, const int y1, const int x2, const int y2);
};


