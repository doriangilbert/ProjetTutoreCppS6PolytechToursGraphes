#ifndef CArc_h
#define CArc_h

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