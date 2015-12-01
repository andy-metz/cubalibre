package clientserveurdessin.serveur.mieux;

/**
 * représente la session de dessin entreprise par un client distant.
 * 
 * Effectue principalement les opérations suivantes :
 * 
 * ouvre une fenêtre awt (Frame) pour dessiner dessus (les coordonnées de la fenêtre sont indiquées par le client).
 * puis exécute sur la fenêtre ouverte tous les ordres de tracé du client distant.
 * 
 * fonctionne dans un thread séparé du thread principal.
 * 
 * */
import java.net.Socket;
import java.awt.Color;
import java.awt.Frame;
import java.awt.Graphics;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferStrategy;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.SocketException;


public class SessionDessin extends Thread
{
private
Socket socket;                  // pour dialoguer avec le client distant. Peut-on se passer de cet attribut ?
BufferedReader fluxEntrant;     // flux entrant pour recevoir les requetes du client

/**
 * crée la session de dessin avec le client distant connecté sur socket
 * @throws IOException 
 * 
 * */
public SessionDessin(Socket socket) throws IOException
{
this.socket = socket;
this.fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
}

@Override
public void run()
{
	String requete;
	
	try
    {
	    requete = this.fluxEntrant.readLine();  // lit le titre et les 4 coordonnées Ox, Oy, largeur et hauteur de la fenêtre, les arguments sont séparés par des ","
	    System.out.println("requete reçue : " + requete);
	    String arguments[] = requete.split(",");            // redondance de code à éliminer
	    
	    requete = this.fluxEntrant.readLine();
		System.out.println("requete reçue : " + requete);
	    
	    String titre;
	    int Ox, Oy, largeur, hauteur;
	    
	    titre = arguments[0].trim();
	    Ox = Integer.parseInt(arguments[1].trim());         // redondance de code à éliminer pour 8 lignes !!!! cf. lignes suivantes
	    Oy = Integer.parseInt(arguments[2].trim());
	    largeur = Integer.parseInt(arguments[3].trim());
	    hauteur = Integer.parseInt(arguments[4].trim());
	    
	    //CadreDessin cadreDessin = new CadreDessin(titre,Ox,Oy,largeur,hauteur);
	    Frame frame=new Frame(titre);
		frame.addWindowListener(
				new WindowAdapter(){
					public void windowClosing(WindowEvent evt){
						Frame f=(Frame)evt.getSource();
						f.dispose();
					}
				}
			);
	    
		//frame.setBounds(400,200,400,400);
		frame.setBounds(Ox,Oy,largeur,hauteur);
		frame.setVisible(true);
		frame.setIgnoreRepaint(true);
		frame.createBufferStrategy(2);
	    
		BufferStrategy bf= frame.getBufferStrategy();
		
		long time;
		
		ChargementPolygoneCOR cor= new ChargementPolygoneCOR();
		ChargementSegmentCOR seg = new ChargementSegmentCOR();
		ChargementTriangleCOR tri= new ChargementTriangleCOR();
		ChargementCercleCOR cer =new ChargementCercleCOR();
		ChargementGroupeCOR grp = new ChargementGroupeCOR();
		cer.setSuivant(grp);
		tri.setSuivant(cer);
		seg.setSuivant(tri);
		cor.setSuivant(seg);

	    while (true)
        {
	    	bf=frame.getBufferStrategy();
			Graphics graphics=bf.getDrawGraphics();
			graphics.clearRect(Ox,Oy,largeur,hauteur);
			graphics.setColor(Color.GRAY);
			graphics.fillRect(Ox,Oy,largeur,hauteur);
			
			time=System.currentTimeMillis();
			
			try {
				cor.dessiner(requete, graphics);
			} catch (DessinException e) {
				
				e.printStackTrace();
			}
			
			//requete = this.fluxEntrant.readLine();  // lit l'instruction de tracé et les 4 paramètres entiers du tracé, les arguments sont séparés par des ","
			
			//System.out.println("requete reçue : " + requete);
        
			Thread.sleep(5);
			
			bf.show();
			graphics.dispose();
        } // while
    }
	
	catch (SocketException e)
	    {
	    System.out.println("session de dessin terminée par le client");
	    }
	catch (NumberFormatException e)
	    {
		System.out.println("NumberFormatException");
	    e.printStackTrace();
	    }
	catch (IOException e)
	    {
		System.out.println("IOException");
	    e.printStackTrace();
	    }
	catch (InterruptedException e)
	    {
		System.out.println("InterruptedException");
	    e.printStackTrace();
	    }
	}
}

