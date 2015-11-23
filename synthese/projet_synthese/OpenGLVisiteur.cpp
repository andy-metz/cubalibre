#include"OpenGLVisiteur.hpp"


/*
class OpenGLVisiteur: public FormeVisiteur
{
    unsigned int draws;
    void setColor(const Color c)const;
    void drawVect(const Vecteur2D&v)const;
public:
    OpenGLVisiteur();
    ~OpenGLVisiteur();

    void render();

    // héritées de FormeVisiteur
    void visit( Triangle * triangle);
	void visit( Polygone * polygone);
	void visit( Segment * segment);
	void visit( Cercle * cercle);
};
*/

void OpenGLVisiteur::setColor(const Color c)const
{
    switch(c)
    {
        case BLACK: glColor3f(0,0,0); break;
        case RED: glColor3f(1.0,0,0); break;
        case GREEN: glColor3f(0,1.0,0);break;
        case BLUE: glColor3f(0,0,1.0);break;
        case YELLOW: glColor3f(1.0,1.0,0);break;
        case CYAN: glColor3f(0,1.0,1.0);break;
        default: glColor3ub(255,51,204);
    }
}

/**
*   Fonction privée qui sert à dessiner un vecteur via OpenGL
*   en s'occupant au passage de la gestion du viewport.
*   @param v: le vecteurà dessiner.
*/
void OpenGLVisiteur::drawVect(const Vecteur2D&v)const{
    glVertex2d(v.getX()/screenWidth,v.getY()/screenHeight);
}

/**
*   Constructeur qui ouvre une fenêtre avec la SDL et définit le contexte.
*   La fenêtre est destinée à être remplie par des visites,
*   puis mise à jour par un appel à render.
*/
OpenGLVisiteur::OpenGLVisiteur(bool fullscreen_):
    fullscreen(fullscreen_)
{
    SDL_DisplayMode dm;
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER);
    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
        SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    if(fullscreen){
        screenWidth=dm.w;
        screenHeight=dm.h;
    }else{
        screenWidth=800;
        screenHeight=600;
    }

    window=SDL_CreateWindow
            ("2eme affichage",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            screenWidth,
            screenHeight,
            SDL_WINDOW_OPENGL|SDL_WINDOW_SHOWN|
            (fullscreen?SDL_WINDOW_FULLSCREEN_DESKTOP:0));
    context= SDL_GL_CreateContext(window);

    draws=glGenLists(1);
    glNewList(1,GL_COMPILE);
    glColor3f(1,0,0);
}

/**
*   Destructeur d'OpenGLVisiteur, détruit la fenêtre et libère tout ce qui a été alloué pour le dessin.
*/
OpenGLVisiteur::~OpenGLVisiteur()
{
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    glDeleteLists(draws,1);
    SDL_Quit();
}

/**
*   Permet de terminer le dessin et de définir définitivement le contenu de la fenêtre.
*   Lorsque cette fonction est appellée, la fenêtre est mise à jour et reste jusqu'à ce que l'utilisateur
*   la ferme, appuie sur ECHAP ou termine le processus.
*/
void OpenGLVisiteur::render()
{
    glEndList();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    SDL_Event event;
    bool windowIsOpen=true;

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glClearColor(0.8,0.8,0.8,0);
    glColor3f(1,0.5,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glCallList(draws);
    glFlush();
    SDL_GL_SwapWindow(window);
    while(windowIsOpen)
    {
        SDL_WaitEvent(&event);
        if( event.type==SDL_QUIT||
            event.type==SDL_KEYDOWN&&
            event.key.keysym.sym==SDLK_ESCAPE)
            windowIsOpen=false;
    }
}

// héritées de FormeVisiteur
/**
*   Dessine un triangle dans la fenêtre de ce visiteur.
*/
void OpenGLVisiteur::visit( Triangle * triangle)
{
    setColor(triangle->getColor());
    glBegin(GL_LINES);
        drawVect(triangle->getPoints1()); drawVect(triangle->getPoints2());
        drawVect(triangle->getPoints2()); drawVect(triangle->getPoints3());
        drawVect(triangle->getPoints3()); drawVect(triangle->getPoints1());
    glEnd();
}

/**
*   Dessine un polygone dans la fenêtre de ce visiteur.
*/
void OpenGLVisiteur::visit( Polygone * polygone)
{
    setColor(polygone->getColor());
    vector<Vecteur2D> pts=polygone->getPoints();
    vector<Vecteur2D>::iterator i=pts.begin();

    Vecteur2D p1,p2;

    glBegin(GL_LINES);
        for(i;i<pts.end();i++)
        {
            drawVect(*i);
            if(i>=pts.end())
                drawVect(*pts.begin());

                drawVect(*(i+1));
        }

    glEnd();
}

/**
*   Dessine un triangle dans la fenêtre de ce visiteur.
*/
void OpenGLVisiteur::visit( Segment * segment)
{
    setColor(segment->getColor());
    glBegin(GL_LINES);
        drawVect(segment->getA());
        drawVect(segment->getB());
    glEnd();
}

/**
*   Dessine un cercle dans la fenêtre de ce visiteur.
*/
#define CIRCLE_PRECISION 256
void OpenGLVisiteur::visit( Cercle * cercle)
{
    setColor(cercle->getColor());
    Vecteur2D point1,
              point2( cercle->getCentre().getX()+cercle->getRayon(), cercle->getCentre().getY() );
    double angle; // en radians
    glBegin(GL_LINES);
        for(int i=1;i<=CIRCLE_PRECISION;i++)
        {
            angle=(double)i*2.0*M_PI/(double)(CIRCLE_PRECISION);
            point1.setX(cercle->getCentre().getX()+cos(angle)*cercle->getRayon());
            point1.setY(cercle->getCentre().getY()+sin(angle)*cercle->getRayon());
            //drawVect(cercle->getCentre());
            drawVect(point2);
            drawVect(point1);
            point2=point1;
        }
    glEnd();
}












