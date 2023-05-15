#ifndef CListe_h
#define CListe_h
#include "CException.h"

using namespace std;
#include <iostream>

#define ListeVide 1
#define DepassementdeTaille 2

template<class MTYPE> class CListe
{
	private :
		MTYPE* pLISListe;
		unsigned int uiLISTaille;
	public:
		CListe<MTYPE>();
		CListe<MTYPE>(CListe<MTYPE> &LISParam);
		CListe<MTYPE>(unsigned int uiTaille);
		unsigned int LISLireTaille();
		MTYPE LISLireElement(unsigned int uiPosition);
		void LISAjouterElement(MTYPE MTYPEParam);
		void LISModifierElement(unsigned int uiPosition, MTYPE MTYPEParam);
		void LISSupprimerElement(unsigned int uiPosition);
		void LISAfficher();
		CListe<MTYPE>& operator=(CListe<MTYPE> LISParam);
};

#include "CListe.cpp"
#endif
