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
	 * @param s String a parser pour d�terminer si le cas est trat� par le COR
	 * @param g Graphics sur le quelle on d�ssine le forme parser
	 * @throws DessinException Exception lanc� si cas non g�r� dans un expert ou le COR
	 */
	public abstract void expertise(String s,Graphics g)throws DessinException;
	
	/**
	 * 	Methode qui sert � parser une string correspondant � un point
	 *  La string doit �tre comme suit "(x,y)"
	 * @param s String d'un point � mettre dans le tableau list
	 * @param list ArrayListe d'integer, destin� � contenir les points � dessiner
	 * @throws DessinException Exception lanc� si cas non g�r� dans un expert ou le COR
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
	 * Dessine la forme d�crite par la cha�ne s et passe au suivant en cas d'�chec.
	 * @param s la cha�ne d�crivant la forme � dessiner.
	 * @param g l'objet graphique � utiliser pour dessiner.
	 * @throws DessinException en cas d'�chec.
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
	 * D�finit le prochain maillon de la cha�ne de responsabilit�
	 * @param _suivant la prochain maillon
	 */
	public void setSuivant(ChargementFormeCOR _suivant)
	{
		suivant=_suivant;
	}
}
