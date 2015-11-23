#ifndef OPENGLVISITEUR_HPP_INCLUDED
#define OPENGLVISITEUR_HPP_INCLUDED

/**
*   @file    FormeVisiteur.hpp FormeVisiteur.cpp
*   @author  Jérôme Lartillot Olivier Mertz André Erba
*   @version 1.0
*
*   @section REQUIREMENTS
*   -FormeVisiteur
*   -Triangle, Cercle, Polygone, Segment
*   -stdio, stdlib
*   -OpenGL, SDL
*   -std namespace
*
*   @section DESCRIPTION
*
*   Classe abstraite FormeVisiteur pour définir
*   les méthodes abstraites permettant de visiter pour les classes filles.
*
*
*/

#include<GL/gl.h>
#include<GL/glu.h>

#include<SDL2/SDL.h>

#include "Vecteur2D.hpp"
#include "FormeVisiteur.hpp"
#include "Forme.hpp"

#include"Triangle.hpp"
#include"Polygone.hpp"
#include"Cercle.hpp"
#include"Segment.hpp"
#include"Transformation.hpp"



class OpenGLVisiteur: public FormeVisiteur
{
    GLuint draws;
    SDL_Window*window;
    SDL_GLContext context;
    double screenWidth,screenHeight;
    bool fullscreen;

    void setColor(const Color c)const;
    inline void drawVect(const Vecteur2D&v)const;


public:
    OpenGLVisiteur(bool fullscreen=false);
    ~OpenGLVisiteur();

    void readyToDraw();
    void render();

    // héritées de FormeVisiteur
    void visit( Triangle * triangle);
	void visit( Polygone * polygone);
	void visit( Segment * segment);
	void visit( Cercle * cercle);
};

#endif // OPENGLVISITEUR_HPP_INCLUDED
