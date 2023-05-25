#ifndef CLecteur_h
#define CLecteur_h

#include "CGraphe.h"

#include <cstdio>
#include <cstring>
using namespace std;

#pragma warning(disable : 4996) //Ligne utilis�e pour �viter l'erreur Visual Studio : C4996 This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS

#define NULL 0;

#define NomFichierManquant 21
#define EchecOuvertureFichier 22
#define FormatFichierInvalide 23

class CLecteur
{
	private:
		char* pcLECNomFichier; //Chaine de caract�res, Nom du fichier � lire

	public:
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
		CLecteur();

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
		CLecteur(CLecteur &LECParam);

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
		CLecteur(char* pcNomFichier);

		/**********************************************
		***** ~CLECTEUR : Destructeur de CLecteur *****
		***********************************************
		***** Entr�e :                            *****
		***** N�cessite :                         *****
		***** Sortie :                            *****
		***** Entraine : Le destructeur a         *****
		***** d�sallou� les pointeurs             *****
		**********************************************/
		~CLecteur();

		/*****************************************************************************
		***** LECLIRENOMFICHIER : Accesseur direct en lecture de pcLECNomFichier *****
		******************************************************************************
		***** Entr�e :                                                           *****
		***** N�cessite :                                                        *****
		***** Sortie : chaine de caract�res, valeur de l'attribut                *****
		***** pcLECNomFichier                                                    *****
		***** Entraine : LECLireNomFichier() = pcLECNomFichier                   *****
		*****************************************************************************/
		char* LECLireNomFichier();

		/**********************************************************************************
		***** LECMODIFIERNOMFICHIER : Accesseur direct en �criture de pcLECNomFichier *****
		***********************************************************************************
		***** Entr�e : pcNomFichier, chaine de caract�res, nouvelle valeur de         *****
		***** pcLECNomFichier                                                         *****
		***** N�cessite :                                                             *****
		***** Sortie :                                                                *****
		***** Entraine : pcLECNomFichier = pcNomFichier                               *****
		**********************************************************************************/
		void LECModifierNomFichier(char* pcNomFichier);

		/******************************************************************************************
		***** OPERATOR= : Surcharge de l'op�rateur = de CLecteur prenant un CLecteur � droite *****
		*******************************************************************************************
		***** Entr�e : LECParam, un objet de type CLecteur                                    *****
		***** N�cessite :                                                                     *****
		***** Sortie : objet CLecteur, retourn� par r�f�rence                                 *****
		***** Entraine : Un objet CMatrice<MTYPE> � �t� initialis� correspondant � une copie  *****
		***** de l'objet LECParam                                                             *****
		******************************************************************************************/
		CLecteur& operator=(CLecteur& LECParam);

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
		CGraphe& LECLireFichierGraphe();

};

#endif
