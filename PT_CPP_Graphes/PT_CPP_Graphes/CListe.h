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
		***** CLISTE<MTYPE> : Constructeur par d�faut de CLISTE<MTYPE> *****
		********************************************************************
		***** Entr�e :                                                 *****
		***** N�cessite :                                              *****
		***** Sortie :                                                 *****
		***** Entraine : Le contructeur a initialis� un objet          *****
		***** CLISTE<MTYPE> avec uiLISTaille � 0 et le pointeur        *****
		***** pLISListe aussi � 0 et pMATMatrice � NULL                *****
		*******************************************************************/
		CListe<MTYPE>();
		
		/*******************************************************************
		***** CLISTE<MTYPE> : Constructeur de recopie de CLISTE<MTYPE> *****
		********************************************************************
		***** Entr�e : LisParam,un objet de type CListe<MTYPE>         *****
		***** N�cessite :                                              *****
		***** Sortie :                                                 *****
		***** Entraine : Le contructeur a initialis� un objet          *****
		***** CLISTE<MTYPE> qui est une recopie de la liste pass�      *****
		***** en param�tre OU                                          *****
		***** EXCEPTION ListeVide: On ne recopie pas une liste vide    *****
		*******************************************************************/
		CListe<MTYPE>(CListe<MTYPE>& LISParam);
		
		/*******************************************************************
		***** CLISTE<MTYPE> : Constructeur de confort de CLISTE<MTYPE> *****
		********************************************************************
		***** Entr�e : uiTaille, entier non sign� donnant la taille de *****
		***** la liste                                                 *****
		***** N�cessite :                                              *****
		***** Sortie :                                                 *****
		***** Entraine : Le contructeur a initialis� un objet          *****
		***** CLISTE<MTYPE> avec la taille pass� en param�tre  OU      *****
		***** EXCEPTION ListeVide: On ne cr�e pas une liste vide       *****
		*******************************************************************/
		CListe<MTYPE>(unsigned int uiTaille);
		
		/*****************************************************************************
		***** LISLIRETAILLE : Accesseur en lecture de la taille de CLISTE<MTYPE> *****
		******************************************************************************
		***** Entr�e : uiTaille, entier non sign� donnant la taille de la liste  *****
		***** N�cessite :                                                        *****
		***** Sortie : entier non sign�, taille de la liste                      *****
		***** Entraine : LISLireTaille()=uiLISTaille                             *****
		*****************************************************************************/
		unsigned int LISLireTaille();
		
		/**********************************************************************************
		***** LISLIREELEMENT : Permet d'acceder � l'element en uiPosition de la liste *****
		***********************************************************************************
		***** Entr�e : uiPosition, entier non sign� de la position de l'element       *****
		***** N�cessite :                                                             *****
		***** Sortie : type g�n�rique MTYPE, correspondant � l'element de la position *****
		***** de la liste                                                             *****
		***** Entraine : LISLireElement()=pLISListe[uiPosition] OU                    *****
		***** EXCEPTION DepassementDeTaille: Essaye d'acceder � un element hors de    *****
		***** la liste                                                                *****
		**********************************************************************************/
		MTYPE& LISLireElement(unsigned int uiPosition);
		
		/*****************************************************************************
		***** LISAJOUTERELEMENT : Permet d'ajouter un element en fin de la liste *****
		******************************************************************************
		***** Entr�e : MTYPEParam, type g�n�rique, correspondant � l'element     *****
		***** N�cessite :                                                        *****
		***** Sortie :                                                           *****
		***** Entraine : Reallouer la nouvelle liste avec une taille plus grande *****
		***** de 1 et rajouter l'element � la fin de la liste                    *****
		*****************************************************************************/
		void LISAjouterElement(MTYPE MTYPEParam);
		
		/*****************************************************************************************
		***** LISMODIFIERELEMENT : Permet de modifier un element � la uiPosition de la liste *****
		******************************************************************************************
		***** Entr�e : - uiPosition, entier non sign� correspond � la position de l'element  *****
		***** � modifier                                                                     *****
		***** - MTYPEParam, type g�n�rique, correspondant � l'element qui va remplacer       *****
		***** l'autre                                                                        *****
		***** N�cessite :                                                                    *****
		***** Sortie :                                                                       *****
		***** Entraine : pLISListe[uiPosition]=MTYPE OU	                                     *****
		***** EXCEPTION DepassementDeTaille: Ne peut pas modifier un element hors            *****
		***** de la liste                                                                    *****
		*****************************************************************************************/
		void LISModifierElement(unsigned int uiPosition, MTYPE MTYPEParam);

		/*******************************************************************************************
		***** LISSUPPRIMERELEMENT : Permet de supprimer un element � la uiPosition de la liste *****
		********************************************************************************************
		***** Entr�e : uiPosition, entier non sign� correspond � la position de l'element      *****
		***** � supprimer                                                                      *****
		***** N�cessite :                                                                      *****
		***** Sortie :                                                                         *****
		***** Entraine : La nouvelle liste avec tous les elements de la liste avant            *****
		***** uiPosition non modifi� et autres avec un decalage de 1 OU                        *****
		***** EXCEPTION DepassementDeTaille: Ne peut pas supprimer un element hors de la liste *****
		*******************************************************************************************/
		void LISSupprimerElement(unsigned int uiPosition);
		
		/**************************************************************
		***** LISAFFICHER : Permet d'afficher une liste � l'�cran *****
		***************************************************************
		***** Entr�e :                                            *****
		***** N�cessite :                                         *****
		***** Sortie :                                            *****
		***** Entraine : Affiche dans la console la liste OU      *****
		***** EXCEPTION ListeVide:On n'affiche pas une liste vide *****
		**************************************************************/
		void LISAfficher();
		
		/***********************************************************************************
		***** OPERATOR= : Surcharge de l'op�rateur = prenant un CListe<MTYPE> � droite *****
		************************************************************************************
		***** Entr�e :	LISParam , CListe<MTYPE> � recopier                            *****
		***** N�cessite :                                                              *****
		***** Sortie : CListe<MTYPE>, recopie de LISParam                              *****
		***** Entraine : Recopie la liste LISParam et la renvoie                       *****
		***** EXCEPTION ListeVide: On n'affiche pas une liste vide		               *****
		***********************************************************************************/
		CListe<MTYPE>& operator=(CListe<MTYPE> LISParam);
};

#include "CListe.cpp"

#endif
