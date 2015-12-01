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
public class ChargementPolygoneCOR extends ChargementFormeCOR {
	
	/**
	 * Methode qui implémente la solution donnner par cette expert
	 * @param s String a parser pour déterminer si le cas est traté par le COR
	 * @param g Graphics sur le quelle on déssine le forme parser
	 * @throws DessinException Exception lancé si cas non géré dans un expert ou le COR
	 */
	public void expertise(String s, Graphics g) throws DessinException {
		String nom=new String(s.substring(0,8));
		if(!nom.equals("Polygone"))
			throw new DessinException();
		else
		{
		int nbPoints=0;
		for(int i=0;i<s.length();i++)
		{	if(s.charAt(i)=='p')
				{ nbPoints=nbPoints+1;}
		}
		
		ArrayList<Integer> pointList= new ArrayList<Integer>();
		int decalage =0;
		int polyPos=s.indexOf("Polygone");
		int pos=0;
		int vpos=0;
		for(int i=0;i<nbPoints;i++)
		{	
			System.out.println("iteration");			
			pos=s.indexOf("(");
			if(pos==-1)
				throw new DessinException();
			pos=pos+decalage;
			vpos = s.indexOf(")",pos);
			vpos = s.indexOf(",",vpos+1);
			if(vpos==-1) throw new DessinException();
			String res = s.substring( polyPos+pos , vpos-polyPos);
			decalage=decalage+8;
			System.out.println(res);
			readPoint(res, pointList);
		}	
			int sz=pointList.size();
			for(int i=0;i<sz;i+=2)
			{
				g.drawLine(pointList.get(i), pointList.get(i+1),
							pointList.get(i+3<sz?i+3:i+3-sz), pointList.get(i+4<sz?i+3:i+4-sz));
			}
		}
	}
}

