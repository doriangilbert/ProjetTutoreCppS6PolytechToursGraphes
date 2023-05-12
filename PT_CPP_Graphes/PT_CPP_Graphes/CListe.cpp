#ifndef CListe_cpp
#define CListe_cpp

#include "CListe.h"

template<class MTYPE> CListe<MTYPE>::CListe() {
	pLISListe = nullptr;
	uiLISTaille=0
}

template<class MTYPE> CListe<MTYPE>::CListe(CListe<MTYPE> &LISParam) {
	if (LISParam.LISLireTaille() == 0) {
		//....
	}
	uiLISTaille = LISParam.LISLireTaille();
	pLISListe = new MTYPE[uiLISTaille];
	for (unsigned int iBoucle=0; iBoucle < uiLISTaille; iBoucle++) {
		pLISListe[i] = LISParam.LISLireElement(iBoucle);
	}
}

template<class MTYPE> CListe<MTYPE>::CListe(unsigned int uiTaille) {
	if (uiTaille == 0) {
		//....
	}
	uiLISTaille = uiTaille;
	pLISListe = new MTYPE[uiLISTaille];
	for (unsigned int iBoucle = 0; iBoucle < uiLISTaille; iBoucle++) {
		pLISListe[iBoucle] = nullptr;
	}
}

template<class MTYPE> unsigned int CListe<MTYPE>::LISLireTaille() {
	return uiLISTaille;
}


template<class MTYPE> void CListe<MTYPE>::LISAjouterElement(MTYPE MTYPEParam) {
	
	pNouvelleListe = new MTYPE[uiLISTaille+1];
	for (unsigned int iBoucle = 0; iBoucle < uiLISTaille; iBoucle++) {
		pNouvelleListe[iBoucle] = pLISListe[iBoucle];
	}
	pNouvelleListe[uiLISTaille] = MTYPEParam;
	uiLISTaille = uiLISTaille + 1;
}


#endif