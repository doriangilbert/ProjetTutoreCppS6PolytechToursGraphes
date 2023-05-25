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
		CListe<CSommet>& GRALireListeSommet();

		/*******************************************************************************************
		***** GRAAJOUTERSOMMET : Fonction permettant d'ajouter un sommet au graphe *****************
		********************************************************************************************
		***** Entr�e : uiId, entier non sign�, identifiant du sommet � ajouter                 *****
		***** N�cessite :                                                                      *****
		***** Sortie :                                                                         *****
		***** Entraine : LISGRASommet contient la liste des sommets du graphe,                 *****
		***** additionn�e du sommet � ajouter OU											   *****
		***** Exception EstDejaDansLaListe: Ne peut pas rajouter des elements d�j� existants   *****
		*******************************************************************************************/
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

		/************************************************************************************************
		***** GRAAJOUETERArc : Fonction permettant d'ajouter un arc entre 2 sommet du graphe ************
		*************************************************************************************************
		***** Entr�e : uiId, entier non sign�, identifiant du sommet partants                       *****
		***** uiIdDestination, entier non sign�, identifiant du sommet Arrivants                    *****
		***** N�cessite :                                                                           *****
		***** Sortie :                                                                              *****
		***** Entraine : Elle ajoute un arc entre les deux Sommet choisis OU                        *****
		***** Exception NEstPasDansLaListe: Ne peut pas ajouter un arc de Sommet non existants      *****
		************************************************************************************************/
		void GRAAjouterArc(unsigned int uiIdSommet, unsigned int uiIdDestination);

		/************************************************************************************************
		***** GRASUPPRIMERARC : Fonction permettant de supprimer un arc entre 2 sommet du graphe ********
		*************************************************************************************************
		***** Entr�e : uiId, entier non sign�, identifiant du sommet partants                       *****
		***** uiIdDestination, entier non sign�, identifiant du sommet Arrivants                    *****
		***** N�cessite :                                                                           *****
		***** Sortie :                                                                              *****
		***** Entraine : Elle supprime un arc entre les deux Sommet choisis OU                      *****
		***** Exception NEstPasDansLaListe: Ne peut pas supprimer un arc de Sommet non existants    *****
		************************************************************************************************/
		void GRASupprimerArc(unsigned int uiIdSommet, unsigned int uiIdDestination);

		/************************************************************************************************
		***** GRAINVERSERGRAPHE : Fonction permettant d'inverser les arcs du graphe *********************
		*************************************************************************************************
		***** Entr�e :																				*****
		***** N�cessite :                                                                           *****
		***** Sortie :                                                                              *****
		***** Entraine : Elle supprime un arc entre les deux Sommet choisis                         *****
		************************************************************************************************/
		CGraphe& GRAInverserGraphe();

};

#endif