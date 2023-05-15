#include <iostream>

using namespace std;
#include "CListe.h"

int main()
{
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


	
}

