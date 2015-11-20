#ifndef FormeVisiteur_HPP_INCLUDED
#define FormeVisiteur_HPP_INCLUDED


/**
*   @file    FormeVisiteur.hpp FormeVisiteur.cpp
*   @author  Jérôme Lartillot Olivier Mertz Alain Erba
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
*   Classe abstraite FormeVisiteur pour définir
*   les méthodes abstraites permettant de visiter pour les classes filles.
*
*
*/
class Triangle;
class Segment;
class Polygone;
class Cercle;
class Groupe;

/*
*	@class Visiteur permettant d'ajouter de nouvelle fonctionnalités aux clients
*
*/

class FormeVisiteur{
public:
	virtual  void visit(Triangle * Forme) = 0;
	virtual  void visit(Polygone * Forme) = 0;
	virtual  void visit(Segment * Forme) = 0;
	virtual  void visit(Cercle * Forme) = 0;
	/*virtual  Forme * visite(const Groupe * Forme) = 0;*/

};
#endif
