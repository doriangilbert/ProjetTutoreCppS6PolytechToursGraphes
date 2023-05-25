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
		CListe<CSommet>& GRALireListeSommet();

		/*******************************************************************************************
		***** GRAAJOUTERSOMMET : Fonction permettant d'ajouter un sommet au graphe *****************
		********************************************************************************************
		***** Entrée : uiId, entier non signé, identifiant du sommet à ajouter                 *****
		***** Nécessite :                                                                      *****
		***** Sortie :                                                                         *****
		***** Entraine : LISGRASommet contient la liste des sommets du graphe,                 *****
		***** additionnée du sommet à ajouter OU											   *****
		***** Exception EstDejaDansLaListe: Ne peut pas rajouter des elements déjà existants   *****
		*******************************************************************************************/
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

		/************************************************************************************************
		***** GRAAJOUETERArc : Fonction permettant d'ajouter un arc entre 2 sommet du graphe ************
		*************************************************************************************************
		***** Entrée : uiId, entier non signé, identifiant du sommet partants                       *****
		***** uiIdDestination, entier non signé, identifiant du sommet Arrivants                    *****
		***** Nécessite :                                                                           *****
		***** Sortie :                                                                              *****
		***** Entraine : Elle ajoute un arc entre les deux Sommet choisis OU                        *****
		***** Exception NEstPasDansLaListe: Ne peut pas ajouter un arc de Sommet non existants      *****
		************************************************************************************************/
		void GRAAjouterArc(unsigned int uiIdSommet, unsigned int uiIdDestination);

		/************************************************************************************************
		***** GRASUPPRIMERARC : Fonction permettant de supprimer un arc entre 2 sommet du graphe ********
		*************************************************************************************************
		***** Entrée : uiId, entier non signé, identifiant du sommet partants                       *****
		***** uiIdDestination, entier non signé, identifiant du sommet Arrivants                    *****
		***** Nécessite :                                                                           *****
		***** Sortie :                                                                              *****
		***** Entraine : Elle supprime un arc entre les deux Sommet choisis OU                      *****
		***** Exception NEstPasDansLaListe: Ne peut pas supprimer un arc de Sommet non existants    *****
		************************************************************************************************/
		void GRASupprimerArc(unsigned int uiIdSommet, unsigned int uiIdDestination);

		/************************************************************************************************
		***** GRAINVERSERGRAPHE : Fonction permettant d'inverser les arcs du graphe *********************
		*************************************************************************************************
		***** Entrée :																				*****
		***** Nécessite :                                                                           *****
		***** Sortie :                                                                              *****
		***** Entraine : Elle supprime un arc entre les deux Sommet choisis                         *****
		************************************************************************************************/
		CGraphe& GRAInverserGraphe();

};

#endif