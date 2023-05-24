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

/*CGraphe::~CGraphe()
{

}*/

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

/*******************************************************************************
***** GRAAJOUTERSOMMET : Fonction permettant d'ajouter un sommet au graphe *****
********************************************************************************
***** Entr�e : uiId, entier non sign�, identifiant du sommet � ajouter     *****
***** N�cessite :                                                          *****
***** Sortie :                                                             *****
***** Entraine : LISGRASommet contient la liste des sommets du graphe,     *****
***** additionn�e du sommet � ajouter                                      *****
*******************************************************************************/
void CGraphe::GRAAjouterSommet(unsigned int uiId)
{
	CSommet SOM1=*new CSommet(uiId);
	if (LISGRASommet.LISLireTaille() != 0) {
		bool bEstDejaDansLaListe = false;
		unsigned int uiBoucle = 0;
		while (bEstDejaDansLaListe == false && uiBoucle < LISGRASommet.LISLireTaille()) {
			bEstDejaDansLaListe = (uiId == LISGRASommet.LISLireElement(uiBoucle).SOMLireId());
			uiBoucle++;
		}
		if (bEstDejaDansLaListe == true) {
			//Exception....
		}
		LISGRASommet.LISAjouterElement(SOM1);
	}
	else {
		LISGRASommet.LISAjouterElement(SOM1);
	}
}

/************************************************************************************
***** GRASUPPRIMERSOMMET : Fonction permettant de supprimer un sommet du graphe *****
*************************************************************************************
***** Entr�e : uiId, entier non sign�, identifiant du sommet � supprimer        *****
***** N�cessite :                                                               *****
***** Sortie :                                                                  *****
***** Entraine : LISGRASommet contient la liste des sommets du graphe,          *****
***** soustraite du sommet � supprimer                                          *****
************************************************************************************/
void CGraphe::GRASupprimerSommet(unsigned int uiId)
{
	if (LISGRASommet.LISLireTaille() == 0) {
		//Exception...
	}
	bool bEstDansLaListe = false;
	unsigned int uiBoucle = 0;
	while (bEstDansLaListe == false && uiBoucle < LISGRASommet.LISLireTaille()) {
		bEstDansLaListe = (uiId == LISGRASommet.LISLireElement(uiBoucle).SOMLireId());
		uiBoucle++;
	}
	if (bEstDansLaListe == false) {
		//Exception....
	}
	LISGRASommet.LISSupprimerElement(uiBoucle - 1);
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
		//Exception....
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
		//Exception....
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

void CGraphe::GRAInverserGraphe() {
	for (unsigned int uiBoucle = 0; uiBoucle < LISGRASommet.LISLireTaille(); uiBoucle++) {
		LISGRASommet.LISLireElement(uiBoucle).SOMInverserListesArc();
	}
}
/*CGraphe& CGraphe::operator=(CGraphe& GRAParam)
{
	CGraphe TODO;
	return TODO;
}*/