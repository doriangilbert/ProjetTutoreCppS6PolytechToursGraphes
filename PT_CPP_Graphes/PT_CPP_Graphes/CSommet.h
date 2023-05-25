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
		unsigned int uiSOMId; //Entier non sign�, Identifiant du sommet
		CListe<CArc*> LISSOMPartants; //Liste des arcs partants du sommet
		CListe<CArc*> LISSOMArrivants; //Liste des arcs arrivants au sommet

	public:
		/*******************************************************
		***** CSOMMET : Constructeur par d�faut de CSommet *****
		********************************************************
		***** Entr�e :                                     *****
		***** N�cessite :                                  *****
		***** Sortie :                                     *****
		***** Entraine : Le contructeur a initialis� un    *****
		***** objet CSommet avec uiSOMId �gal � 0          *****
		*******************************************************/
		CSommet();

		/*******************************************************
		***** CSOMMET : Constructeur de confort de CSommet *****
		********************************************************
		***** Entr�e : uiId, entier non sign�, identifiant *****
		***** du sommet                                    *****
		***** N�cessite :                                  *****
		***** Sortie :                                     *****
		***** Entraine : Le contructeur a initialis�       *****
		***** un objet CSommet ayant uiSOMId = uiId        *****
		*******************************************************/
		CSommet(unsigned int uiId);

		/**********************************************************
		***** CSOMMET : Constructeur de recopie de CSommet ********
		***********************************************************
		***** Entr�e : SOMParam, un objet CSommet			  *****
		***** du sommet                                       *****
		***** N�cessite :                                     *****
		***** Sortie :                                        *****
		***** Entraine : Le contructeur a initialis�          *****
		***** un objet CSommet �tant la recopie de SOMParam   *****
		**********************************************************/
		CSommet(CSommet& SOMParam);

		/*************************************************************
		***** SOMLIREID : Accesseur direct en lecture de uiSOMId *****
		**************************************************************
		***** Entr�e :                                           *****
		***** N�cessite :                                        *****
		***** Sortie : entier non sign�, valeur de l'attribut    *****
		***** uiSOMId                                            *****
		***** Entraine : SOMLireId() = uiSOMId                   *****
		*************************************************************/
		unsigned int SOMLireId();

		/******************************************************************
		***** SOMMODIFIERID : Accesseur direct en �criture de uiSOMId *****
		*******************************************************************
		***** Entr�e : uiSOMId, entier non sign�, nouvelle valeur de  *****
		***** uiSOMId                                                 *****
		***** N�cessite :                                             *****
		***** Sortie :                                                *****
		***** Entraine : uiSOMId = uiId                               *****
		******************************************************************/
		void SOMModifierId(unsigned int uiId);

		/*******************************************************************************
		***** SOMLIRELISTEPARTANTS : Accesseur direct en lecture de LISSOMPartants *****
		********************************************************************************
		***** Entr�e :                                                             *****
		***** N�cessite :                                                          *****
		***** Sortie : Objet de type CListe<CArc*>, valeur de l'attribut           *****
		***** LISSOMPartants                                                       *****
		***** Entraine : SOMLireListePartants() = LISSOMPartants                   *****
		*******************************************************************************/
		CListe<CArc*> SOMLireListePartants();

		/*********************************************************************************
		***** SOMLIRELISTEARRIVANTS : Accesseur direct en lecture de LISSOMArrivants *****
		**********************************************************************************
		***** Entr�e :                                                               *****
		***** N�cessite :                                                            *****
		***** Sortie : Objet de type CListe<CArc*>, valeur de l'attribut             *****
		***** LISSOMArrivants                                                        *****
		***** Entraine : SOMLireListeArrivants() = LISSOMArrivants                   *****
		*********************************************************************************/
		CListe<CArc*> SOMLireListeArrivants();
		
		/*****************************************************************************************
		***** SOMAJOUTERARCPARTANTS : Fonction permettant d'ajouter un arc partant au sommet *****
		******************************************************************************************
		***** Entr�e : uiDestination, entier non sign�, identifiant du sommet de destination *****
		***** de l'arc � ajouter                                                             *****
		***** N�cessite :                                                                    *****
		***** Sortie :                                                                       *****
		***** Entraine : LISSOMPartants contient la liste des sommets partants, additionn�e  *****
		***** du sommet � ajouter OU                                                         *****
		***** Exception EstDejaDansLaListe: Ne peut pas rajouter des elements d�j� existants *****
		*****************************************************************************************/
		void SOMAjouterArcPartants(unsigned int uiDestination);

		/**********************************************************************************************
		***** SOMSUPPRIMERARCPARTANTS : Fonction permettant de supprimer un arc partant du sommet *****
		***********************************************************************************************
		***** Entr�e : uiDestination, entier non sign�, identifiant du sommet de destination de   *****
		***** l'arc � supprimer                                                                   *****
		***** N�cessite :                                                                         *****
		***** Sortie :                                                                            *****
		***** Entraine : LISSOMPartants contient la liste des sommets partants, soustraite du     *****
		***** sommet � supprimer OU                                                               *****
		***** Exception NEstPasDansLaListe: Ne peut pas supprimer des �lements d�j� existants OU  *****
		***** Exception ListeVide: Ne peut pas supprimer un element d'une liste vide              *****
		**********************************************************************************************/
		void SOMSupprimerArcPartants(unsigned int uiDestination);

		/*******************************************************************************************
		***** SOMAJOUTERARCARRIVANTS : Fonction permettant d'ajouter un arc arrivant au sommet *****
		********************************************************************************************
		***** Entr�e : uiDestination, entier non sign�, identifiant du sommet de destination   *****
		***** de l'arc � ajouter                                                               *****
		***** N�cessite :                                                                      *****
		***** Sortie :                                                                         *****
		***** Entraine : LISSOMArrivants contient la liste des sommets arrivants, additionn�e  *****
		***** du sommet � ajouter                                                              *****
		***** Exception EstDejaDansLaListe: Ne peut pas rajouter des elements d�j� existants   *****
		*******************************************************************************************/
		void SOMAjouterArcArrivants(unsigned int uiDestination);

		/************************************************************************************************
		***** SOMSUPPRIMERARCARRIVANTS : Fonction permettant de supprimer un arc arrivant du sommet *****
		*************************************************************************************************
		***** Entr�e : uiDestination, entier non sign�, identifiant du sommet de destination de     *****
		***** l'arc � supprimer                                                                     *****
		***** N�cessite :                                                                           *****
		***** Sortie :                                                                              *****
		***** Entraine : LISSOMArrivants contient la liste des sommets arrivants, soustraite du     *****
		***** sommet � supprimer                                                                    *****
		***** Exception NEstPasDansLaListe: Ne peut pas supprimer des �lements d�j� existants OU    *****
		***** Exception ListeVide: Ne peut pas supprimer un element d'une liste vide                *****
		************************************************************************************************/
		void SOMSupprimerArcArrivants(unsigned int uiDestination);

		/***************************************************************************
		***** SOMAFFICHER : Fonction permettant d'afficher un sommet � l'�cran *****
		****************************************************************************
		***** Entr�e :                                                         *****
		***** N�cessite :                                                      *****
		***** Sortie :                                                         *****
		***** Entraine : La fonction � affich� les informations du sommet �    *****
		***** l'�cran                                                          *****
		***************************************************************************/
		void SOMAfficher();

		/***************************************************************************
		***** OPERATOR= : Surcharge de l'op�rateur =                           *****
		****************************************************************************
		***** Entr�e : SOMParam, un objet CSommet                              *****
		***** N�cessite :                                                      *****
		***** Sortie :                                                         *****
		***** Entraine : Il a recopie l'objet SOMParam dans l'objet            *****
		***************************************************************************/
		CSommet operator=(CSommet SOMParam);

		/***************************************************************************
		***** SOMINVERSERLISTESARC :Fonction permettant d'inverser les listes  *****
		****************************************************************************
		***** Entr�e :														   *****
		***** N�cessite :                                                      *****
		***** Sortie :                                                         *****
		***** Entraine : Les listes sont invers�s                              *****
		***************************************************************************/
		void SOMInverserListesArc();

};

#endif