#ifndef CGraphe_h
#define CGraphe_h

#include "CSommet.h"

#define NULL 0;

class CGraphe
{
	private:
		CListe<CSommet> LISGRASommet; //Liste des sommets du graphe
		bool bGRAEstOriente; //Booléen, Indique si le graphe est orienté ou non (true si orienté et false si non orienté)

	public:
		/*******************************************************
		***** CGRAPHE : Constructeur par défaut de CGraphe *****
		********************************************************
		***** Entrée :                                     *****
		***** Nécessite :                                  *****
		***** Sortie :                                     *****
		***** Entraine : Le contructeur a initialisé un    *****
		***** objet CGraphe avec bGRAEstOriente            *****
		***** égal à true                                  *****
		*******************************************************/
		CGraphe();

		//CGraphe(CGraphe &GRAParam);

		/*******************************************************
		***** CGRAPHE : Constructeur de confort de CGraphe *****
		********************************************************
		***** Entrée : bEstOriente, booléen, indication du *****
		***** type de graphe (orienté ou non)              *****
		***** Nécessite :                                  *****
		***** Sortie :                                     *****
		***** Entraine : Le contructeur a initialisé       *****
		***** un objet CGraphe ayant                       *****
		***** bGRAEstOriente = bEstOriente                 *****
		*******************************************************/
		CGraphe(bool bEstOriente);

		//~CGraphe();

		/****************************************************************************
		***** GRALIREESTORIENTE : Accesseur direct en lecture de bGRAEstOriente *****
		*****************************************************************************
		***** Entrée :                                                          *****
		***** Nécessite :                                                       *****
		***** Sortie : booléen, valeur de l'attribut bGRAEstOriente             *****
		***** Entraine : GRALireEstOriente() = bGRAEstOriente                   *****
		****************************************************************************/
		bool GRALireEstOriente();

		/***************************************************************************
		***** GRALIRELISTESOMMET : Accesseur direct en lecture de LISGRASommet *****
		****************************************************************************
		***** Entrée :                                                         *****
		***** Nécessite :                                                      *****
		***** Sortie : Objet de type CListe<CSommet>, valeur de l'attribut     *****
		***** LISGRASommet                                                     *****
		***** Entraine : GRALireListeSommet() = LISGRASommet                   *****
		***************************************************************************/
		CListe<CSommet> GRALireListeSommet();

		/*******************************************************************************
		***** GRAAJOUTERSOMMET : Fonction permettant d'ajouter un sommet au graphe *****
		********************************************************************************
		***** Entrée : uiId, entier non signé, identifiant du sommet à ajouter     *****
		***** Nécessite :                                                          *****
		***** Sortie :                                                             *****
		***** Entraine : LISGRASommet contient la liste des sommets du graphe,     *****
		***** additionnée du sommet à ajouter                                      *****
		*******************************************************************************/
		void GRAAjouterSommet(unsigned int uiId);

		/************************************************************************************
		***** GRASUPPRIMERSOMMET : Fonction permettant de supprimer un sommet du graphe *****
		*************************************************************************************
		***** Entrée : uiId, entier non signé, identifiant du sommet à supprimer        *****
		***** Nécessite :                                                               *****
		***** Sortie :                                                                  *****
		***** Entraine : LISGRASommet contient la liste des sommets du graphe,          *****
		***** soustraite du sommet à supprimer                                          *****
		************************************************************************************/
		void GRASupprimerSommet(unsigned int uiId);

		/***************************************************************************
		***** GRAAFFICHER : Fonction permettant d'afficher un graphe à l'écran *****
		****************************************************************************
		***** Entrée :                                                         *****
		***** Nécessite :                                                      *****
		***** Sortie :                                                         *****
		***** Entraine : La fonction à affiché les informations du graphe à    *****
		***** l'écran                                                          *****
		***************************************************************************/
		void GRAAfficher();

		void GRAAjouterArc(unsigned int uiIdSommet, unsigned int uiIdDestination);

		void GRASupprimerArc(unsigned int uiIdSommet, unsigned int uiIdDestination);

		void GRAInverserGraphe();
		
		//CGraphe& operator=(CGraphe &GRAParam);

};

#endif