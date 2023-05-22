#include <iostream>

using namespace std;
#include "CListe.h"
#include "CSommet.h"
#include "CArc.h"


int main()
{
	/*cout << "TEST CLISTE \n";
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
	}*/

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
	LISARC2 = LISARC1;
	LISARC1.LISAfficher();
	LISARC2.LISAfficher();
	
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

	CListe<CSommet> LISSOM1,LISSOM2;
	LISSOM1.LISAjouterElement(SOM1);
	SOM1 = LISSOM1.LISLireElement(0);
	LISSOM2 = LISSOM1;

}

