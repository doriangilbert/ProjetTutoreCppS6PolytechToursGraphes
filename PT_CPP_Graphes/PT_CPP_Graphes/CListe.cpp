#ifndef CListe_cpp
#define CListe_cpp

#include "CListe.h"

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
template<class MTYPE> CListe<MTYPE>::CListe() 
{
	pLISListe = nullptr;
	uiLISTaille = 0;
}

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
template<class MTYPE> CListe<MTYPE>::CListe(CListe<MTYPE> &LISParam) 
{
	if (LISParam.LISLireTaille() == 0)
	{
		uiLISTaille = 0;
		pLISListe = nullptr;
	}
	else {
		uiLISTaille = LISParam.LISLireTaille();
		pLISListe = new MTYPE[uiLISTaille];
		for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++)
		{
			pLISListe[uiBoucle] = LISParam.LISLireElement(uiBoucle);
		}
	}

}

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
template<class MTYPE> CListe<MTYPE>::CListe(unsigned int uiTaille) 
{
	if (uiTaille == 0) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(ListeVide);
		throw EXCErreur;
	}
	uiLISTaille = uiTaille;
	pLISListe = new MTYPE[uiLISTaille];
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) 
	{
		pLISListe[uiBoucle] = 0;
	}
}

/*******************************************************************
***** ~CLISTE<MTYPE> : Destructeur de CLISTE<MTYPE> ****************
********************************************************************
***** Entr�e :												   *****
***** la liste                                                 *****
***** N�cessite :                                              *****
***** Sortie :                                                 *****
***** Entraine : Le destucteur d�salloue le tableau            *****
*******************************************************************/
template<class MTYPE> CListe<MTYPE>::~CListe()
{
	uiLISTaille = 0;
	delete [] pLISListe;
}

/*****************************************************************************
***** LISLIRETAILLE : Accesseur en lecture de la taille de CLISTE<MTYPE> *****
******************************************************************************
***** Entr�e : uiTaille, entier non sign� donnant la taille de la liste  *****
***** N�cessite :                                                        *****
***** Sortie : entier non sign�, taille de la liste                      *****
***** Entraine : LISLireTaille()=uiLISTaille                             *****
*****************************************************************************/
template<class MTYPE> unsigned int CListe<MTYPE>::LISLireTaille() 
{
	return uiLISTaille;
}

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
template<class MTYPE> MTYPE& CListe<MTYPE>::LISLireElement(unsigned int uiPosition) 
{
	if (uiPosition >= uiLISTaille) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DepassementdeTaille);
		throw EXCErreur;
	}
	return pLISListe[uiPosition];
}

/*****************************************************************************
***** LISAJOUTERELEMENT : Permet d'ajouter un element en fin de la liste *****
******************************************************************************
***** Entr�e : MTYPEParam, type g�n�rique, correspondant � l'element     *****
***** N�cessite :                                                        *****
***** Sortie :                                                           *****
***** Entraine : Reallouer la nouvelle liste avec une taille plus grande *****
***** de 1 et rajouter l'element � la fin de la liste                    *****
*****************************************************************************/
template<class MTYPE> void CListe<MTYPE>::LISAjouterElement(MTYPE MTYPEParam) 
{
	MTYPE* pNouvelleListe = new MTYPE[uiLISTaille+1];
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) 
	{
		pNouvelleListe[uiBoucle] = pLISListe[uiBoucle];
	}
	pNouvelleListe[uiLISTaille] = MTYPEParam;
	pLISListe = pNouvelleListe;
	uiLISTaille = uiLISTaille + 1;
}

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
template<class MTYPE> void CListe<MTYPE>::LISModifierElement(unsigned int uiPosition, MTYPE MTYPEParam) 
{
	if (uiPosition >= uiLISTaille) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DepassementdeTaille);
		throw EXCErreur;
	}
	pLISListe[uiPosition] = MTYPEParam;
}

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
template<class MTYPE> void CListe<MTYPE>::LISSupprimerElement(unsigned int uiPosition) 
{
	if (uiPosition >= uiLISTaille) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DepassementdeTaille);
		throw EXCErreur;
	}
	MTYPE* pNouvelleListe = new MTYPE[uiLISTaille -1];
	for (unsigned int uiBoucle=0; uiBoucle < uiPosition; uiBoucle++) 
	{
		pNouvelleListe[uiBoucle] = pLISListe[uiBoucle];
	}
	if (uiPosition!=uiLISTaille)
	{
		for (unsigned int uiBoucle = uiPosition; uiBoucle < uiLISTaille - 1; uiBoucle++) 
		{
			pNouvelleListe[uiBoucle] = pLISListe[uiBoucle+1];
		}
	}
	pLISListe = pNouvelleListe;
	uiLISTaille = uiLISTaille - 1;
}

/**************************************************************
***** LISAFFICHER : Permet d'afficher une liste � l'�cran *****
***************************************************************
***** Entr�e :                                            *****
***** N�cessite :                                         *****
***** Sortie :                                            *****
***** Entraine : Affiche dans la console la liste OU      *****
***** EXCEPTION ListeVide:On n'affiche pas une liste vide *****
**************************************************************/
template<class MTYPE> void CListe<MTYPE>::LISAfficher() 
{
	if (uiLISTaille == 0) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(ListeVide);
		throw EXCErreur;
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) 
	{
		cout << pLISListe[uiBoucle] << " ";
	}
	cout << "\n";
}

/***********************************************************************************
***** OPERATOR= : Surcharge de l'op�rateur = prenant un CListe<MTYPE> � droite *****
************************************************************************************
***** Entr�e :	LISParam , CListe<MTYPE> � recopier                            *****
***** N�cessite :                                                              *****
***** Sortie : CListe<MTYPE>, recopie de LISParam                              *****
***** Entraine : Recopie la liste LISParam et la renvoie                       *****
***** EXCEPTION ListeVide: On n'affiche pas une liste vide		               *****
***********************************************************************************/
template<class MTYPE> CListe<MTYPE>& CListe<MTYPE>::operator=(CListe<MTYPE> LISParam) 
{
	unsigned int uiTaille = LISParam.LISLireTaille();
	if (uiTaille == 0) 
	{
		uiLISTaille = 0;
		pLISListe = nullptr;
	}
	else {
		uiLISTaille = uiTaille;
		pLISListe = new MTYPE[uiLISTaille];
		for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++)
		{
			pLISListe[uiBoucle] = LISParam.LISLireElement(uiBoucle);
		}
		return *this;
	}

}

#endif