#include "Groupe.hpp"

/**
*	Destructeur de la classe Groupe
*/
Groupe::~Groupe(){
}

/**
*	Constructeur littérale de la classe Groupe avec couleur Black par défaut
*	@param liste: le vector de l'ensemble des formes du groupes
*/
Groupe::Groupe(const vector<Forme*> liste):Forme(){
	Groupe::liste_forme = liste;
}
/**
*	Constructeur littérale de la class Groupe avec choix de couleur
*	@param liste : le vector de l'ensemble des formes du groupes
*	@param couleur: la couleur de l'ensemble du groupe
*/
Groupe::Groupe(const vector<Forme*> liste, Color couleur):Forme(couleur){
	Groupe::liste_forme = liste;
}
/*
*	Constructeur par recopie de la classe Groupe
*	@param G: le groupe a recopier
*/
Groupe::Groupe(const Groupe &G):Forme(G),liste_forme(G.liste_forme){
}
/**
*	Constructeur par string de la classe Groupe
*	@param s : la string qui permet de construire le groupe
*	format  :"Groupe:{..},{..},{..}"
*	Chaque accolade {..} contient une forme
*/
Groupe::Groupe(const string &s){
	int fo_count=0;//compteur du nbre de forme dans la pos
	string tri = "Triangle", cer = "Cercle", seg = "Segment", poly = "Polygone";
	string forme_courante;
	int decalage = 0;
	int pos = 0;
	int fpos;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '}')
		fo_count = fo_count + 1;
	}

	for (int i = 0; i < fo_count; i++)
	{
		pos = s.find('{',pos+1);// on arrive sur une forme
		if (pos == string::npos)
			throw Erreur("Le format de la chaine non reconnu par le constructeur");
		else
		{
			fpos = s.find('}', pos +1);
			fpos = fpos -1;
			forme_courante = s.substr(pos + 1, fpos-7-decalage);
			if ((forme_courante.find(tri)) != string::npos)
			{
				Groupe::addForme(new Triangle(forme_courante));
				decalage = decalage + forme_courante.size();
			}
			if ((forme_courante.find(cer)) != string::npos)
			{
				Groupe::addForme(new Cercle(forme_courante));
				decalage = decalage + forme_courante.size();
			}
			if ((forme_courante.find(seg)) != string::npos)
			{
				Groupe::addForme(new Segment(forme_courante));
				decalage = decalage + forme_courante.size();
			}
			if ((forme_courante.find(poly)) != string::npos)
			{
				Groupe::addForme(new Polygone(forme_courante));
				decalage = decalage + forme_courante.size();
			}
		}
	}
}
/**
*	Setter de forme de la classe Groupe
*	@param liste: le nouveau vector de Forme
*/
void Groupe::setFormes(const vector<Forme*> liste){
	Groupe::liste_forme = liste;
}
/**
*	Getter du vector<Forme*> de la classe Groupe
*	@return le vector<Forme*> du Groupe qui contient les formes du groupes
*/
const vector<Forme*> Groupe::getFormes()const{
	return liste_forme;
}
/**
*	Méthode pour ajouter une forme au groupe
*	@param F: la forme à ajouter
*/
void Groupe::addForme(Forme *F){
	if (F == NULL)
	{	throw Erreur("La Forme doit etre definie !=NULL");
	}
	else{
		F->setColor(Groupe::getColor());
		Groupe::liste_forme.push_back((Forme*)F);
	}
}
/**
*	Méthode accept qui permet de se faire visiter par un FormeVisiteur
*	@param fv : la classe dérivée de forme visiteur
*	implémentant la fonctionnalité souhaitée
*/
void Groupe::accept(FormeVisiteur *fv)
{	fv->visit(this);
}
/**
*	Méthode calculant l'aire du groupe
*	@return l'aire totale du groupe
*/
double Groupe::calculerAire()const{
	double area=0;
	string s_type;
	for (int i = 0; i < liste_forme.size(); i++)
	{
		s_type = (typeid(*liste_forme[i]).name());
		if (s_type == typeid(Cercle).name())
		{
			Cercle* C = dynamic_cast<Cercle *> (liste_forme[i]);
			area=area+C->calculerAire();
		}
		if (s_type == typeid(Triangle).name())
		{
			Triangle* T = dynamic_cast<Triangle*>(liste_forme[i]);
			area = area + T->calculerAire();
		}
		if (s_type == typeid(Segment).name())
		{
			Segment* S = dynamic_cast <Segment*>(liste_forme[i]);
			area = area + S->calculerAire();
		}
		if (s_type == typeid(Polygone).name())
		{
			Polygone* P = dynamic_cast<Polygone*>(liste_forme[i]);
			area = area + P->calculerAire();
		}
	}
	return area;
}
/**
*	Opérateur de conversion d'un groupe en string
*	@return le groupe convertie en string
*/
Groupe::operator string()const{
	stringstream ss;
	ss << "Groupe:";
	string s_type;

 	for (int i = 0;	i<liste_forme.size();i++)
	{
		s_type=(typeid(*liste_forme[i]).name());
		if (s_type == typeid(Cercle).name())
		{
			Cercle* C = dynamic_cast<Cercle *> (liste_forme[i]);
			ss << "{" << *C << "}";
			ss << ",";
		}
		if (s_type == typeid(Triangle).name())
		{
			Triangle* T = dynamic_cast<Triangle*>(liste_forme[i]);
			ss << "{" << *T << "}";
			ss << ",";
		}
		if (s_type == typeid(Segment).name())
		{
			Segment* S = dynamic_cast <Segment*>(liste_forme[i]);
			ss << "{" << *S << "}";
			ss << ",";
		}
		if (s_type == typeid(Polygone).name())
		{
			Polygone* P = dynamic_cast<Polygone*>(liste_forme[i]);
			ss << "{" << *P << "}";
			ss << ",";
		}
			
	}
	ss << "end";
	string s= ss.str();
	return s;
}
/**
*	Renvoie le groupe sous forme de string dans un flux
*	@param stream: le fluxà modifié
*	@param G: le groupe sous forme de string
*	@return le flux modifié
*/
ostream&operator<<(ostream&stream, const Groupe &G){
	stream << (string)G;
	return stream;
}
