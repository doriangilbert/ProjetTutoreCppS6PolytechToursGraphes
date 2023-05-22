#ifndef CListe_h
#define CListe_h

#include "CException.h"

#include <iostream>
using namespace std;

#define ListeVide 1
#define DepassementdeTaille 2

template<class MTYPE> class CListe
{
	private:
		MTYPE* pLISListe;
		unsigned int uiLISTaille;

	public:
		/*******************************************************************
		***** CLISTE<MTYPE> : Constructeur par défaut de CLISTE<MTYPE> *****
		********************************************************************
		***** Entrée :                                                 *****
		***** Nécessite :                                              *****
		***** Sortie :                                                 *****
		***** Entraine : Le contructeur a initialisé un objet          *****
		***** CLISTE<MTYPE> avec uiLISTaille à 0 et le pointeur        *****
		***** pLISListe aussi à 0 et pMATMatrice à NULL                *****
		*******************************************************************/
		CListe<MTYPE>();
		
		/*******************************************************************
		***** CLISTE<MTYPE> : Constructeur de recopie de CLISTE<MTYPE> *****
		********************************************************************
		***** Entrée : LisParam,un objet de type CListe<MTYPE>         *****
		***** Nécessite :                                              *****
		***** Sortie :                                                 *****
		***** Entraine : Le contructeur a initialisé un objet          *****
		***** CLISTE<MTYPE> qui est une recopie de la liste passé      *****
		***** en paramètre OU                                          *****
		***** EXCEPTION ListeVide: On ne recopie pas une liste vide    *****
		*******************************************************************/
		CListe<MTYPE>(CListe<MTYPE>& LISParam);
		
		/*******************************************************************
		***** CLISTE<MTYPE> : Constructeur de confort de CLISTE<MTYPE> *****
		********************************************************************
		***** Entrée : uiTaille, entier non signé donnant la taille de *****
		***** la liste                                                 *****
		***** Nécessite :                                              *****
		***** Sortie :                                                 *****
		***** Entraine : Le contructeur a initialisé un objet          *****
		***** CLISTE<MTYPE> avec la taille passé en paramètre  OU      *****
		***** EXCEPTION ListeVide: On ne crée pas une liste vide       *****
		*******************************************************************/
		CListe<MTYPE>(unsigned int uiTaille);
		
		/*****************************************************************************
		***** LISLIRETAILLE : Accesseur en lecture de la taille de CLISTE<MTYPE> *****
		******************************************************************************
		***** Entrée : uiTaille, entier non signé donnant la taille de la liste  *****
		***** Nécessite :                                                        *****
		***** Sortie : entier non signé, taille de la liste                      *****
		***** Entraine : LISLireTaille()=uiLISTaille                             *****
		*****************************************************************************/
		unsigned int LISLireTaille();
		
		/**********************************************************************************
		***** LISLIREELEMENT : Permet d'acceder à l'element en uiPosition de la liste *****
		***********************************************************************************
		***** Entrée : uiPosition, entier non signé de la position de l'element       *****
		***** Nécessite :                                                             *****
		***** Sortie : type générique MTYPE, correspondant à l'element de la position *****
		***** de la liste                                                             *****
		***** Entraine : LISLireElement()=pLISListe[uiPosition] OU                    *****
		***** EXCEPTION DepassementDeTaille: Essaye d'acceder à un element hors de    *****
		***** la liste                                                                *****
		**********************************************************************************/
		MTYPE& LISLireElement(unsigned int uiPosition);
		
		/*****************************************************************************
		***** LISAJOUTERELEMENT : Permet d'ajouter un element en fin de la liste *****
		******************************************************************************
		***** Entrée : MTYPEParam, type générique, correspondant à l'element     *****
		***** Nécessite :                                                        *****
		***** Sortie :                                                           *****
		***** Entraine : Reallouer la nouvelle liste avec une taille plus grande *****
		***** de 1 et rajouter l'element à la fin de la liste                    *****
		*****************************************************************************/
		void LISAjouterElement(MTYPE MTYPEParam);
		
		/*****************************************************************************************
		***** LISMODIFIERELEMENT : Permet de modifier un element à la uiPosition de la liste *****
		******************************************************************************************
		***** Entrée : - uiPosition, entier non signé correspond à la position de l'element  *****
		***** à modifier                                                                     *****
		***** - MTYPEParam, type générique, correspondant à l'element qui va remplacer       *****
		***** l'autre                                                                        *****
		***** Nécessite :                                                                    *****
		***** Sortie :                                                                       *****
		***** Entraine : pLISListe[uiPosition]=MTYPE OU	                                     *****
		***** EXCEPTION DepassementDeTaille: Ne peut pas modifier un element hors            *****
		***** de la liste                                                                    *****
		*****************************************************************************************/
		void LISModifierElement(unsigned int uiPosition, MTYPE MTYPEParam);

		/*******************************************************************************************
		***** LISSUPPRIMERELEMENT : Permet de supprimer un element à la uiPosition de la liste *****
		********************************************************************************************
		***** Entrée : uiPosition, entier non signé correspond à la position de l'element      *****
		***** à supprimer                                                                      *****
		***** Nécessite :                                                                      *****
		***** Sortie :                                                                         *****
		***** Entraine : La nouvelle liste avec tous les elements de la liste avant            *****
		***** uiPosition non modifié et autres avec un decalage de 1 OU                        *****
		***** EXCEPTION DepassementDeTaille: Ne peut pas supprimer un element hors de la liste *****
		*******************************************************************************************/
		void LISSupprimerElement(unsigned int uiPosition);
		
		/**************************************************************
		***** LISAFFICHER : Permet d'afficher une liste à l'écran *****
		***************************************************************
		***** Entrée :                                            *****
		***** Nécessite :                                         *****
		***** Sortie :                                            *****
		***** Entraine : Affiche dans la console la liste OU      *****
		***** EXCEPTION ListeVide:On n'affiche pas une liste vide *****
		**************************************************************/
		void LISAfficher();
		
		/***********************************************************************************
		***** OPERATOR= : Surcharge de l'opérateur = prenant un CListe<MTYPE> à droite *****
		************************************************************************************
		***** Entrée :	LISParam , CListe<MTYPE> à recopier                            *****
		***** Nécessite :                                                              *****
		***** Sortie : CListe<MTYPE>, recopie de LISParam                              *****
		***** Entraine : Recopie la liste LISParam et la renvoie                       *****
		***** EXCEPTION ListeVide: On n'affiche pas une liste vide		               *****
		***********************************************************************************/
		CListe<MTYPE>& operator=(CListe<MTYPE> LISParam);
};

#include "CListe.cpp"

#endif
