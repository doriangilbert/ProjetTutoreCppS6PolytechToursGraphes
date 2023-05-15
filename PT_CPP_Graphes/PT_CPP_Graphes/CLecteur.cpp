#include "CLecteur.h"

/*********************************************************
***** CLECTEUR : Constructeur par d�faut de CLecteur *****
**********************************************************
***** Entr�e :                                       *****
***** N�cessite :                                    *****
***** Sortie :                                       *****
***** Entraine : Le contructeur a initialis� un      *****
***** objet CLecteur avec pcLECNomFichier �gal       *****
***** � NULL                                         *****
*********************************************************/
CLecteur::CLecteur()
{
	pcLECNomFichier = NULL;
}

/*********************************************************
***** CLECTEUR : Constructeur de recopie de CLecteur *****
**********************************************************
***** Entr�e : LECParam, un objet de type CLecteur   *****
***** N�cessite :                                    *****
***** Sortie :                                       *****
***** Entraine : Le contructeur a initialis� un      *****
***** objet CMatrice<MTYPE> correspondant � une      *****
***** copie de l'objet LECParam                      *****
*********************************************************/
CLecteur::CLecteur(CLecteur &LECParam)
{
	strcpy(pcLECNomFichier, LECParam.LECLireNomFichier());
}

/*********************************************************
***** CLECTEUR : Constructeur de confort de CLecteur *****
**********************************************************
***** Entr�e : pcNomFichier, chaine de caract�res,   *****
***** nom du fichier � lire                          *****
***** N�cessite :                                    *****
***** Sortie :                                       *****
***** Entraine : Le contructeur a initialis� un      *****
***** objet CLecteur ayant                           *****
***** pcLECNomFichier = pcNomFichier                 *****
*********************************************************/
CLecteur::CLecteur(char* pcNomFichier)
{
	pcLECNomFichier = new char[strlen(pcNomFichier)];
	strcpy(pcLECNomFichier, pcNomFichier);
}

/**********************************************
***** ~CLECTEUR : Destructeur de CLecteur *****
***********************************************
***** Entr�e :                            *****
***** N�cessite :                         *****
***** Sortie :                            *****
***** Entraine : Le destructeur a         *****
***** d�sallou� les pointeurs             *****
**********************************************/
CLecteur::~CLecteur()
{
	pcLECNomFichier = NULL;
}

/*****************************************************************************
***** LECLIRENOMFICHIER : Accesseur direct en lecture de pcLECNomFichier *****
******************************************************************************
***** Entr�e :                                                           *****
***** N�cessite :                                                        *****
***** Sortie : chaine de caract�res, valeur de l'attribut                *****
***** pcLECNomFichier                                                    *****
***** Entraine : LECLireNomFichier() = pcLECNomFichier                   *****
*****************************************************************************/
char* CLecteur::LECLireNomFichier()
{
	return pcLECNomFichier;
}

/**********************************************************************************
***** LECMODIFIERNOMFICHIER : Accesseur direct en �criture de pcLECNomFichier *****
***********************************************************************************
***** Entr�e : pcNomFichier, chaine de caract�res, nouvelle valeur de         *****
***** pcLECNomFichier                                                         *****
***** N�cessite :                                                             *****
***** Sortie :                                                                *****
***** Entraine : pcLECNomFichier = pcNomFichier                               *****
**********************************************************************************/
void CLecteur::LECModifierNomFichier(char* pcNomFichier)
{
	pcLECNomFichier = new char[strlen(pcNomFichier)];
	strcpy(pcLECNomFichier, pcNomFichier);
}

/******************************************************************************************
***** OPERATOR= : Surcharge de l'op�rateur = de CLecteur prenant un CLecteur � droite *****
*******************************************************************************************
***** Entr�e : LECParam, un objet de type CLecteur                                    *****
***** N�cessite :                                                                     *****
***** Sortie : objet CLecteur, retourn� par r�f�rence                                 *****
***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant � une copie  *****
***** de l'objet LECParam                                                             *****
******************************************************************************************/
CLecteur& CLecteur::operator=(CLecteur& LECParam)
{
	strcpy(pcLECNomFichier, LECParam.LECLireNomFichier());
	return *this;
}

/**********************************************************************************************
***** LECLIREFICHIERGRAPHE : Fonction permettant de cr�er un graphe � partir d'un fichier *****
***********************************************************************************************
***** Entr�e :                                                                            *****
***** N�cessite : - pcLECNomFichier contient un nom de fichier                            *****
***** - Le format du fichier est valide                                                   *****
***** Sortie : objet CGraphe, retourn� par r�f�rence                                      *****
***** Entraine : Un objet CGraphe � �t� initialis� correspondant au contenu du            *****
***** fichier OU                                                                          *****
***** Exception NomFichierManquant : Nom de fichier manquant OU                           *****
***** Exception EchecOuvertureFichier : Echec d'ouverture de fichier OU                   *****
***** Exception FormatFichierInvalide : Format de fichier invalide                        *****
**********************************************************************************************/
CGraphe& CLecteur::LECLireFichierGraphe() 
{

}