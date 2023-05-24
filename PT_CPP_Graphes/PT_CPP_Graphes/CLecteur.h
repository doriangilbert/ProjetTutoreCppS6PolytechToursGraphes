#ifndef CLecteur_h
#define CLecteur_h

#include "CGraphe.h"

#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable : 4996) //Ligne utilisée pour éviter l'erreur Visual Studio : C4996 This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS

#define NULL 0;
/*
Voir pour faire pour les codes erreurs une typologie de type : <id_classe><id_erreur>, ce qui permet d'avoir 10 codes erreurs par classe et si on dépasse il suffit de prendre le prochain <id_classe> disponible, 
cette structure permet une homogénéité des codes et d'améliorer leur lecture, ainsi si on donne le code 5 à CLecteur on aura les codes de 50 à 59, 
si par exemple il faut plus de codes et que les codes 6 et 7 sont deja pris on va donc prendre 8 et on aura les codes 80 à 89 et ainsi de suite.
En gardant l'exemple précédent, le code 55 est donc une erreur de CLecteur et le code 42 d'une autre classe
*/
#define NomFichierManquant 55
#define EchecOuvertureFichier 56
#define FormatFichierInvalide 57

class CLecteur
{
	private:
		char* pcLECNomFichier; //Chaine de caractères, Nom du fichier à lire

	public:
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
		CLecteur();

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
		CLecteur(CLecteur &LECParam);

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
		CLecteur(char* pcNomFichier);

		/**********************************************
		***** ~CLECTEUR : Destructeur de CLecteur *****
		***********************************************
		***** Entrée :                            *****
		***** Nécessite :                         *****
		***** Sortie :                            *****
		***** Entraine : Le destructeur a         *****
		***** désalloué les pointeurs             *****
		**********************************************/
		~CLecteur();

		/*****************************************************************************
		***** LECLIRENOMFICHIER : Accesseur direct en lecture de pcLECNomFichier *****
		******************************************************************************
		***** Entrée :                                                           *****
		***** Nécessite :                                                        *****
		***** Sortie : chaine de caractères, valeur de l'attribut                *****
		***** pcLECNomFichier                                                    *****
		***** Entraine : LECLireNomFichier() = pcLECNomFichier                   *****
		*****************************************************************************/
		char* LECLireNomFichier();

		/**********************************************************************************
		***** LECMODIFIERNOMFICHIER : Accesseur direct en écriture de pcLECNomFichier *****
		***********************************************************************************
		***** Entrée : pcNomFichier, chaine de caractères, nouvelle valeur de         *****
		***** pcLECNomFichier                                                         *****
		***** Nécessite :                                                             *****
		***** Sortie :                                                                *****
		***** Entraine : pcLECNomFichier = pcNomFichier                               *****
		**********************************************************************************/
		void LECModifierNomFichier(char* pcNomFichier);

		/******************************************************************************************
		***** OPERATOR= : Surcharge de l'opérateur = de CLecteur prenant un CLecteur à droite *****
		*******************************************************************************************
		***** Entrée : LECParam, un objet de type CLecteur                                    *****
		***** Nécessite :                                                                     *****
		***** Sortie : objet CLecteur, retourné par référence                                 *****
		***** Entraine : Un objet CMatrice<MTYPE> à été initialisé correspondant à une copie  *****
		***** de l'objet LECParam                                                             *****
		******************************************************************************************/
		CLecteur& operator=(CLecteur& LECParam);

		/******************************************************************************************************
		***** LECLIREFICHIERGRAPHE : Fonction permettant de créer un graphe orienté à partir d'un fichier *****
		*******************************************************************************************************
		***** Entrée :                                                                                    *****
		***** Nécessite : - pcLECNomFichier contient un nom de fichier                                    *****
		***** - Le format du fichier est valide                                                           *****
		***** Sortie : objet CGraphe, retourné par référence                                              *****
		***** Entraine : Un objet CGraphe (orienté) à été initialisé correspondant au contenu du          *****
		***** fichier OU                                                                                  *****
		***** Exception NomFichierManquant : Nom de fichier manquant OU                                   *****
		***** Exception EchecOuvertureFichier : Echec d'ouverture de fichier OU                           *****
		***** Exception FormatFichierInvalide : Format de fichier invalide                                *****
		******************************************************************************************************/
		CGraphe& LECLireFichierGraphe();

};

#endif
