#pragma once
#ifndef ERREUR_HPP_INCLUDED
#define ERREUR_HPP_INCLUDED
/**
*   @file    Polygone.hpp Polygone.cpp
*   @author  J�r�me Lartillot Olivier Mertz Alain Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -iostream
*   -string
*
*   @section DESCRIPTION
*
*   Exception utilis�e pour le r�seaus
*
*/



using namespace std;
#include <exception>
#include <string>
#include <iostream>

/**
    Classe Erreur
*/
class Erreur : public exception
{
private:
	string info_message;
public :
	Erreur(string const& phrase) throw();

	virtual ~Erreur() throw();

	friend ostream&operator<<(ostream&stream, const Erreur e);
};
#endif


