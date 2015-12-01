/**
 * 
 */
package clientserveurdessin.serveur.mieux;

import java.awt.Graphics;
import java.util.ArrayList;


public abstract class ChargementFormeCOR {
	ChargementFormeCOR suivant;
	
	public ChargementFormeCOR(){
		suivant = null;
	}
	/**
	 * 
	 * @param s String a parser pour déterminer si le cas est traté par le COR
	 * @param g Graphics sur le quelle on déssine le forme parser
	 * @throws DessinException Exception lancé si cas non géré dans un expert ou le COR
	 */
	public abstract void expertise(String s,Graphics g)throws DessinException;
	
	/**
	 * 	Methode qui sert à parser une string correspondant à un point
	 *  La string doit être comme suit "(x,y)"
	 * @param s String d'un point à mettre dans le tableau list
	 * @param list ArrayListe d'integer, destiné à contenir les points à dessiner
	 * @throws DessinException Exception lancé si cas non géré dans un expert ou le COR
	 */
	public void readPoint(String s,ArrayList<Integer> list)throws DessinException
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
	/**
	 * Dessine la forme décrite par la chaîne s et passe au suivant en cas d'échec.
	 * @param s la chaîne décrivant la forme à dessiner.
	 * @param g l'objet graphique à utiliser pour dessiner.
	 * @throws DessinException en cas d'échec.
	 */
	public void dessiner(String s,Graphics g)throws DessinException
	{
		try
		{
			expertise(s,g);
		}
		catch(DessinException e)
		{
			if(suivant==null)
				throw new DessinException();
			else
				suivant.dessiner(s,g);
		}
	}
	/**
	 * Définit le prochain maillon de la chaîne de responsabilité
	 * @param _suivant la prochain maillon
	 */
	public void setSuivant(ChargementFormeCOR _suivant)
	{
		suivant=_suivant;
	}
}
