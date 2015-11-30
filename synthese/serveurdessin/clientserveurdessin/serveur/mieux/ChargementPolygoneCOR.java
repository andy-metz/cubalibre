/**
 * 
 */
package clientserveurdessin.serveur.mieux;

import java.awt.Graphics;
import java.util.ArrayList;

/**
 * @author Jérôme
 *
 */
public class ChargementPolygoneCOR extends ChargementFormeCOR {
	private void readPoint(String s,ArrayList<Integer> list)throws DessinException
	{
		int po=s.indexOf("("),
			v=s.indexOf(","),
			pf=s.indexOf(")");
		if(po==-1||v==-1||pf==-1)
			throw new DessinException();
		String
			xs = new String(s.substring(po+1,v)),
			ys = new String(s.substring(v+1,pf));
		int x=(int)Float.parseFloat(xs),
			y=(int)Float.parseFloat(ys);
		list.add(x);
		list.add(y);
	}
	/* (non-Javadoc)
	 * @see clientserveurdessin.serveur.mieux.ChargementFormeCOR#expertise(java.lang.String, java.awt.Graphics)
	 */
	@Override
	public void expertise(String s, Graphics g) throws DessinException {
		int v1,v2; // virgule1, virgule2
		String nom=new String(s.substring(0,8));
		if(!nom.equals("Polygone"))
			throw new DessinException();
		v1=12;
		ArrayList<Integer> pointList= new ArrayList<Integer>();
		String points= new String(s.getBytes(),0,9);
		
		v2 = points.indexOf(",");
		if(v2==-1) throw new DessinException();
		
		
		while(v2!=-1)
		{
			readPoint(s.substring(v1+1, v2),pointList);
			
			v1=v2;
			v1 = points.indexOf(",");
			v2 = points.indexOf(",",v2+1);
			if(v1==-1) throw new DessinException();
			if(v2==-1) throw new DessinException();
		}
		
		
		int sz=pointList.size();
		for(int i=0;i<sz;i+=2)
		{
			g.drawLine(pointList.get(i), pointList.get(i+1),
						pointList.get(i+3<sz?i+3:i+3-sz), pointList.get(i+4<sz?i+3:i+4-sz));
		}
	}
}

