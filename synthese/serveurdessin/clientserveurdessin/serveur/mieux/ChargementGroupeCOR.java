/**
 * 
 */
package clientserveurdessin.serveur.mieux;

import java.awt.Graphics;
import java.util.ArrayList;

/**
 * @author J�r�me
 *
 */
public class ChargementGroupeCOR extends ChargementFormeCOR {

	/**
	 * Methode qui impl�mente la solution donnner par cette expert
	 * @param s String a parser pour d�terminer si le cas est trat� par le COR
	 * @param g Graphics sur le quelle on d�ssine le forme parser
	 * @throws DessinException Exception lanc� si cas non g�r� dans un expert ou le COR
	 */
	public void expertise(String s, Graphics g) throws DessinException {
		ChargementPolygoneCOR cor= new ChargementPolygoneCOR();
		ChargementSegmentCOR seg = new ChargementSegmentCOR();
		ChargementTriangleCOR tri= new ChargementTriangleCOR();
		ChargementCercleCOR cer =new ChargementCercleCOR();
		tri.setSuivant(cer);
		seg.setSuivant(tri);
		cor.setSuivant(seg);
		
		String nom =s.substring(0,6);
		if(!nom.equals("Groupe"))
		{	throw new DessinException(); }
		else
		{   int fo_count=0;//compteur du nbre de forme dans la pos
			
			int decalage = 0;
			int pos = 0;
			int fpos;
			for(int i=0;i<s.length();i++)
			{	if(s.charAt(i)=='p')
					{ fo_count= fo_count+1;}
			}

			for (int i = 0; i < fo_count; i++)
			{
				pos = s.indexOf('{',pos+1);// on arrive sur une forme
				if (pos == -1)
					throw new DessinException();
				else
				{
					fpos = s.indexOf('}', pos +1);
					String forme_courante = s.substring(pos + 1, fpos-decalage);
					// recup�rer la couleur du groupe et la concatener � la string envoyer
					System.out.println(forme_courante+"ici");
					cor.dessiner(forme_courante, g);
					/*if ((forme_courante.find(tri)) != string::npos)
					{
						Groupe::addForme(new Triangle(forme_courante));
						decalage = decalage + forme_courante.size();
					}*/
				}
			}
			
			
		}
	/*"Groupe:{Triangle:p1(1,1),p2(4,5),p3(3,7)},"
	+ "{Segment((0.1,2),(3,4.5))},"
	+ "{Cercle(rayon(10),centre(0.5,512.5))},"
	+ "{Polygone:p0(1,1),p1(2,3),p2(2,5),p3(1,6),p4(0,5),p5(0,3)}");*/
	}

}
