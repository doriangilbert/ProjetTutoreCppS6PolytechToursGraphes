#include "CLecteur.h"

/*********************************************************
***** CLECTEUR : Constructeur par défaut de CLecteur *****
**********************************************************
***** Entrée :                                       *****
***** Nécessite :                                    *****
***** Sortie :                                       *****
***** Entraine : Le contructeur a initialisé un      *****
***** objet CLecteur avec pcLECNomFichier égal       *****
***** à NULL                                         *****
*********************************************************/
CLecteur::CLecteur()
{
	pcLECNomFichier = NULL;
}

/*********************************************************
***** CLECTEUR : Constructeur de recopie de CLecteur *****
**********************************************************
***** Entrée : LECParam, un objet de type CLecteur   *****
***** Nécessite :                                    *****
***** Sortie :                                       *****
***** Entraine : Le contructeur a initialisé un      *****
***** objet CMatrice<MTYPE> correspondant à une      *****
***** copie de l'objet LECParam                      *****
*********************************************************/
CLecteur::CLecteur(CLecteur &LECParam)
{
	strcpy(pcLECNomFichier, LECParam.LECLireNomFichier());
}

/*********************************************************
***** CLECTEUR : Constructeur de confort de CLecteur *****
**********************************************************
***** Entrée : pcNomFichier, chaine de caractères,   *****
***** nom du fichier à lire                          *****
***** Nécessite :                                    *****
***** Sortie :                                       *****
***** Entraine : Le contructeur a initialisé un      *****
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
***** Entrée :                            *****
***** Nécessite :                         *****
***** Sortie :                            *****
***** Entraine : Le destructeur a         *****
***** désalloué les pointeurs             *****
**********************************************/
CLecteur::~CLecteur()
{
	pcLECNomFichier = NULL;
}

/*****************************************************************************
***** LECLIRENOMFICHIER : Accesseur direct en lecture de pcLECNomFichier *****
******************************************************************************
***** Entrée :                                                           *****
***** Nécessite :                                                        *****
***** Sortie : chaine de caractères, valeur de l'attribut                *****
***** pcLECNomFichier                                                    *****
***** Entraine : LECLireNomFichier() = pcLECNomFichier                   *****
*****************************************************************************/
char* CLecteur::LECLireNomFichier()
{
	return pcLECNomFichier;
}

/**********************************************************************************
***** LECMODIFIERNOMFICHIER : Accesseur direct en écriture de pcLECNomFichier *****
***********************************************************************************
***** Entrée : pcNomFichier, chaine de caractères, nouvelle valeur de         *****
***** pcLECNomFichier                                                         *****
***** Nécessite :                                                             *****
***** Sortie :                                                                *****
***** Entraine : pcLECNomFichier = pcNomFichier                               *****
**********************************************************************************/
void CLecteur::LECModifierNomFichier(char* pcNomFichier)
{
	pcLECNomFichier = new char[strlen(pcNomFichier)];
	strcpy(pcLECNomFichier, pcNomFichier);
}

/******************************************************************************************
***** OPERATOR= : Surcharge de l'opérateur = de CLecteur prenant un CLecteur à droite *****
*******************************************************************************************
***** Entrée : LECParam, un objet de type CLecteur                                    *****
***** Nécessite :                                                                     *****
***** Sortie : objet CLecteur, retourné par référence                                 *****
***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant à une copie  *****
***** de l'objet LECParam                                                             *****
******************************************************************************************/
CLecteur& CLecteur::operator=(CLecteur& LECParam)
{
	strcpy(pcLECNomFichier, LECParam.LECLireNomFichier());
	return *this;
}

/**********************************************************************************************
***** LECLIREFICHIERGRAPHE : Fonction permettant de créer un graphe à partir d'un fichier *****
***********************************************************************************************
***** Entrée :                                                                            *****
***** Nécessite : - pcLECNomFichier contient un nom de fichier                            *****
***** - Le format du fichier est valide                                                   *****
***** Sortie : objet CGraphe, retourné par référence                                      *****
***** Entraine : Un objet CGraphe à été initialisé correspondant au contenu du            *****
***** fichier OU                                                                          *****
***** Exception NomFichierManquant : Nom de fichier manquant OU                           *****
***** Exception EchecOuvertureFichier : Echec d'ouverture de fichier OU                   *****
***** Exception FormatFichierInvalide : Format de fichier invalide                        *****
**********************************************************************************************/
CGraphe& CLecteur::LECLireFichierGraphe() 
{

}