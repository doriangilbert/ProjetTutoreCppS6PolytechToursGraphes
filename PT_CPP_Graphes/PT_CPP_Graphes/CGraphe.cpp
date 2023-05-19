#include "CGraphe.h"

/*******************************************************
***** CGRAPHE : Constructeur par défaut de CGraphe *****
********************************************************
***** Entrée :                                     *****
***** Nécessite :                                  *****
***** Sortie :                                     *****
***** Entraine : Le contructeur a initialisé un    *****
***** objet CGraphe avec bGRAEstOriente            *****
***** égal à true                                  *****
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
***** Entrée : bEstOriente, booléen, indication du *****
***** type de graphe (orienté ou non)              *****
***** Nécessite :                                  *****
***** Sortie :                                     *****
***** Entraine : Le contructeur a initialisé       *****
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
***** Entrée :                                                          *****
***** Nécessite :                                                       *****
***** Sortie : booléen, valeur de l'attribut bGRAEstOriente             *****
***** Entraine : GRALireEstOriente() = bGRAEstOriente                   *****
****************************************************************************/
bool CGraphe::GRALireEstOriente()
{
	return bGRAEstOriente;
}

/***************************************************************************
***** GRALIRELISTESOMMET : Accesseur direct en lecture de LISGRASommet *****
****************************************************************************
***** Entrée :                                                         *****
***** Nécessite :                                                      *****
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
***** Entrée : uiId, entier non signé, identifiant du sommet à ajouter     *****
***** Nécessite :                                                          *****
***** Sortie :                                                             *****
***** Entraine : LISGRASommet contient la liste des sommets du graphe,     *****
***** additionnée du sommet à ajouter                                      *****
*******************************************************************************/
void CGraphe::GRAAjouterSommet(unsigned int uiId)
{

}

/************************************************************************************
***** GRASUPPRIMERSOMMET : Fonction permettant de supprimer un sommet du graphe *****
*************************************************************************************
***** Entrée : uiId, entier non signé, identifiant du sommet à supprimer        *****
***** Nécessite :                                                               *****
***** Sortie :                                                                  *****
***** Entraine : LISGRASommet contient la liste des sommets du graphe,          *****
***** soustraite du sommet à supprimer                                          *****
************************************************************************************/
void CGraphe::GRASupprimerSommet(unsigned int uiId)
{

}

/***************************************************************************
***** GRAAFFICHER : Fonction permettant d'afficher un graphe à l'écran *****
****************************************************************************
***** Entrée :                                                         *****
***** Nécessite :                                                      *****
***** Sortie :                                                         *****
***** Entraine : La fonction à affiché les informations du graphe à    *****
***** l'écran                                                          *****
***************************************************************************/
void CGraphe::GRAAfficher()
{

}

/*CGraphe& CGraphe::operator=(CGraphe& GRAParam)
{
	CGraphe TODO;
	return TODO;
}*/