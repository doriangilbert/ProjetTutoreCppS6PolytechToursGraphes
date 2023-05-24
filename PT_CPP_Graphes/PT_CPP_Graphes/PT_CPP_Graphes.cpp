#include <iostream>

using namespace std;
#include "CListe.h"
#include "CSommet.h"
#include "CArc.h"
#include "CGraphe.h"
#include "CLecteur.h"


int main(int argc, char* argv[])
{
	/*
	cout << "TEST CLISTE \n";
	CListe<char*> LIS1(5);
	for (unsigned int uiBoucle = 0; uiBoucle < 5; uiBoucle++) {
		LIS1.LISModifierElement(uiBoucle, (char*)"Salut");
	}
	cout << "TEST CLISTE LireTaille \n";
	cout<<LIS1.LISLireTaille() << endl;
	cout << "TEST CLISTE LireElement \n";
	cout << LIS1.LISLireElement(0) << endl;
	cout << "TEST CLISTE LiSAfficher \n";
	LIS1.LISAfficher();
	cout << "TEST CLISTE AjouterElement \n";
	LIS1.LISAjouterElement((char*)"Bonjour");
	LIS1.LISAfficher();
	cout << "TEST CLISTE SupprimerElement \n";
	LIS1.LISSupprimerElement(5);
	LIS1.LISAfficher();
	cout << "TEST CLISTE ModifierElement \n";
	LIS1.LISModifierElement(4,(char*)"Truc");
	LIS1.LISAfficher();
	CListe<char*> LIS2(LIS1), LIS3;
	cout << "TEST CLISTE Test Constructeur de recopue \n";
	LIS2.LISAfficher();
	cout << "TEST CLISTE Test operateur = \n";
	LIS3 = LIS1;
	LIS3.LISAfficher();
	CListe<double> LIS4,LIS5;
	LIS4.LISAjouterElement(547.6);
	LIS4.LISAfficher();
	try {
		LIS5.LISAfficher();
	}
	catch (CException EXCErreur) {
		cout << EXCErreur.EXCLireValeur() << endl;
	}
	*/

	/*
	cout << "TEST CArc \n";
	CArc ARC1;
	cout << ARC1.ARCLireDestination() <<"\n";
	ARC1.ARCModifierDestination(2);
	cout << ARC1.ARCLireDestination() << "\n";
	CArc ARC2(ARC1), ARC3;
	ARC3 = ARC2;
	cout << ARC2.ARCLireDestination() << "\n";
	cout << ARC3.ARCLireDestination() << "\n";

	CListe<CArc*> LISARC1, LISARC2;
	LISARC1.LISAjouterElement(&ARC1);
	LISARC1.LISAjouterElement(&ARC1);
	LISARC2 = LISARC1;
	LISARC1.LISAfficher();
	LISARC2.LISAfficher();
	*/

	/*
	cout << "TEST CSommet \n";
	CSommet SOM1;
	SOM1.SOMAfficher();
	SOM1.SOMAjouterArcArrivants(2);
	SOM1.SOMAjouterArcArrivants(3);
	SOM1.SOMAjouterArcArrivants(4);
	SOM1.SOMAjouterArcPartants(2);
	SOM1.SOMAjouterArcPartants(3);
	SOM1.SOMAjouterArcPartants(5);
	SOM1.SOMSupprimerArcArrivants(3);
	SOM1.SOMSupprimerArcPartants(3);
	SOM1.SOMAfficher();
	CSommet SOM2(SOM1), SOM3;
	SOM3 = SOM1;
	cout << "recopie \n";
	SOM2.SOMAfficher();
	cout << "= \n";
	SOM3.SOMAfficher();
	*/

	/*
	cout << "TEST CGraphe\n";
	CGraphe GRA1(false);
	GRA1.GRAAfficher();
	GRA1.GRAAjouterSommet(1);
	GRA1.GRAAjouterSommet(2);
	GRA1.GRAAjouterSommet(3);
	GRA1.GRAAjouterArc(1, 2);
	GRA1.GRAAjouterArc(1, 3);
	GRA1.GRAAfficher();
	GRA1.GRASupprimerSommet(3);
	GRA1.GRAAfficher();
	*/

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
		}
	}
	catch (CException EXCErreur) {
		if (EXCErreur.EXCLireValeur() == NomFichierManquant) cout << "ERREUR : Nom de fichier manquant\n";
		if (EXCErreur.EXCLireValeur() == EchecOuvertureFichier) cout << "ERREUR : Echec d'ouverture de fichier\n";
		if (EXCErreur.EXCLireValeur() == FormatFichierInvalide) cout << "ERREUR : Format de fichier invalide\n";
		cout << "ERREUR : Code d'erreur : " << EXCErreur.EXCLireValeur() << endl;
	}
}

