#include "CArc.h"

/*************************************************
***** CARC : Constructeur par d�faut de CArc *****
**************************************************
***** Entr�e :                               *****
***** N�cessite :                            *****
***** Sortie :                               *****
***** Entraine : Le contructeur a initialis� *****
***** un objet CLecteur avec                 *****
***** uiARCDestination �gal � NULL           *****
*************************************************/
CArc::CArc()
{
	uiARCDestination = NULL;
}

/*************************************************
***** CARC : Constructeur de confort de CArc *****
**************************************************
***** Entr�e : uiDestination, entier non     *****
***** sign�, identifiant du sommet de        *****
***** destination                            *****
***** N�cessite :                            *****
***** Sortie :                               *****
***** Entraine : Le contructeur a initialis� *****
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
***** Entr�e :                                                             *****
***** N�cessite :                                                          *****
***** Sortie : entier non sign�, valeur de l'attribut uiARCDestination     *****
***** Entraine : ARCLireDestination() = uiARCDestination                   *****
*******************************************************************************/
unsigned int CArc::ARCLireDestination()
{
	return uiARCDestination;
}

/************************************************************************************
***** ARCMODIFIERDESTINATION : Accesseur direct en �criture de uiARCDestination *****
*************************************************************************************
***** Entr�e : uiDestination, entier non sign�, nouvelle valeur de              *****
***** uiARCDestination                                                          *****
***** N�cessite :                                                               *****
***** Sortie :                                                                  *****
***** Entraine : uiARCDestination = uiDestination                               *****
************************************************************************************/
void CArc::ARCModifierDestination(unsigned int uiDestination)
{
	uiARCDestination = uiDestination;
}