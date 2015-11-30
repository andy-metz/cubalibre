/**
 * 
 */
package clientserveurdessin.serveur.mieux;

import java.awt.Graphics;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @author andre
 *
 */
public class ChargementSegmentCOR extends ChargementFormeCOR{

	@Override
	public void expertise(String s, Graphics g) throws DessinException {
		// TODO Auto-generated method stub
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


	
	        //g.getBufferStrategy().show();
		}
	}

