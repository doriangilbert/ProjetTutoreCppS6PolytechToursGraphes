#include "CArc.h"

/*************************************************
***** CARC : Constructeur par défaut de CArc *****
**************************************************
***** Entrée :                               *****
***** Nécessite :                            *****
***** Sortie :                               *****
***** Entraine : Le contructeur a initialisé *****
***** un objet CLecteur avec                 *****
***** uiARCDestination égal à NULL           *****
*************************************************/
CArc::CArc()
{
	uiARCDestination = NULL;
}

/*************************************************
***** CARC : Constructeur de confort de CArc *****
**************************************************
***** Entrée : uiDestination, entier non     *****
***** signé, identifiant du sommet de        *****
***** destination                            *****
***** Nécessite :                            *****
***** Sortie :                               *****
***** Entraine : Le contructeur a initialisé *****
***** un objet CArc ayant                    *****
***** uiARCDestination = uiDestination       *****
*************************************************/
CArc::CArc(unsigned int uiDestination)
{
	uiARCDestination = uiDestination;
}

/*******************************************************************************
***** ARCLIREDESTINATION : Accesseur direct en lecture de uiARCDestination *****
********************************************************************************
***** Entrée :                                                             *****
***** Nécessite :                                                          *****
***** Sortie : entier non signé, valeur de l'attribut uiARCDestination     *****
***** Entraine : ARCLireDestination() = uiARCDestination                   *****
*******************************************************************************/
unsigned int CArc::ARCLireDestination()
{
	return uiARCDestination;
}

/************************************************************************************
***** ARCMODIFIERDESTINATION : Accesseur direct en écriture de uiARCDestination *****
*************************************************************************************
***** Entrée : uiDestination, entier non signé, nouvelle valeur de              *****
***** uiARCDestination                                                          *****
***** Nécessite :                                                               *****
***** Sortie :                                                                  *****
***** Entraine : uiARCDestination = uiDestination                               *****
************************************************************************************/
void CArc::ARCModifierDestination(unsigned int uiDestination)
{
	uiARCDestination = uiDestination;
}