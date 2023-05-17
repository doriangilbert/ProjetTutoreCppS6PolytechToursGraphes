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
	//On vérifie la présence d'un nom de fichier
	if (!pcLECNomFichier)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(NomFichierManquant);
		throw EXCErreur;
	}
	//Ouverture du fichier en mode lecture seule, erreur si l'ouverture échoue
	FILE* fichier = fopen(pcLECNomFichier, "r");
	if (!fichier)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(EchecOuvertureFichier);
		throw EXCErreur;
	}

	char pcLigne[1024] = ""; //Chaine permettant de stocker la ligne courante
	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	int iNBSommets = 0;
	unsigned int uiNBSommets = 0;
	//Vérification de la présence de NBSommets=
	if (strncmp(pcLigne, "NBSommets=", 10) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	else
	{
		//Récupération de la valeur de NBSommets
		sscanf(pcLigne, "NBSommets=%d", &iNBSommets);
		if (iNBSommets < 0)
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		else
		{
			uiNBSommets = iNBSommets;
		}
	}

	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	int iNBArcs = 0;
	unsigned int uiNBArcs = 0;
	//Vérification de la présence de NBArcs=
	if (strncmp(pcLigne, "NBArcs=", 7) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	else
	{
		//Récupération de la valeur de NBArcs
		sscanf(pcLigne, "NBArcs=%d", &iNBArcs);
		if (iNBArcs < 0)
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		else {
			uiNBArcs = iNBArcs;
		}
	}
	
	//TODO : Créer Graphe (orienté)

	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	//Vérification de la présence de Sommets=[
	if (strncmp(pcLigne, "Sommets=[", 9) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}

	//Parcours des lignes pour les sommets
	for (unsigned int uiBoucleSommetsIndiceLigne = 0; uiBoucleSommetsIndiceLigne < uiNBSommets; uiBoucleSommetsIndiceLigne++) 
	{
		//Lecture de la ligne suivante et erreur si la ligne est absente
		if (!fgets(pcLigne, 1024, fichier))
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		//Vérification de la présence de ]
		if (strncmp(pcLigne, "]", 1) == 0)
		{
			//ERREUR : Pas assez de lignes par rapport au NBSommets indiqué
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}

		int iNumero = 0;
		unsigned int uiNumero = 0;
		//Vérification de la présence de Numero=
		if (strncmp(pcLigne, "Numero=", 7) != 0)
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		else
		{
			//Récupération de la valeur de Numero=
			sscanf(pcLigne, "Numero=%d", &iNumero);
			if (iNumero < 0)
			{
				CException EXCErreur;
				EXCErreur.EXCModifierValeur(FormatFichierInvalide);
				throw EXCErreur;
			}
			else {
				uiNumero = iNumero;
			}
		}

		//TODO : Créer Sommet avec uiNumero

	}

	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	//Vérification de la présence de ]
	if (strncmp(pcLigne, "]", 1) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}

	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	//Vérification de la présence de Arcs=[
	if (strncmp(pcLigne, "Arcs=[", 6) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}

	//Parcours des lignes pour les arcs
	for (unsigned int uiBoucleArcsIndiceLigne = 0; uiBoucleArcsIndiceLigne < uiNBArcs; uiBoucleArcsIndiceLigne++)
	{
		//Lecture de la ligne suivante et erreur si la ligne est absente
		if (!fgets(pcLigne, 1024, fichier))
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		//Vérification de la présence de ]
		if (strncmp(pcLigne, "]", 1) == 0)
		{
			//ERREUR : Pas assez de lignes par rapport au NBSommets indiqué
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}

		int iNumeroSommetDepart = 0;
		unsigned int uiNumeroSommetDepart = 0;
		int iNumeroSommetArrivee = 0;
		unsigned int uiNumeroSommetArrivee = 0;
		char* pcParcoursChaine = pcLigne;

		//Parcours de chaque ligne
		while (*pcParcoursChaine != '\n')
		{
			//Vérification de la présence de Debut=
			if (strncmp(pcLigne, "Debut=", 6) != 0)
			{
				CException EXCErreur;
				EXCErreur.EXCModifierValeur(FormatFichierInvalide);
				throw EXCErreur;
			}
			else
			{
				//Récupération de la valeur de Debut=
				sscanf(pcLigne, "Debut=%d", &iNumeroSommetDepart);
				if (iNumeroSommetDepart < 0)
				{
					CException EXCErreur;
					EXCErreur.EXCModifierValeur(FormatFichierInvalide);
					throw EXCErreur;
				}
				else {
					uiNumeroSommetDepart = iNumeroSommetDepart;
				}
			}

			if (strchr(pcParcoursChaine, ', '))
			{
				pcParcoursChaine = strchr(pcParcoursChaine, ', ');
				pcParcoursChaine++;
			}
			else
			{
				//On va directement à la fin de la chaine si pas d'élément suivant
				pcParcoursChaine = strchr(pcParcoursChaine, '\n');
			}

			//Vérification de la présence de Fin=
			if (strncmp(pcLigne, "Fin=", 4) != 0)
			{
				CException EXCErreur;
				EXCErreur.EXCModifierValeur(FormatFichierInvalide);
				throw EXCErreur;
			}
			else
			{
				//Récupération de la valeur de Fin=
				sscanf(pcLigne, "Fin=%d", &iNumeroSommetArrivee);
				if (iNumeroSommetArrivee < 0)
				{
					CException EXCErreur;
					EXCErreur.EXCModifierValeur(FormatFichierInvalide);
					throw EXCErreur;
				}
				else {
					uiNumeroSommetArrivee = iNumeroSommetArrivee;
				}
			}

			if (strchr(pcParcoursChaine, ' '))
			{
				pcParcoursChaine = strchr(pcParcoursChaine, ' ');
				pcParcoursChaine++;
			}
			else
			{
				//On va directement à la fin de la chaine si pas d'élément suivant
				pcParcoursChaine = strchr(pcParcoursChaine, '\n');
			}
			
			//TODO : Ajouter Arc
			
		}
	}

	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	//Vérification de la présence de ]
	if (strncmp(pcLigne, "]", 1) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}

	//Si le fichier à été ouvert, on le ferme
	if (fichier)
	{
		fclose(fichier);
	}
	
	//TODO : Retourner Graphe

}