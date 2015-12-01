package clientserveurdessin.serveur.mieux;

/**
 * repr�sente la session de dessin entreprise par un client distant.
 * 
 * Effectue principalement les op�rations suivantes :
 * 
 * ouvre une fen�tre awt (Frame) pour dessiner dessus (les coordonn�es de la fen�tre sont indiqu�es par le client).
 * puis ex�cute sur la fen�tre ouverte tous les ordres de trac� du client distant.
 * 
 * fonctionne dans un thread s�par� du thread principal.
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
 * cr�e la session de dessin avec le client distant connect� sur socket
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
	    requete = this.fluxEntrant.readLine();  // lit le titre et les 4 coordonn�es Ox, Oy, largeur et hauteur de la fen�tre, les arguments sont s�par�s par des ","
	    System.out.println("requete re�ue : " + requete);
	    String arguments[] = requete.split(",");            // redondance de code � �liminer
	    
	    requete = this.fluxEntrant.readLine();
		System.out.println("requete re�ue : " + requete);
	    
	    String titre;
	    int Ox, Oy, largeur, hauteur;
	    
	    titre = arguments[0].trim();
	    Ox = Integer.parseInt(arguments[1].trim());         // redondance de code � �liminer pour 8 lignes !!!! cf. lignes suivantes
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
			
			//requete = this.fluxEntrant.readLine();  // lit l'instruction de trac� et les 4 param�tres entiers du trac�, les arguments sont s�par�s par des ","
			
			//System.out.println("requete re�ue : " + requete);
        
			Thread.sleep(5);
			
			bf.show();
			graphics.dispose();
        } // while
    }
	
	catch (SocketException e)
	    {
	    System.out.println("session de dessin termin�e par le client");
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

