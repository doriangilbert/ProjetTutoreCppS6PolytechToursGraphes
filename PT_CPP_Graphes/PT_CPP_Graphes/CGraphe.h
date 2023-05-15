#ifndef CGraphe_h
#define CGraphe_h

#include "CListe.h"
#include "CSommet.h"

class CGraphe
{
	private:
		CListe<CSommet> LISGRASommet;

		bool bGRAEstOrienté;

	public:
		CGraphe();

		CGraphe(CGraphe &GRAParam);

		CGraphe(bool bEstOrienté);

		~CGraphe();

		void GRAAjouterSommet(unsigned int uiId);

		void GRASupprimerSommet(unsigned int uiId);

		void GRAAfficher();

		CSommet& operator=(CSommet &SOMParam);

};

#endif