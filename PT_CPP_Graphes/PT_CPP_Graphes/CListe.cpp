#ifndef CListe_cpp
#define CListe_cpp

#include "CListe.h"

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
template<class MTYPE> CListe<MTYPE>::CListe() 
{
	pLISListe = nullptr;
	uiLISTaille = 0;
}

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
***** Entrée : uiTaille, entier non signé donnant la taille de *****
***** la liste                                                 *****
***** Nécessite :                                              *****
***** Sortie :                                                 *****
***** Entraine : Le contructeur a initialisé un objet          *****
***** CLISTE<MTYPE> avec la taille passé en paramètre  OU      *****
***** EXCEPTION ListeVide: On ne crée pas une liste vide       *****
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
***** Entrée :												   *****
***** la liste                                                 *****
***** Nécessite :                                              *****
***** Sortie :                                                 *****
***** Entraine : Le destucteur désalloue le tableau            *****
*******************************************************************/
template<class MTYPE> CListe<MTYPE>::~CListe()
{
	uiLISTaille = 0;
	delete [] pLISListe;
}

/*****************************************************************************
***** LISLIRETAILLE : Accesseur en lecture de la taille de CLISTE<MTYPE> *****
******************************************************************************
***** Entrée : uiTaille, entier non signé donnant la taille de la liste  *****
***** Nécessite :                                                        *****
***** Sortie : entier non signé, taille de la liste                      *****
***** Entraine : LISLireTaille()=uiLISTaille                             *****
*****************************************************************************/
template<class MTYPE> unsigned int CListe<MTYPE>::LISLireTaille() 
{
	return uiLISTaille;
}

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
***** Entrée : MTYPEParam, type générique, correspondant à l'element     *****
***** Nécessite :                                                        *****
***** Sortie :                                                           *****
***** Entraine : Reallouer la nouvelle liste avec une taille plus grande *****
***** de 1 et rajouter l'element à la fin de la liste                    *****
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
***** LISAFFICHER : Permet d'afficher une liste à l'écran *****
***************************************************************
***** Entrée :                                            *****
***** Nécessite :                                         *****
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
***** OPERATOR= : Surcharge de l'opérateur = prenant un CListe<MTYPE> à droite *****
************************************************************************************
***** Entrée :	LISParam , CListe<MTYPE> à recopier                            *****
***** Nécessite :                                                              *****
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