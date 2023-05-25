#include <iostream>

#include "CListe.h"
#include "CSommet.h"
#include "CArc.h"
#include "CGraphe.h"
#include "CLecteur.h"

using namespace std;

#define PasDeFichierEnArgument 1
#define TropDArguments 2

int main(int argc, char* argv[])
{
	try 
	{
		if (argc == 1 || argc > 2) 
		{
			if (argc == 1) 
			{
				CException EXCErreur;
				EXCErreur.EXCModifierValeur(PasDeFichierEnArgument);
				throw EXCErreur;
			}
			if (argc > 2) 
			{
				CException EXCErreur;
				EXCErreur.EXCModifierValeur(TropDArguments);
				throw EXCErreur;
			}
		}
		else 
		{
			CLecteur* LECLecteur = new CLecteur(argv[1]);
			CGraphe GRAGraphe = LECLecteur->LECLireFichierGraphe();
			cout << "AFFICHAGE DU GRAPHE" << endl;
			GRAGraphe.GRAAfficher();
			CGraphe GRAGrapheInv = GRAGraphe.GRAInverserGraphe();
			cout << "AFFICHAGE DU GRAPHE INVERSE" << endl;
			GRAGrapheInv.GRAAfficher();
		}
	}
	catch (CException EXCErreur) 
	{
		if (EXCErreur.EXCLireValeur() == PasDeFichierEnArgument) cout << "ERREUR : Pas de nom de fichier specifie en argument\n";
		if (EXCErreur.EXCLireValeur() == TropDArguments) cout << "ERREUR : Trop de fichiers specifies en argument (un fichier maximum)\n";
		if (EXCErreur.EXCLireValeur() == NomFichierManquant) cout << "ERREUR : Nom de fichier manquant\n";
		if (EXCErreur.EXCLireValeur() == EchecOuvertureFichier) cout << "ERREUR : Echec d'ouverture de fichier\n";
		if (EXCErreur.EXCLireValeur() == FormatFichierInvalide) cout << "ERREUR : Format de fichier invalide\n";
		cout << "ERREUR : Code d'erreur : " << EXCErreur.EXCLireValeur() << endl;
	}
}