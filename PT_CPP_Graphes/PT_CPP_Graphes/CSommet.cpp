#include "CSommet.h"

using namespace std;

/*******************************************************
***** CSOMMET : Constructeur par d�faut de CSommet *****
********************************************************
***** Entr�e :                                     *****
***** N�cessite :                                  *****
***** Sortie :                                     *****
***** Entraine : Le contructeur a initialis� un    *****
***** objet CSommet avec uiSOMId �gal � 0          *****
*******************************************************/
CSommet::CSommet()
{
	uiSOMId = 0;
}

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
CSommet::CSommet(unsigned int uiId)
{
	uiSOMId = uiId;
}

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
CSommet::CSommet(CSommet& SOMParam) {

	uiSOMId = SOMParam.SOMLireId();
	if (SOMParam.SOMLireListeArrivants().LISLireTaille() != 0) 
	{
		for (unsigned int uiBoucle = 0; uiBoucle < SOMParam.SOMLireListeArrivants().LISLireTaille(); uiBoucle++) 
		{
		LISSOMArrivants.LISAjouterElement(new CArc(SOMParam.SOMLireListeArrivants().LISLireElement(uiBoucle)->ARCLireDestination()));
		}
	}
	if (SOMParam.SOMLireListePartants().LISLireTaille() != 0) 
	{
		for (unsigned int uiBoucle = 0; uiBoucle < SOMParam.SOMLireListePartants().LISLireTaille(); uiBoucle++) 
		{
			LISSOMPartants.LISAjouterElement(new CArc(SOMParam.SOMLireListePartants().LISLireElement(uiBoucle)->ARCLireDestination()));
		}
	}
}

/*************************************************************
***** SOMLIREID : Accesseur direct en lecture de uiSOMId *****
**************************************************************
***** Entr�e :                                           *****
***** N�cessite :                                        *****
***** Sortie : entier non sign�, valeur de l'attribut    *****
***** uiSOMId                                            *****
***** Entraine : SOMLireId() = uiSOMId                   *****
*************************************************************/
unsigned int CSommet::SOMLireId()
{
	return uiSOMId;
}

/******************************************************************
***** SOMMODIFIERID : Accesseur direct en �criture de uiSOMId *****
*******************************************************************
***** Entr�e : uiSOMId, entier non sign�, nouvelle valeur de  *****
***** uiSOMId                                                 *****
***** N�cessite :                                             *****
***** Sortie :                                                *****
***** Entraine : uiSOMId = uiId                               *****
******************************************************************/
void CSommet::SOMModifierId(unsigned int uiId)
{
	uiSOMId = uiId;
}

/*******************************************************************************
***** SOMLIRELISTEPARTANTS : Accesseur direct en lecture de LISSOMPartants *****
********************************************************************************
***** Entr�e :                                                             *****
***** N�cessite :                                                          *****
***** Sortie : Objet de type CListe<CArc*>, valeur de l'attribut           *****
***** LISSOMPartants                                                       *****
***** Entraine : SOMLireListePartants() = LISSOMPartants                   *****
*******************************************************************************/
CListe<CArc*> CSommet::SOMLireListePartants() 
{
	return LISSOMPartants;
}

/*********************************************************************************
***** SOMLIRELISTEARRIVANTS : Accesseur direct en lecture de LISSOMArrivants *****
**********************************************************************************
***** Entr�e :                                                               *****
***** N�cessite :                                                            *****
***** Sortie : Objet de type CListe<CArc*>, valeur de l'attribut             *****
***** LISSOMArrivants                                                        *****
***** Entraine : SOMLireListeArrivants() = LISSOMArrivants                   *****
*********************************************************************************/
CListe<CArc*> CSommet::SOMLireListeArrivants() 
{
	return LISSOMArrivants;
}

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
void CSommet::SOMAjouterArcPartants(unsigned int uiDestination)
{
	if (LISSOMPartants.LISLireTaille() != 0) 
	{
		//On cherche si l'arc est dans la liste.
		bool bEstDejaDansLaListe = false;
		unsigned int uiBoucle = 0;
		while (bEstDejaDansLaListe == false && uiBoucle < LISSOMPartants.LISLireTaille()) 
		{
			bEstDejaDansLaListe = (uiDestination == LISSOMPartants.LISLireElement(uiBoucle)->ARCLireDestination());
			uiBoucle++;
		}
		if (bEstDejaDansLaListe == true) 
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(EstDejaDansLaListe);
			throw EXCErreur;
		}
	}
	CArc* ARCParam = new CArc(uiDestination);
	LISSOMPartants.LISAjouterElement(ARCParam);
}

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
void CSommet::SOMSupprimerArcPartants(unsigned int uiDestination)
{
	if (LISSOMPartants.LISLireTaille() == 0) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(ListeVide);
		throw EXCErreur;
	}
	//On cherche si l'arc est dans la liste.
	bool bEstDansLaListe = false;
	unsigned int uiBoucle = 0;
	while (bEstDansLaListe == false && uiBoucle < LISSOMPartants.LISLireTaille()) 
	{
		bEstDansLaListe = (uiDestination == LISSOMPartants.LISLireElement(uiBoucle)->ARCLireDestination());
		uiBoucle++;
	}
	if (bEstDansLaListe == false) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(NEstPasDansLaListe);
		throw EXCErreur;
	}
	CArc* pARCArc= LISSOMPartants.LISLireElement(uiBoucle-1);
	LISSOMPartants.LISSupprimerElement(uiBoucle - 1);
	delete pARCArc;
}

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
void CSommet::SOMAjouterArcArrivants(unsigned int uiDestination)
{
	if (LISSOMArrivants.LISLireTaille() != 0) 
	{
		//On cherche si l'arc est dans la liste.
		bool bEstDejaDansLaListe = false;
		unsigned int uiBoucle = 0;
		while ((bEstDejaDansLaListe == false) && (uiBoucle < LISSOMArrivants.LISLireTaille())) 
		{
			bEstDejaDansLaListe = (uiDestination == LISSOMArrivants.LISLireElement(uiBoucle)->ARCLireDestination());
			uiBoucle++;
		}
		if (bEstDejaDansLaListe == true) 
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(EstDejaDansLaListe);
			throw EXCErreur;
		}
	}
	CArc* ARCParam = new CArc(uiDestination);
	LISSOMArrivants.LISAjouterElement(ARCParam);
}

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
void CSommet::SOMSupprimerArcArrivants(unsigned int uiDestination)
{
	if (LISSOMArrivants.LISLireTaille() == 0) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(ListeVide);
		throw EXCErreur;
	}
	//On cherche si l'arc est dans la liste.
	bool bEstDansLaListe = false;
	unsigned int uiBoucle = 0;
	while (bEstDansLaListe == false && uiBoucle < LISSOMArrivants.LISLireTaille()) 
	{
		bEstDansLaListe = (uiDestination == LISSOMArrivants.LISLireElement(uiBoucle)->ARCLireDestination());
		uiBoucle++;
	}
	if (bEstDansLaListe == false) 
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(NEstPasDansLaListe);
		throw EXCErreur;
	}
	CArc* pARCArc = LISSOMArrivants.LISLireElement(uiBoucle-1);
	LISSOMArrivants.LISSupprimerElement(uiBoucle-1);
	delete pARCArc;
}

/***************************************************************************
***** SOMAFFICHER : Fonction permettant d'afficher un sommet � l'�cran *****
****************************************************************************
***** Entr�e :                                                         *****
***** N�cessite :                                                      *****
***** Sortie :                                                         *****
***** Entraine : La fonction � affich� les informations du sommet �    *****
***** l'�cran                                                          *****
***************************************************************************/
void CSommet::SOMAfficher() {
	cout << "Id du sommet : " << uiSOMId << "\n";
	if (LISSOMArrivants.LISLireTaille() != 0) 
	{
		cout << "Liste des destinations arrivantes est \n";
		for (unsigned int uiBoucle = 0; uiBoucle < LISSOMArrivants.LISLireTaille(); uiBoucle++) 
		{
			cout << LISSOMArrivants.LISLireElement(uiBoucle)->ARCLireDestination() << " ";
		}
		cout << "\n";
	}
	else 
	{
		cout << "Liste des destinations arrivantes est vide\n";
	}
	if (LISSOMPartants.LISLireTaille() != 0) 
	{
		cout << "Liste des destinations partantes est \n";
		for (unsigned int uiBoucle = 0; uiBoucle < LISSOMPartants.LISLireTaille(); uiBoucle++) 
		{
			cout << LISSOMPartants.LISLireElement(uiBoucle)->ARCLireDestination() << " ";
		}
		cout << "\n";
	}
	else 
	{
		cout << "Liste des destinations partantes est vide \n";
	}
}

/***************************************************************************
***** OPERATOR= : Surcharge de l'op�rateur =                           *****
****************************************************************************
***** Entr�e : SOMParam, un objet CSommet                              *****
***** N�cessite :                                                      *****
***** Sortie :                                                         *****
***** Entraine : Il a recopie l'objet SOMParam dans l'objet            *****
***************************************************************************/
CSommet CSommet::operator=(CSommet SOMParam)
{
	uiSOMId = SOMParam.SOMLireId();
	for (unsigned int uiBoucle = 0; uiBoucle<SOMParam.SOMLireListeArrivants().LISLireTaille(); uiBoucle++) 
	{
		LISSOMArrivants.LISAjouterElement(new CArc(SOMParam.SOMLireListeArrivants().LISLireElement(uiBoucle)->ARCLireDestination()));
	}
	for (unsigned int uiBoucle = 0; uiBoucle<SOMParam.SOMLireListePartants().LISLireTaille(); uiBoucle++) 
	{
		LISSOMPartants.LISAjouterElement(new CArc(SOMParam.SOMLireListePartants().LISLireElement(uiBoucle)->ARCLireDestination()));
	}
	return *this;
}

/***************************************************************************
***** SOMINVERSERLISTESARC :Fonction permettant d'inverser les listes  *****
****************************************************************************
***** Entr�e :														   *****
***** N�cessite :                                                      *****
***** Sortie :                                                         *****
***** Entraine : Les listes sont invers�s                              *****
***************************************************************************/
void CSommet::SOMInverserListesArc() 
{
	CListe<CArc*> LISArc = LISSOMArrivants;
	LISSOMArrivants = LISSOMPartants;
	LISSOMPartants = LISArc;
}
