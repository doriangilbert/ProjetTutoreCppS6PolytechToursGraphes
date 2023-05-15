#include "CArc.h"

CArc::CArc()
{
	uiARCDestination = NULL;
}

CArc::CArc(unsigned int uiDestination)
{
	uiARCDestination = uiDestination;
}

unsigned int CArc::ARCLireDestination()
{
	return uiARCDestination;
}

void CArc::ARCModifierDestination(int uiDestination)
{
	uiARCDestination = uiDestination;
}