/**
 * 
 */
package clientserveurdessin.serveur.mieux;

import java.awt.Graphics;
import java.util.ArrayList;

/**
 * @author Jérôme Olivier andré
 *
 */
public class ChargementGroupeCOR extends ChargementFormeCOR {

	/**
	 * Methode qui implémente la solution donnner par cette expert
	 * @param s String a parser pour déterminer si le cas est traté par le COR
	 * @param g Graphics sur le quelle on déssine le forme parser
	 * @throws DessinException Exception lancé si cas non géré dans un expert ou le COR
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
					// recupérer la couleur du groupe et la concatener à la string envoyer
					System.out.println(forme_courante+"ici");
					cor.dessiner(forme_courante, g);				
				}
			}
		}
	}

}
