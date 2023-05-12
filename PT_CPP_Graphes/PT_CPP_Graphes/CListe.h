#ifndef CListe_h
#define CListe_h

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
		CListe<MTYPE>& operator=(CListe<MTYPE> MTYPEParam);
};

#include "CListe.cpp"
#endif
