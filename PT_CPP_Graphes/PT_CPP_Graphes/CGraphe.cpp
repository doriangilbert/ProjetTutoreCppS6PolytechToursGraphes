#include "CGraphe.h"

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
CGraphe::CGraphe()
{
	bGRAEstOriente = true;
}

/*CGraphe::CGraphe(CGraphe& GRAParam)
{

}*/

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
CGraphe::CGraphe(bool bEstOriente)
{
	bGRAEstOriente = bEstOriente;
}


/****************************************************************************
***** GRALIREESTORIENTE : Accesseur direct en lecture de bGRAEstOriente *****
*****************************************************************************
***** Entr�e :                                                          *****
***** N�cessite :                                                       *****
***** Sortie : bool�en, valeur de l'attribut bGRAEstOriente             *****
***** Entraine : GRALireEstOriente() = bGRAEstOriente                   *****
****************************************************************************/
bool CGraphe::GRALireEstOriente()
{
	return bGRAEstOriente;
}

/***************************************************************************
***** GRALIRELISTESOMMET : Accesseur direct en lecture de LISGRASommet *****
****************************************************************************
***** Entr�e :                                                         *****
***** N�cessite :                                                      *****
***** Sortie : Objet de type CListe<CSommet>, valeur de l'attribut     *****
***** LISGRASommet                                                     *****
***** Entraine : GRALireListeSommet() = LISGRASommet                   *****
***************************************************************************/
CListe<CSommet> CGraphe::GRALireListeSommet()
{
	return LISGRASommet;
}

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
void CGraphe::GRAAjouterSommet(unsigned int uiId)
{
	CSommet SOM1=*new CSommet(uiId);
	if (LISGRASommet.LISLireTaille() != 0) {
		//On cherche si le sommet est dans la liste.
		bool bEstDejaDansLaListe = false;
		unsigned int uiBoucle = 0;
		while (bEstDejaDansLaListe == false && uiBoucle < LISGRASommet.LISLireTaille()) {
			bEstDejaDansLaListe = (uiId == LISGRASommet.LISLireElement(uiBoucle).SOMLireId());
			uiBoucle++;
		}
		if (bEstDejaDansLaListe == true) {
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(EstDejaDansLaListe);
			throw EXCErreur;
		}
		LISGRASommet.LISAjouterElement(SOM1);
	}
	else {
		LISGRASommet.LISAjouterElement(SOM1);
	}
}

/************************************************************************************************
***** GRASUPPRIMERSOMMET : Fonction permettant de supprimer un sommet du graphe *****************
*************************************************************************************************
***** Entr�e : uiId, entier non sign�, identifiant du sommet � supprimer                    *****
***** N�cessite :                                                                           *****
***** Sortie :                                                                              *****
***** Entraine : LISGRASommet contient la liste des sommets du graphe,                      *****
***** soustraite du sommet � supprimer OU                                                   *****
***** Exception NEstPasDansLaListe: Ne peut pas supprimer des �lements d�j� existants OU    *****
***** Exception ListeVide: Ne peut pas supprimer un element d'une liste vide                *****
************************************************************************************************/
void CGraphe::GRASupprimerSommet(unsigned int uiId)
{
	if (LISGRASommet.LISLireTaille() == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(ListeVide);
		throw EXCErreur;
	}
	//On cherche si le sommet est dans la liste.
	bool bEstDansLaListe = false;
	unsigned int uiBoucle = 0;
	while (bEstDansLaListe == false && uiBoucle < LISGRASommet.LISLireTaille()) {
		bEstDansLaListe = (uiId == LISGRASommet.LISLireElement(uiBoucle).SOMLireId());
		uiBoucle++;
	}
	if (bEstDansLaListe == false) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(NEstPasDansLaListe);
		throw EXCErreur;
	}
	LISGRASommet.LISSupprimerElement(uiBoucle - 1);
	//On supprime tous les arcs contenant le sommet comme destination.
	if (LISGRASommet.LISLireTaille() != 0) {
		for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
			bool bTrouveDest = false;
			for (unsigned int uiBoucle2 = 0; uiBoucle2 < LISGRASommet.LISLireElement(uiBoucle).SOMLireListeArrivants().LISLireTaille();uiBoucle2++) {
				if (LISGRASommet.LISLireElement(uiBoucle).SOMLireListeArrivants().LISLireElement(uiBoucle2)->ARCLireDestination() == uiId) {
					bTrouveDest = true;
				}
			}
			if (bTrouveDest == true) {
				LISGRASommet.LISLireElement(uiBoucle).SOMSupprimerArcArrivants(uiId);
			}
			bTrouveDest = false;
			for( unsigned int uiBoucle2=0;uiBoucle2 < LISGRASommet.LISLireElement(uiBoucle).SOMLireListePartants().LISLireTaille() ; uiBoucle2++) {
				if (LISGRASommet.LISLireElement(uiBoucle).SOMLireListePartants().LISLireElement(uiBoucle2)->ARCLireDestination() == uiId) {
					bTrouveDest = true;

				}
			}
			if (bTrouveDest == true) {
				LISGRASommet.LISLireElement(uiBoucle).SOMSupprimerArcPartants(uiId);
			}
		}
	}
}

/***************************************************************************
***** GRAAFFICHER : Fonction permettant d'afficher un graphe � l'�cran *****
****************************************************************************
***** Entr�e :                                                         *****
***** N�cessite :                                                      *****
***** Sortie :                                                         *****
***** Entraine : La fonction � affich� les informations du graphe �    *****
***** l'�cran                                                          *****
***************************************************************************/
void CGraphe::GRAAfficher()
{
	if (bGRAEstOriente) {
		cout << "Le graphe est oriente \n";
	}
	else {
		cout << "Le graphe n'est pas oriente \n";
	}
	if (LISGRASommet.LISLireTaille() != 0) {
		for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
			
			LISGRASommet.LISLireElement(uiBoucle).SOMAfficher();
		}
	}
	else {
		cout << "Le Graphe est vide\n";
	}

}

/************************************************************************************************
***** GRAJOUTERARC  : Fonction permettant d'ajouter un arc entre 2 sommet du graphe *************
*************************************************************************************************
***** Entr�e : uiId, entier non sign�, identifiant du sommet partants                       *****
***** uiIdDestination, entier non sign�, identifiant du sommet Arrivants                    *****
***** N�cessite :                                                                           *****
***** Sortie :                                                                              *****
***** Entraine : Elle ajoute un arc entre les deux Sommet choisis OU                        *****
***** Exception NEstPasDansLaListe: Ne peut pas ajouter un arc de Sommet non existants      ***** 
************************************************************************************************/
void CGraphe::GRAAjouterArc(unsigned int uiIdSommet, unsigned int uiIdDestination) {
	unsigned int uiPositionSommet = 0;
	unsigned int uiPositionDestination = 0;
	bool bTrouveSommet = false;
	bool bTrouveDestination = false;
	unsigned int uiBoucle = 0;
	while ((bTrouveSommet == false || bTrouveDestination == false) && uiBoucle < LISGRASommet.LISLireTaille()) {
		if (bTrouveSommet == false) {
			bTrouveSommet = LISGRASommet.LISLireElement(uiBoucle).SOMLireId() == uiIdSommet;
			if (bTrouveSommet == true) {
				uiPositionSommet = uiBoucle;
			}
		}
		if (bTrouveDestination == false) {
			bTrouveDestination = LISGRASommet.LISLireElement(uiBoucle).SOMLireId() == uiIdDestination;
			if (bTrouveDestination == true) {
				uiPositionDestination = uiBoucle;
			}
		}
		uiBoucle++;
	}
	if (bTrouveSommet == false || bTrouveDestination == false) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(NEstPasDansLaListe);
		throw EXCErreur;
	}
	else {
		LISGRASommet.LISLireElement(uiPositionSommet).SOMAjouterArcPartants(uiIdDestination);
		LISGRASommet.LISLireElement(uiPositionDestination).SOMAjouterArcArrivants(uiIdSommet);
		if (!bGRAEstOriente) {
			LISGRASommet.LISLireElement(uiPositionSommet).SOMAjouterArcArrivants(uiIdDestination);
			LISGRASommet.LISLireElement(uiPositionDestination).SOMAjouterArcPartants(uiIdSommet);
		}
	}
}

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
void CGraphe::GRASupprimerArc(unsigned int uiIdSommet, unsigned int uiIdDestination) {
	unsigned int uiPositionSommet = 0;
	unsigned int uiPositionDestination = 0;
	bool bTrouveSommet = false;
	bool bTrouveDestination = false;
	unsigned int uiBoucle = 0;
	while ((bTrouveSommet == false || bTrouveDestination == false) && uiBoucle < LISGRASommet.LISLireTaille()) {
		if (bTrouveSommet == false) {
			bTrouveSommet = LISGRASommet.LISLireElement(uiBoucle).SOMLireId() == uiIdSommet;
			if (bTrouveSommet == true) {
				uiPositionSommet = uiBoucle;
			}
		}
		if (bTrouveDestination == false) {
			bTrouveDestination = LISGRASommet.LISLireElement(uiBoucle).SOMLireId() == uiIdDestination;
			if (bTrouveDestination == true) {
				uiPositionDestination = uiBoucle;
			}
		}
		uiBoucle++;
	}
	if (bTrouveSommet == false || bTrouveDestination == false) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(NEstPasDansLaListe);
		throw EXCErreur;
	}
	else {
		LISGRASommet.LISLireElement(uiPositionSommet).SOMSupprimerArcPartants(uiIdDestination);
		LISGRASommet.LISLireElement(uiPositionDestination).SOMSupprimerArcArrivants(uiIdSommet);
		if (!bGRAEstOriente) {
			LISGRASommet.LISLireElement(uiPositionSommet).SOMSupprimerArcArrivants(uiIdDestination);
			LISGRASommet.LISLireElement(uiPositionDestination).SOMSupprimerArcPartants(uiIdSommet);
		}
	}
}

/************************************************************************************************
***** GRAINVERSERGRAPHE : Fonction permettant d'inverser les arcs du graphe *********************
*************************************************************************************************
***** Entr�e :																				*****
***** N�cessite :                                                                           *****
***** Sortie :                                                                              *****
***** Entraine : Elle supprime un arc entre les deux Sommet choisis                         *****
************************************************************************************************/
void CGraphe::GRAInverserGraphe() {
	for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
		LISGRASommet.LISLireElement(uiBoucle).SOMInverserListesArc();
	}
}
