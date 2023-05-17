#include "CSommet.h"

using namespace std;

CSommet::CSommet()
{
	uiSOMId = 0;
}

/*CSommet::CSommet(CSommet &SOMParam)
{

}*/

CSommet::CSommet(unsigned int uiId)
{
	uiSOMId = uiId;
}

CSommet::~CSommet()
{

}

unsigned int CSommet::SOMLireId()
{
	return uiSOMId;
}

void CSommet::SOMModifierId(unsigned int uiId)
{
	uiSOMId = uiId;
}

CListe<CArc*> CSommet::SOMLireListePartants() {
	return LISSOMPartants;
}

CListe<CArc*> CSommet::SOMLireListeArrivants() {
	return LISSOMArrivants;
}

void CSommet::SOMAjouterArcPartants(unsigned int uiDestination)
{
	if (LISSOMPartants.LISLireTaille() != 0) {
		bool bEstDejaDansLaListe = false;
		unsigned int uiBoucle = 0;
		while (bEstDejaDansLaListe == false && uiBoucle < LISSOMPartants.LISLireTaille()) {
			bEstDejaDansLaListe = (uiDestination == LISSOMPartants.LISLireElement(uiBoucle)->ARCLireDestination());
			uiBoucle++;
		}
		if (bEstDejaDansLaListe == true) {
			//Exception....
		}
	}
	CArc* ARCParam = new CArc(uiDestination);
	LISSOMPartants.LISAjouterElement(ARCParam);
}

void CSommet::SOMSupprimerArcPartants(unsigned int uiDestination)
{
	if (LISSOMPartants.LISLireTaille() == 0) {
		//Exception...
	}
	bool bEstDansLaListe = false;
	unsigned int uiBoucle = 0;
	while (bEstDansLaListe == false && uiBoucle < LISSOMPartants.LISLireTaille()) {
		bEstDansLaListe = (uiDestination == LISSOMPartants.LISLireElement(uiBoucle)->ARCLireDestination());
		uiBoucle++;
	}
	if (bEstDansLaListe == false) {
		//Exception....
	}
	CArc* pARCArc= LISSOMPartants.LISLireElement(uiBoucle-1);
	LISSOMPartants.LISSupprimerElement(uiBoucle - 1);
	delete pARCArc;
}

void CSommet::SOMAjouterArcArrivants(unsigned int uiDestination)
{
	if (LISSOMArrivants.LISLireTaille() != 0) {
		bool bEstDejaDansLaListe = false;
		unsigned int uiBoucle = 0;
		while ((bEstDejaDansLaListe == false) && (uiBoucle < LISSOMArrivants.LISLireTaille())) {
			bEstDejaDansLaListe = (uiDestination == LISSOMArrivants.LISLireElement(uiBoucle)->ARCLireDestination());
			uiBoucle++;
		}
		if (bEstDejaDansLaListe == true) {
			//Exception....
		}
	}
	CArc* ARCParam = new CArc(uiDestination);
	LISSOMArrivants.LISAjouterElement(ARCParam);
}

void CSommet::SOMSupprimerArcArrivants(unsigned int uiDestination)
{
	if (LISSOMArrivants.LISLireTaille() == 0) {
		//Exception...
	}
	bool bEstDansLaListe = false;
	unsigned int uiBoucle = 0;
	while (bEstDansLaListe == false && uiBoucle < LISSOMArrivants.LISLireTaille()) {
		bEstDansLaListe = (uiDestination == LISSOMArrivants.LISLireElement(uiBoucle)->ARCLireDestination());
		uiBoucle++;
	}
	if (bEstDansLaListe == false) {
		//Exception....
	}
	CArc* pARCArc = LISSOMArrivants.LISLireElement(uiBoucle - 1);
	LISSOMArrivants.LISSupprimerElement(uiBoucle - 1);
	delete pARCArc;
}

void CSommet::SOMAfficher() {
	cout << "uiSOMID = " << uiSOMId << "\n";
	cout << "Liste des destinations arrivantes est \n";
	if (LISSOMArrivants.LISLireTaille() != 0) {
		for (unsigned int uiBoucle = 0; uiBoucle < LISSOMArrivants.LISLireTaille(); uiBoucle++) {
			cout << LISSOMArrivants.LISLireElement(uiBoucle)->ARCLireDestination() << " ";
		}
		cout << "\n";
	}
	cout << "Liste des destinations partantes est \n";
	if (LISSOMPartants.LISLireTaille() != 0) {
		for (unsigned int uiBoucle = 0; uiBoucle < LISSOMPartants.LISLireTaille(); uiBoucle++) {
			cout << LISSOMPartants.LISLireElement(uiBoucle)->ARCLireDestination() << " ";
		}
		cout << "\n";
	}
}

/*CSommet& CSommet::operator=(CSommet &SOMParam)
{
	CSommet TODO;
	return TODO;
}*/