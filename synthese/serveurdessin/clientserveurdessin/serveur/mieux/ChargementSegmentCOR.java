/**
 * 
 */
package clientserveurdessin.serveur.mieux;

import java.awt.Graphics;

import java.util.ArrayList;

import java.util.regex.Matcher;
import java.util.regex.Pattern;


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


		/*// 	} TODO Auto-generated method stub
		int index;
		// Test pour expression régulière
		// Gestion de groupe
		String essai = s;
		String sous_chaine;
		
		
		 Pattern p = Pattern.compile("Segment(.*)");
		 Matcher m = p.matcher(s);
		 boolean b = m.matches();
		 if(b)
		 {
			 sous_chaine = m.group(1);
			// Retirer les parenthèses ouvrantes et fermantes 
			sous_chaine = sous_chaine.replace("(", "");
			sous_chaine = sous_chaine.replace(")", "");

		
			String[] parts = sous_chaine.split(",");
			String part1 = parts[0];
			System.out.println("trouve: "+parts[0]+ " "+parts[1]+ " "+parts[2]+ " "+parts[3]+ " ");	
			
			int x1, y1, x2, y2;
			x1 = (int)Double.parseDouble(parts[0]);
			y1 = (int)Double.parseDouble(parts[1]);
			x2 = (int)Double.parseDouble(parts[2]);
			y2 = (int)Double.parseDouble(parts[3]);	
			g.drawLine(x1, y1, x2, y2);			
		 }
		 else
			 throw new DessinException();
			 }
			 */


	
	        //g.getBufferStrategy().show();
		
	}


