#ifndef CGraphe_h
#define CGraphe_h

#include "CListe.h"
#include "CSommet.h"

#define NULL 0;

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

		bool GRALireEstOrienté();

		void GRAAjouterSommet(unsigned int uiId);

		void GRASupprimerSommet(unsigned int uiId);

		void GRAAfficher();

		CSommet& operator=(CSommet &SOMParam);

};

#endif