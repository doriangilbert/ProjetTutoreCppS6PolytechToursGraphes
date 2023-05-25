#ifndef CSommet_h
#define CSommet_h

#include "CListe.h"
#include "CArc.h"

#define NULL 0

#define EstDejaDansLaListe 3
#define NEstPasDansLaListe 4

class CSommet
{
	private:
		unsigned int uiSOMId; //Entier non signé, Identifiant du sommet
		CListe<CArc*> LISSOMPartants; //Liste des arcs partants du sommet
		CListe<CArc*> LISSOMArrivants; //Liste des arcs arrivants au sommet

	public:
		/*******************************************************
		***** CSOMMET : Constructeur par défaut de CSommet *****
		********************************************************
		***** Entrée :                                     *****
		***** Nécessite :                                  *****
		***** Sortie :                                     *****
		***** Entraine : Le contructeur a initialisé un    *****
		***** objet CSommet avec uiSOMId égal à 0          *****
		*******************************************************/
		CSommet();

		/*******************************************************
		***** CSOMMET : Constructeur de confort de CSommet *****
		********************************************************
		***** Entrée : uiId, entier non signé, identifiant *****
		***** du sommet                                    *****
		***** Nécessite :                                  *****
		***** Sortie :                                     *****
		***** Entraine : Le contructeur a initialisé       *****
		***** un objet CSommet ayant uiSOMId = uiId        *****
		*******************************************************/
		CSommet(unsigned int uiId);

		/**********************************************************
		***** CSOMMET : Constructeur de recopie de CSommet ********
		***********************************************************
		***** Entrée : SOMParam, un objet CSommet			  *****
		***** du sommet                                       *****
		***** Nécessite :                                     *****
		***** Sortie :                                        *****
		***** Entraine : Le contructeur a initialisé          *****
		***** un objet CSommet étant la recopie de SOMParam   *****
		**********************************************************/
		CSommet(CSommet& SOMParam);

		/*************************************************************
		***** SOMLIREID : Accesseur direct en lecture de uiSOMId *****
		**************************************************************
		***** Entrée :                                           *****
		***** Nécessite :                                        *****
		***** Sortie : entier non signé, valeur de l'attribut    *****
		***** uiSOMId                                            *****
		***** Entraine : SOMLireId() = uiSOMId                   *****
		*************************************************************/
		unsigned int SOMLireId();

		/******************************************************************
		***** SOMMODIFIERID : Accesseur direct en écriture de uiSOMId *****
		*******************************************************************
		***** Entrée : uiSOMId, entier non signé, nouvelle valeur de  *****
		***** uiSOMId                                                 *****
		***** Nécessite :                                             *****
		***** Sortie :                                                *****
		***** Entraine : uiSOMId = uiId                               *****
		******************************************************************/
		void SOMModifierId(unsigned int uiId);

		/*******************************************************************************
		***** SOMLIRELISTEPARTANTS : Accesseur direct en lecture de LISSOMPartants *****
		********************************************************************************
		***** Entrée :                                                             *****
		***** Nécessite :                                                          *****
		***** Sortie : Objet de type CListe<CArc*>, valeur de l'attribut           *****
		***** LISSOMPartants                                                       *****
		***** Entraine : SOMLireListePartants() = LISSOMPartants                   *****
		*******************************************************************************/
		CListe<CArc*> SOMLireListePartants();

		/*********************************************************************************
		***** SOMLIRELISTEARRIVANTS : Accesseur direct en lecture de LISSOMArrivants *****
		**********************************************************************************
		***** Entrée :                                                               *****
		***** Nécessite :                                                            *****
		***** Sortie : Objet de type CListe<CArc*>, valeur de l'attribut             *****
		***** LISSOMArrivants                                                        *****
		***** Entraine : SOMLireListeArrivants() = LISSOMArrivants                   *****
		*********************************************************************************/
		CListe<CArc*> SOMLireListeArrivants();
		
		/*****************************************************************************************
		***** SOMAJOUTERARCPARTANTS : Fonction permettant d'ajouter un arc partant au sommet *****
		******************************************************************************************
		***** Entrée : uiDestination, entier non signé, identifiant du sommet de destination *****
		***** de l'arc à ajouter                                                             *****
		***** Nécessite :                                                                    *****
		***** Sortie :                                                                       *****
		***** Entraine : LISSOMPartants contient la liste des sommets partants, additionnée  *****
		***** du sommet à ajouter OU                                                         *****
		***** Exception EstDejaDansLaListe: Ne peut pas rajouter des elements déjà existants *****
		*****************************************************************************************/
		void SOMAjouterArcPartants(unsigned int uiDestination);

		/**********************************************************************************************
		***** SOMSUPPRIMERARCPARTANTS : Fonction permettant de supprimer un arc partant du sommet *****
		***********************************************************************************************
		***** Entrée : uiDestination, entier non signé, identifiant du sommet de destination de   *****
		***** l'arc à supprimer                                                                   *****
		***** Nécessite :                                                                         *****
		***** Sortie :                                                                            *****
		***** Entraine : LISSOMPartants contient la liste des sommets partants, soustraite du     *****
		***** sommet à supprimer OU                                                               *****
		***** Exception NEstPasDansLaListe: Ne peut pas supprimer des élements déjà existants OU  *****
		***** Exception ListeVide: Ne peut pas supprimer un element d'une liste vide              *****
		**********************************************************************************************/
		void SOMSupprimerArcPartants(unsigned int uiDestination);

		/*******************************************************************************************
		***** SOMAJOUTERARCARRIVANTS : Fonction permettant d'ajouter un arc arrivant au sommet *****
		********************************************************************************************
		***** Entrée : uiDestination, entier non signé, identifiant du sommet de destination   *****
		***** de l'arc à ajouter                                                               *****
		***** Nécessite :                                                                      *****
		***** Sortie :                                                                         *****
		***** Entraine : LISSOMArrivants contient la liste des sommets arrivants, additionnée  *****
		***** du sommet à ajouter                                                              *****
		***** Exception EstDejaDansLaListe: Ne peut pas rajouter des elements déjà existants   *****
		*******************************************************************************************/
		void SOMAjouterArcArrivants(unsigned int uiDestination);

		/************************************************************************************************
		***** SOMSUPPRIMERARCARRIVANTS : Fonction permettant de supprimer un arc arrivant du sommet *****
		*************************************************************************************************
		***** Entrée : uiDestination, entier non signé, identifiant du sommet de destination de     *****
		***** l'arc à supprimer                                                                     *****
		***** Nécessite :                                                                           *****
		***** Sortie :                                                                              *****
		***** Entraine : LISSOMArrivants contient la liste des sommets arrivants, soustraite du     *****
		***** sommet à supprimer                                                                    *****
		***** Exception NEstPasDansLaListe: Ne peut pas supprimer des élements déjà existants OU    *****
		***** Exception ListeVide: Ne peut pas supprimer un element d'une liste vide                *****
		************************************************************************************************/
		void SOMSupprimerArcArrivants(unsigned int uiDestination);

		/***************************************************************************
		***** SOMAFFICHER : Fonction permettant d'afficher un sommet à l'écran *****
		****************************************************************************
		***** Entrée :                                                         *****
		***** Nécessite :                                                      *****
		***** Sortie :                                                         *****
		***** Entraine : La fonction à affiché les informations du sommet à    *****
		***** l'écran                                                          *****
		***************************************************************************/
		void SOMAfficher();

		/***************************************************************************
		***** OPERATOR= : Surcharge de l'opérateur =                           *****
		****************************************************************************
		***** Entrée : SOMParam, un objet CSommet                              *****
		***** Nécessite :                                                      *****
		***** Sortie :                                                         *****
		***** Entraine : Il a recopie l'objet SOMParam dans l'objet            *****
		***************************************************************************/
		CSommet operator=(CSommet SOMParam);

		/***************************************************************************
		***** SOMINVERSERLISTESARC :Fonction permettant d'inverser les listes  *****
		****************************************************************************
		***** Entrée :														   *****
		***** Nécessite :                                                      *****
		***** Sortie :                                                         *****
		***** Entraine : Les listes sont inversés                              *****
		***************************************************************************/
		void SOMInverserListesArc();

};

#endif