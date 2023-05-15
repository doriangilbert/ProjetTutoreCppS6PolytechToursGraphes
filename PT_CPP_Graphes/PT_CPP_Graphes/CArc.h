#ifndef CArc_h
#define CArc_h

#define NULL 0;

class CArc
{
	private:
		unsigned int uiARCDestination;

	public:
		CArc();

		CArc(unsigned int uiDestination);

		unsigned int ARCLireDestination();

		void ARCModifierDestination(int uiDestination);

};

#endif