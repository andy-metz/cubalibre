/**
 * 
 */
package clientserveurdessin.serveur.mieux;

import java.awt.Graphics;

/**
 * @author andre
 *
 */
public class ChargementSegmentCOR extends ChargementFormeCOR{

	@Override
	public void expertise(String s, Graphics g) throws DessinException {
		// TODO Auto-generated method stub
		int index;
		if(s.indexOf("Segment:")  != 0)
			throw new DessinException();
		else
		{
			
			double x1, y1, x2, y2;
			int vecposparenthese, vecposvirgule;
			
			vecposparenthese = s.indexOf("(");
			vecposvirgule = s.indexOf(",");		
			x1 = Double.parseDouble(s.substring(vecposparenthese, vecposvirgule));
			
			vecposparenthese = s.indexOf(")");	
			y1 = Double.parseDouble(s.substring(vecposvirgule+1, vecposparenthese));			
			System.out.println(x1+y1);
			
	        //((Object) g).getBufferStrategy().show();
		}
	}

}
