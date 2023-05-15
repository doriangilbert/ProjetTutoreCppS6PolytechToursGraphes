#ifndef CGraphe_h
#define CGraphe_h

#include "CListe.h"
#include "CSommet.h"

#define NULL 0;

class CGraphe
{
	private:
		CListe<CSommet> LISGRASommet;
		bool bGRAEstOriente;

	public:

		CGraphe();

		CGraphe(CGraphe &GRAParam);

		CGraphe(bool bEstOriente);

		~CGraphe();

		bool GRALireEstOriente();

		void GRAAjouterSommet(unsigned int uiId);

		void GRASupprimerSommet(unsigned int uiId);

		void GRAAfficher();

		CGraphe& operator=(CGraphe &GRAParam);

};

#endif