/**
 * 
 */
package clientserveurdessin.serveur.mieux;

import java.awt.Graphics;
import java.util.ArrayList;

/**
 * @author Mertz olivier
 *
 */
public class ChargementSegmentCOR extends ChargementFormeCOR{
	/**
	 * Methode qui implémente la solution donnner par cette expert
	 * @param s String a parser pour déterminer si le cas est traté par le COR
	 * @param g Graphics sur le quelle on déssine le forme parser
	 * @throws DessinException Exception lancé si cas non géré dans un expert ou le COR
	 */
	public void expertise(String s, Graphics g) throws DessinException {
		String nom=new String(s.substring(0,7));
		ArrayList<Integer> pointList= new ArrayList<Integer>();
		if(!nom.equals("Segment"))
			throw new DessinException();
		else
		{	
			String vect_courant;
			int posParntheseOuvrante, posParentheseFermante;
			
			posParntheseOuvrante = s.indexOf("(",8);			
			posParentheseFermante = s.indexOf(")",posParntheseOuvrante)+1;
			vect_courant=s.substring(posParntheseOuvrante,posParentheseFermante);
			readPoint(vect_courant,pointList);
			posParntheseOuvrante=s.indexOf("(",posParentheseFermante);				
			posParentheseFermante = s.indexOf(")",posParntheseOuvrante)+1;
			vect_courant=s.substring(posParntheseOuvrante,posParentheseFermante);
			readPoint(vect_courant,pointList);
		}
		int sz=pointList.size();
		for(int i=0;i<sz;i+=2)
		{
			g.drawLine(pointList.get(i), pointList.get(i+1),
						pointList.get(i+3<sz?i+3:i+3-sz), pointList.get(i+4<sz?i+3:i+4-sz));
		}
	}
}
