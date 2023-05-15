#include "CSommet.h"

CSommet::CSommet()
{

}

CSommet::CSommet(CSommet &SOMParam)
{

}

CSommet::CSommet(unsigned int uiId)
{

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

void CSommet::SOMAjouterArc(unsigned int uiDestination)
{

}

void CSommet::SOMSupprimerArc(unsigned int uiDestination)
{

}

CSommet& CSommet::operator=(CSommet &SOMParam)
{
	
}