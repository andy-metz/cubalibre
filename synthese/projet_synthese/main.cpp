#include <iostream>
#include"Vecteur2D.hpp"

#include"Forme.hpp"
#include"ChargementFormeCORPolygone.hpp"
#include"ChargementFormeCORCercle.hpp"
#include"ChargementFormeCORSegment.hpp"
#include"ChargementFormeCORTriangle.hpp"
#include "Cercle.hpp"
#include"Segment.hpp"
#include"Triangle.hpp"
#include"Polygone.hpp"

#include"TransformerVisiteur.hpp"
//#include"OpenGLVisiteur.hpp"

#include "FormeVisiteur.hpp"
#include"SauvegardeTxt.hPP"
#include "erreur.h"
#include "ClientDessin.hpp"


using namespace std;


#pragma comment(lib, "ws2_32.lib")

int main(int argv, char**argc)
{

    //Forme test(BLACK);
    //cout<<test.getColorAsString()<<endl;
	//Vecteur2D centre = Vecteur2D(2,2);
	//Cercle CE=Cercle(BLACK,centre,4);

	// dessinerswing dessin(dimension);
	// dessin->dess_cercle(C)

	SauvegardeTxt visitor;
	ChargementFormeCOR *pol, *tri, *cer, *seg;
	pol = new ChargementFormeCORPolygone(NULL);
	tri = new ChargementFormeCORTriangle(pol);
	cer = new ChargementFormeCORCercle(tri);
	seg = new ChargementFormeCORSegment(cer);
	ChargementFormeCOR * chargeur = seg;

	Cercle c("Cercle(rayon(10),centre(0.5,512.5))");
	//cout << c << endl;
	c.accept(&visitor);
	Cercle * cercle_1=(Cercle*)chargeur->charge("cercle1.txt");
//	cout <<*cercle_1 << endl;

	Segment s("Segment((0.1,2),(3,4.5))");
	//cout << s << endl;
	s.accept(&visitor);
	Segment * seg_2 = (Segment*)chargeur->charge("segment2.txt");
	//cout << *seg_2 << endl;

	Triangle t("Triangle:p1(1,1),p2(4,5),p3(3,7)");
	//cout << t << endl;
	t.accept(&visitor);
	Triangle * tri_3 = (Triangle*)chargeur->charge("triangle3.txt");
	//cout <<(Triangle) *tri_3 << endl;

	Polygone p("Polygone:p0(1,1),p1(2,3),p2(2,5),p3(1,6),p4(0,5),p5(0,3)");
	cout << p << endl;
	p.accept(&visitor);
	Polygone * poly_4 = (Polygone*)chargeur->charge("polygone4.txt");
	cout << *poly_4 << endl;



	try
	{
		string adresseServeur = "127.0.0.1";
		int portServeurDessin = 8091;

		ClientDessin clientDessin(adresseServeur, portServeurDessin);

		string titre = "fenêtre ouverte par un client C++ distant";

		int bordGauche = 300;
		int bordHaut = 400;
		int largeur = 800;
		int hauteur = 800;

		clientDessin.ouvreFenetreGraphique(titre, bordGauche, bordHaut, largeur, hauteur);

		int x1 = 0;
		int y1 = 0;
		int x2 = 500;
		int y2 = 500;

		clientDessin.traceSegment(x1, y1, x2, y2);

	}
	catch (Erreur e)
	{
		cerr << e << endl;
	}

	system("pause");


    /*
    *   Code de test et démonstration de Cercle, Segment, leurs fonctions de string et constructeurs depuis string
    *   Ainsi que du dp OpenGLVisiteur.
    *   Contentez-vous de le commenter si vous avez pas effectué le linkage:
    *
    *   #include"OpenGLVisiteur.h" se charge d'inclure opengl et la SDL2
    *
    *   -lmingw32 (sous mingw uniquement)
    *   -lopengl32
    *   -lglu32
    *   -lglaux
    *   -lSDL2main
    *   -lSDL2
    *   -lSDL2.dll
    *   N'oubliez pas que l'ordre importe.
    *
    *   Le main DOIT IMPERATIVEMENT CONTENIR ARGC ET ARGV, sinon ça ne marchera pas (SDL2).
    *
    *
    */
   /* Cercle cc("Cercle(rayon(142),centre(0,0))");
    cc.setColor(GREEN);
    cout<<cc<<endl;

    Segment ss("Segment((300,300),(-300,-300))");
    cout<<ss<<endl;

    Homothetie h(0.5,0.5);
    TransformerVisiteur tv(&h);
    ss.accept(&tv);
    cout<<ss<<endl;

    Vecteur2D   p1(10,10),
                p2(200,10),
                p3(10,200);
    Triangle tt(p1,p2,p3,YELLOW);

    Vecteur2D v1(0,0);
    Vecteur2D v2(100,100);
    Vecteur2D v3(0,50);
    Vecteur2D v4(-100,100);

    vector<Vecteur2D> pts;
    pts.insert(pts.end(),v1);
    pts.insert(pts.end(),v2);
    pts.insert(pts.end(),v3);
    pts.insert(pts.end(),v4);

    Polygone pp(pts,RED);

    OpenGLVisiteur glv(false);
    cc.accept(&glv);
    tt.accept(&glv);
    ss.accept(&glv);
    pp.accept(&glv);
    glv.render();*/

    return 0;
}
