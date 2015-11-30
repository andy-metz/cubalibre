/**
 * 
 */
package clientserveurdessin.serveur.mieux;

import java.awt.Graphics;

/**
*   @file    ChargementFormeCOR.hpp ChargementFormeCOR.cpp
*   @author  J�r�me Lartillot Olivier Mertz Andr� Erba
*   @version 1.0
*
*   @section DESCRIPTION
*
*   Classe ChargementFormeCOR pour d�finir une chaine de responsabilit�
*
*/
public abstract class ChargementFormeCOR {
	ChargementFormeCOR suivant;
	
	public ChargementFormeCOR(){
		suivant = null;
	}
	public abstract void expertise(String s,Graphics g)throws DessinException;
	
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
