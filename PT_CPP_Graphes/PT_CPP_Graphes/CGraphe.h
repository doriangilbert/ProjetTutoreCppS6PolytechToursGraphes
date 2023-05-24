#ifndef CGraphe_h
#define CGraphe_h

#include "CSommet.h"

#define NULL 0;

class CGraphe
{
	private:
		CListe<CSommet> LISGRASommet; //Liste des sommets du graphe
		bool bGRAEstOriente; //Bool�en, Indique si le graphe est orient� ou non (true si orient� et false si non orient�)

	public:
		/*******************************************************
		***** CGRAPHE : Constructeur par d�faut de CGraphe *****
		********************************************************
		***** Entr�e :                                     *****
		***** N�cessite :                                  *****
		***** Sortie :                                     *****
		***** Entraine : Le contructeur a initialis� un    *****
		***** objet CGraphe avec bGRAEstOriente            *****
		***** �gal � true                                  *****
		*******************************************************/
		CGraphe();

		//CGraphe(CGraphe &GRAParam);

		/*******************************************************
		***** CGRAPHE : Constructeur de confort de CGraphe *****
		********************************************************
		***** Entr�e : bEstOriente, bool�en, indication du *****
		***** type de graphe (orient� ou non)              *****
		***** N�cessite :                                  *****
		***** Sortie :                                     *****
		***** Entraine : Le contructeur a initialis�       *****
		***** un objet CGraphe ayant                       *****
		***** bGRAEstOriente = bEstOriente                 *****
		*******************************************************/
		CGraphe(bool bEstOriente);

		//~CGraphe();

		/****************************************************************************
		***** GRALIREESTORIENTE : Accesseur direct en lecture de bGRAEstOriente *****
		*****************************************************************************
		***** Entr�e :                                                          *****
		***** N�cessite :                                                       *****
		***** Sortie : bool�en, valeur de l'attribut bGRAEstOriente             *****
		***** Entraine : GRALireEstOriente() = bGRAEstOriente                   *****
		****************************************************************************/
		bool GRALireEstOriente();

		/***************************************************************************
		***** GRALIRELISTESOMMET : Accesseur direct en lecture de LISGRASommet *****
		****************************************************************************
		***** Entr�e :                                                         *****
		***** N�cessite :                                                      *****
		***** Sortie : Objet de type CListe<CSommet>, valeur de l'attribut     *****
		***** LISGRASommet                                                     *****
		***** Entraine : GRALireListeSommet() = LISGRASommet                   *****
		***************************************************************************/
		CListe<CSommet> GRALireListeSommet();

		/*******************************************************************************
		***** GRAAJOUTERSOMMET : Fonction permettant d'ajouter un sommet au graphe *****
		********************************************************************************
		***** Entr�e : uiId, entier non sign�, identifiant du sommet � ajouter     *****
		***** N�cessite :                                                          *****
		***** Sortie :                                                             *****
		***** Entraine : LISGRASommet contient la liste des sommets du graphe,     *****
		***** additionn�e du sommet � ajouter                                      *****
		*******************************************************************************/
		void GRAAjouterSommet(unsigned int uiId);

		/************************************************************************************
		***** GRASUPPRIMERSOMMET : Fonction permettant de supprimer un sommet du graphe *****
		*************************************************************************************
		***** Entr�e : uiId, entier non sign�, identifiant du sommet � supprimer        *****
		***** N�cessite :                                                               *****
		***** Sortie :                                                                  *****
		***** Entraine : LISGRASommet contient la liste des sommets du graphe,          *****
		***** soustraite du sommet � supprimer                                          *****
		************************************************************************************/
		void GRASupprimerSommet(unsigned int uiId);

		/***************************************************************************
		***** GRAAFFICHER : Fonction permettant d'afficher un graphe � l'�cran *****
		****************************************************************************
		***** Entr�e :                                                         *****
		***** N�cessite :                                                      *****
		***** Sortie :                                                         *****
		***** Entraine : La fonction � affich� les informations du graphe �    *****
		***** l'�cran                                                          *****
		***************************************************************************/
		void GRAAfficher();

		void GRAAjouterArc(unsigned int uiIdSommet, unsigned int uiIdDestination);

		void GRASupprimerArc(unsigned int uiIdSommet, unsigned int uiIdDestination);

		void GRAInverserGraphe();
		
		//CGraphe& operator=(CGraphe &GRAParam);

};

#endif