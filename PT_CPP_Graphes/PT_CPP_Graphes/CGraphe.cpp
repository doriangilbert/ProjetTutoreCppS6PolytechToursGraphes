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

}

/*CGraphe& CGraphe::operator=(CGraphe& GRAParam)
{
	CGraphe TODO;
	return TODO;
}*/