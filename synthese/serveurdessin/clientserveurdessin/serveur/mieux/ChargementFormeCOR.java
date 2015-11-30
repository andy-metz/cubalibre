/**
 * 
 */
package clientserveurdessin.serveur.mieux;

import java.awt.Graphics;

/**
*   @file    ChargementFormeCOR.hpp ChargementFormeCOR.cpp
*   @author  Jérôme Lartillot Olivier Mertz André Erba
*   @version 1.0
*
*   @section DESCRIPTION
*
*   Classe ChargementFormeCOR pour définir une chaine de responsabilité
*
*/
public abstract class ChargementFormeCOR {
	ChargementFormeCOR suivant;
	
	public ChargementFormeCOR(){
		suivant = null;
	}
	public abstract void expertise(String s,Graphics g)throws DessinException;
	
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
