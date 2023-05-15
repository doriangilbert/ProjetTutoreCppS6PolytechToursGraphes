#ifndef CSommet_h
#define CSommet_h

#include "CListe.h"
#include "CArc.h"

#define NULL 0;

class CSommet
{
	private:
		unsigned int uiSOMId;
		CListe<CArc*> LISSOMPartants;
		CListe<CArc*> LISSOMArrivants;

	public:

		CSommet();

		CSommet(CSommet &SOMParam);

		CSommet(unsigned int uiId);

		~CSommet();

		unsigned int SOMLireId();

		void SOMModifierId(unsigned int uiId);

		void SOMAjouterArc(unsigned int uiDestination);

		void SOMSupprimerArc(unsigned int uiDestination);

		CSommet& operator=(CSommet &SOMParam);

};

#endif