#include <iostream>

using namespace std;
#include "CListe.h"
#include "CSommet.h"
#include "CArc.h"
#include "CGraphe.h"
#include "CLecteur.h"


int main(int argc, char* argv[])
{
	cout << "TEST CLecteur\n";
	try {
		if (argc == 1 || argc > 2) {
			//Voir pour gérer avec une exception
			cout << "Utilisation de la lecture de fichier impossible : Pas de nom de fichier specifie ou plus de un fichier specifie" << endl;
		}
		else {
			CLecteur* LECLecteur = new CLecteur(argv[1]);
			CGraphe GRAGraphe = LECLecteur->LECLireFichierGraphe();
			GRAGraphe.GRAAfficher();
			CGraphe GRAGrapheInv = GRAGraphe.GRAInverserGraphe();
			GRAGrapheInv.GRAAfficher();
		}
	}
	catch (CException EXCErreur) {
		if (EXCErreur.EXCLireValeur() == NomFichierManquant) cout << "ERREUR : Nom de fichier manquant\n";
		if (EXCErreur.EXCLireValeur() == EchecOuvertureFichier) cout << "ERREUR : Echec d'ouverture de fichier\n";
		if (EXCErreur.EXCLireValeur() == FormatFichierInvalide) cout << "ERREUR : Format de fichier invalide\n";
		cout << "ERREUR : Code d'erreur : " << EXCErreur.EXCLireValeur() << endl;
	}
}

