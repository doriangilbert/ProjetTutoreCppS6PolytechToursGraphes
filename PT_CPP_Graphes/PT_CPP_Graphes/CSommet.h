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

		//CSommet(CSommet &SOMParam);

		CSommet(unsigned int uiId);

		~CSommet();

		unsigned int SOMLireId();

		void SOMModifierId(unsigned int uiId);

		CListe<CArc*> SOMLireListePartants();

		CListe<CArc*> SOMLireListeArrivants();
		
		void SOMAjouterArcPartants(unsigned int uiDestination);

		void SOMSupprimerArcPartants(unsigned int uiDestination);

		void SOMAjouterArcArrivants(unsigned int uiDestination);

		void SOMSupprimerArcArrivants(unsigned int uiDestination);

		void SOMAfficher();

		//CSommet& operator=(CSommet &SOMParam);

};

#endif