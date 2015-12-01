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
public class ChargementCercleCOR extends ChargementFormeCOR{
	/**
	 * Methode qui impl�mente la solution donnner par cette expert
	 * @param s String a parser pour d�terminer si le cas est trat� par le COR
	 * @param g Graphics sur le quelle on d�ssine le forme parser
	 * @throws DessinException Exception lanc� si cas non g�r� dans un expert ou le COR
	 */
	public void expertise(String s, Graphics g) throws DessinException {
		String nom =s.substring(0,6);
		ArrayList<Integer> pointList= new ArrayList<Integer>();
		if(!nom.equals("Cercle"))
		{	throw new DessinException(); }
		else
		{	//"Cercle(rayon(10),centre(0.5,512.5))"
			int posRay=s.indexOf("rayon");
			int parentheseFermante=s.indexOf(")",posRay);
			double ray=Double.parseDouble(s.substring(posRay+6,parentheseFermante));
			System.out.println(ray);
			
			int debPosCentre=s.indexOf("(",parentheseFermante);
			int finPosCentre=s.length()-1;
			String res=s.substring(debPosCentre,finPosCentre);
			System.out.println(res);
			
		}
	}
	
}
