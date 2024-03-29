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
	pcLECNomFichier = nullptr;
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
	pcLECNomFichier = nullptr;
	delete[] pcLECNomFichier;
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

/******************************************************************************************************
***** LECLIREFICHIERGRAPHE : Fonction permettant de cr�er un graphe orient� � partir d'un fichier *****
*******************************************************************************************************
***** Entr�e :                                                                                    *****
***** N�cessite : - pcLECNomFichier contient un nom de fichier                                    *****
***** - Le format du fichier est valide                                                           *****
***** Sortie : objet CGraphe, retourn� par r�f�rence                                              *****
***** Entraine : Un objet CGraphe (orient�) � �t� initialis� correspondant au contenu du          *****
***** fichier OU                                                                                  *****
***** Exception NomFichierManquant : Nom de fichier manquant OU                                   *****
***** Exception EchecOuvertureFichier : Echec d'ouverture de fichier OU                           *****
***** Exception FormatFichierInvalide : Format de fichier invalide                                *****
******************************************************************************************************/
CGraphe& CLecteur::LECLireFichierGraphe() 
{
	//On v�rifie la pr�sence d'un nom de fichier
	if (!pcLECNomFichier)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(NomFichierManquant);
		throw EXCErreur;
	}
	//Ouverture du fichier en mode lecture seule, erreur si l'ouverture �choue
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
	//V�rification de la pr�sence de NBSommets=
	if (strncmp(pcLigne, "NBSommets=", 10) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	else
	{
		//R�cup�ration de la valeur de NBSommets
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
	//V�rification de la pr�sence de NBArcs=
	if (strncmp(pcLigne, "NBArcs=", 7) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	else
	{
		//R�cup�ration de la valeur de NBArcs
		sscanf(pcLigne, "NBArcs=%d", &iNBArcs);
		if (iNBArcs < 0)
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		else 
		{
			uiNBArcs = iNBArcs;
		}
	}
	
	//Cr�er le graphe (orient�)
	CGraphe* GRAGraphe = new CGraphe(true);

	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	//V�rification de la pr�sence de Sommets=[
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
		//V�rification de la pr�sence de ]
		if (strncmp(pcLigne, "]", 1) == 0)
		{
			//ERREUR : Pas assez de lignes par rapport au NBSommets indiqu�
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}

		int iNumero = 0;
		unsigned int uiNumero = 0;
		//V�rification de la pr�sence de Numero=
		if (strncmp(pcLigne, "Numero=", 7) != 0)
		{
			CException EXCErreur;
			EXCErreur.EXCModifierValeur(FormatFichierInvalide);
			throw EXCErreur;
		}
		else
		{
			//R�cup�ration de la valeur de Numero
			sscanf(pcLigne, "Numero=%d", &iNumero);
			if (iNumero < 0)
			{
				CException EXCErreur;
				EXCErreur.EXCModifierValeur(FormatFichierInvalide);
				throw EXCErreur;
			}
			else 
			{
				uiNumero = iNumero;
			}
		}

		//Cr�er le sommet avec uiNumero
		GRAGraphe->GRAAjouterSommet(uiNumero);

	}

	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	//V�rification de la pr�sence de ]
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
	//V�rification de la pr�sence de Arcs=[
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
		//V�rification de la pr�sence de ]
		if (strncmp(pcLigne, "]", 1) == 0)
		{
			//ERREUR : Pas assez de lignes par rapport au NBSommets indiqu�
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
			//V�rification de la pr�sence de Debut=
			if (strncmp(pcParcoursChaine, "Debut=", 6) != 0)
			{
				CException EXCErreur;
				EXCErreur.EXCModifierValeur(FormatFichierInvalide);
				throw EXCErreur;
			}
			else
			{
				//R�cup�ration de la valeur de Debut
				sscanf(pcParcoursChaine, "Debut=%d", &iNumeroSommetDepart);
				if (iNumeroSommetDepart < 0)
				{
					CException EXCErreur;
					EXCErreur.EXCModifierValeur(FormatFichierInvalide);
					throw EXCErreur;
				}
				else 
				{
					uiNumeroSommetDepart = iNumeroSommetDepart;
				}
			}

			//On ignore la virgule et les espaces avant et apr�s celle-ci
			if (strchr(pcParcoursChaine, ','))
			{
				pcParcoursChaine = strchr(pcParcoursChaine, ',');
				pcParcoursChaine++;
				while (strchr(pcParcoursChaine, ' ')) 
				{
					pcParcoursChaine = strchr(pcParcoursChaine, ' ');
					pcParcoursChaine++;
				}
			}
			else
			{
				//On va directement � la fin de la chaine si pas d'�l�ment suivant
				pcParcoursChaine = strchr(pcParcoursChaine, '\n');
			}

			//V�rification de la pr�sence de Fin=
			if (strncmp(pcParcoursChaine, "Fin=", 4) != 0)
			{
				CException EXCErreur;
				EXCErreur.EXCModifierValeur(FormatFichierInvalide);
				throw EXCErreur;
			}
			else
			{
				//R�cup�ration de la valeur de Fin
				sscanf(pcParcoursChaine, "Fin=%d", &iNumeroSommetArrivee);
				if (iNumeroSommetArrivee < 0)
				{
					CException EXCErreur;
					EXCErreur.EXCModifierValeur(FormatFichierInvalide);
					throw EXCErreur;
				}
				else 
				{
					uiNumeroSommetArrivee = iNumeroSommetArrivee;
				}
			}

			//On ignore les espaces de fin de chaine
			if (strchr(pcParcoursChaine, ' '))
			{
				pcParcoursChaine = strchr(pcParcoursChaine, ' ');
				pcParcoursChaine++;
			}
			else
			{
				pcParcoursChaine = strchr(pcParcoursChaine, '\n');
			}
			
			//Ajouter Arc
			GRAGraphe->GRAAjouterArc(uiNumeroSommetDepart, uiNumeroSommetArrivee);
		}
	}

	//Lecture de la ligne suivante et erreur si la ligne est absente
	if (!fgets(pcLigne, 1024, fichier))
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}
	//V�rification de la pr�sence de ]
	if (strncmp(pcLigne, "]", 1) != 0)
	{
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(FormatFichierInvalide);
		throw EXCErreur;
	}

	//Si le fichier � �t� ouvert, on le ferme
	if (fichier)
	{
		fclose(fichier);
	}
	
	//Retourner le graphe
	return *GRAGraphe;

}