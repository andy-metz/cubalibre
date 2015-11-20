#include <iostream>
#include"Vecteur2D.hpp"

#include"Forme.hpp"

#include "Cercle.hpp"
#include"Segment.hpp"
#include"Triangle.hpp"
#include"Polygone.hpp"
#include "FormeVisiteur.hpp"
using namespace std;



int main()
{
 
    //Forme test(BLACK);
    //cout<<test.getColorAsString()<<endl;
	//Vecteur2D centre = Vecteur2D(2,2);
	//Cercle CE=Cercle(BLACK,centre,4);

	Cercle c("Cercle(rayon(10),centre(0.5,512.5))");
	cout << c << endl;

	Segment s("Segment((0.1,2),(3,4.5))");
	cout << s << endl;

	Triangle t("Triangle:p1(1,1),p2(4,5),p3(3,7)");
	cout << t << endl;
	
	Polygone p("Polygone:p0(1,1),p1(2, 3),p2(2, 5),p3(1, 6),p4(0, 5),p5(0, 3)");
	cout << p << endl;
	system("pause");
	/*C.accept(new SauvegardeTxt(C));*/
    return 0;
}
