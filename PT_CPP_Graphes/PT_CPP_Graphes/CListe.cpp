#ifndef CListe_cpp
#define CListe_cpp
#include "CListe.h"



template<class MTYPE> CListe<MTYPE>::CListe() {
	pLISListe = nullptr;
	uiLISTaille = 0;
}

template<class MTYPE> CListe<MTYPE>::CListe(CListe<MTYPE> &LISParam) {
	if (LISParam.LISLireTaille() == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(ListeVide);
		throw EXCErreur;
	}
	uiLISTaille = LISParam.LISLireTaille();
	pLISListe = new MTYPE[uiLISTaille];
	for (unsigned int uiBoucle=0; uiBoucle < uiLISTaille; uiBoucle++) {
		pLISListe[uiBoucle] = LISParam.LISLireElement(uiBoucle);
	}
}

template<class MTYPE> CListe<MTYPE>::CListe(unsigned int uiTaille) {
	if (uiTaille == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(ListeVide);
		throw EXCErreur;
	}
	uiLISTaille = uiTaille;
	pLISListe = new MTYPE[uiLISTaille];
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) {
		pLISListe[uiBoucle] = 0;
	}
}

template<class MTYPE> unsigned int CListe<MTYPE>::LISLireTaille() {
	return uiLISTaille;
}

template<class MTYPE> MTYPE CListe<MTYPE>::LISLireElement(unsigned int uiPosition) {
	if (uiPosition >= uiLISTaille) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DepassementdeTaille);
		throw EXCErreur;
	}
	return pLISListe[uiPosition];
}


template<class MTYPE> void CListe<MTYPE>::LISAjouterElement(MTYPE MTYPEParam) {
	
	MTYPE* pNouvelleListe = new MTYPE[uiLISTaille+1];
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) {
		pNouvelleListe[uiBoucle] = pLISListe[uiBoucle];
	}
	pNouvelleListe[uiLISTaille] = MTYPEParam;
	pLISListe = pNouvelleListe;
	uiLISTaille = uiLISTaille + 1;
}

template<class MTYPE> void CListe<MTYPE>::LISModifierElement(unsigned int uiPosition, MTYPE MTYPEParam) {
	if (uiPosition >= uiLISTaille) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DepassementdeTaille);
		throw EXCErreur;
	}
	pLISListe[uiPosition] = MTYPEParam;
}

template<class MTYPE> void CListe<MTYPE>::LISSupprimerElement(unsigned int uiPosition) {
	if (uiPosition >= uiLISTaille) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(DepassementdeTaille);
		throw EXCErreur;
	}
	MTYPE* pNouvelleListe = new MTYPE[uiLISTaille -1];
	for (unsigned int uiBoucle=0; uiBoucle < uiPosition; uiBoucle++) {
		pNouvelleListe[uiBoucle] = pLISListe[uiBoucle];
	}
	if (uiPosition!=uiLISTaille){
		for (unsigned int uiBoucle = uiPosition; uiBoucle < uiLISTaille - 1; uiBoucle++) {
			pNouvelleListe[uiBoucle] = pLISListe[uiBoucle];
		}
	}
	pLISListe = pNouvelleListe;
	uiLISTaille = uiLISTaille - 1;
}

template<class MTYPE> void CListe<MTYPE>::LISAfficher() {
	if (uiLISTaille == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(ListeVide);
		throw EXCErreur;
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) {
		cout << pLISListe[uiBoucle] << " ";
	}
	cout << "\n";
}

template<class MTYPE> CListe<MTYPE>& CListe<MTYPE>::operator=(CListe<MTYPE> LISParam) {
	
	unsigned int uiTaille = LISParam.LISLireTaille();
	if (uiTaille == 0) {
		CException EXCErreur;
		EXCErreur.EXCModifierValeur(ListeVide);
		throw EXCErreur;
	}
	uiLISTaille = uiTaille;
	pLISListe = new MTYPE[uiLISTaille];
	for (unsigned int uiBoucle = 0; uiBoucle < uiLISTaille; uiBoucle++) {
		pLISListe[uiBoucle] = LISParam.LISLireElement(uiBoucle);
	}
	return *this;
}
#endif