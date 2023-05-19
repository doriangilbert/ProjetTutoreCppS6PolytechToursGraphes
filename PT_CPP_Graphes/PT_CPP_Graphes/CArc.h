#ifndef CArc_h
#define CArc_h

#define NULL 0;

class CArc
{
	private:
		unsigned int uiARCDestination; //Entier non sign�, Identifiant du sommet de destination de l'arc

	public:
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
		CArc();

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
		CArc(unsigned int uiDestination);

		/*******************************************************************************
		***** ARCLIREDESTINATION : Accesseur direct en lecture de uiARCDestination *****
		********************************************************************************
		***** Entr�e :                                                             *****
		***** N�cessite :                                                          *****
		***** Sortie : entier non sign�, valeur de l'attribut uiARCDestination     *****
		***** Entraine : ARCLireDestination() = uiARCDestination                   *****
		*******************************************************************************/
		unsigned int ARCLireDestination();

		/************************************************************************************
		***** ARCMODIFIERDESTINATION : Accesseur direct en �criture de uiARCDestination *****
		*************************************************************************************
		***** Entr�e : uiDestination, entier non sign�, nouvelle valeur de              *****
		***** uiARCDestination                                                          *****
		***** N�cessite :                                                               *****
		***** Sortie :                                                                  *****
		***** Entraine : uiARCDestination = uiDestination                               *****
		************************************************************************************/
		void ARCModifierDestination(unsigned int uiDestination);

};

#endif