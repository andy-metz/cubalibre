/**
mise en oeuvre de la classe Erreur
*/
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <string>
#include "Erreur.hpp"
/**
*	Destructeur de la classe Erreur
*/
Erreur::~Erreur()throw(){

}
/**
*	Constructeur de la classe Erreur par défaut le message est "" sinon info_message
*	@param: phrase
*/
Erreur::Erreur(string const& phrase) throw() :info_message(info_message){}

/**
*	Operateur de string pour la classe erreur.
*	Permet d'afficher le messaged'erreur dans un flux
*   @param stream : le flux dans lequelle on doit envoyer le message d'erreur
*	@param e : L'erreur qui être transmise dans le flux
*/
ostream&operator<<(ostream&stream, const Erreur e)
{
	stream << e.info_message << endl;
	return stream;
}
