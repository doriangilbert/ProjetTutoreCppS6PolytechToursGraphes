#ifndef CArc_h
#define CArc_h

#define NULL 0;

class CArc
{
	private:
		unsigned int uiARCDestination; //Entier non signé, Identifiant du sommet de destination de l'arc

	public:
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
		CArc();

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
		CArc(unsigned int uiDestination);

		/*******************************************************************************
		***** ARCLIREDESTINATION : Accesseur direct en lecture de uiARCDestination *****
		********************************************************************************
		***** Entrée :                                                             *****
		***** Nécessite :                                                          *****
		***** Sortie : entier non signé, valeur de l'attribut uiARCDestination     *****
		***** Entraine : ARCLireDestination() = uiARCDestination                   *****
		*******************************************************************************/
		unsigned int ARCLireDestination();

		/************************************************************************************
		***** ARCMODIFIERDESTINATION : Accesseur direct en écriture de uiARCDestination *****
		*************************************************************************************
		***** Entrée : uiDestination, entier non signé, nouvelle valeur de              *****
		***** uiARCDestination                                                          *****
		***** Nécessite :                                                               *****
		***** Sortie :                                                                  *****
		***** Entraine : uiARCDestination = uiDestination                               *****
		************************************************************************************/
		void ARCModifierDestination(unsigned int uiDestination);

};

#endif