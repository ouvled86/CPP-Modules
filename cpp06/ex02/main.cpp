#include "Base.hpp"

int main(void)
{

	Base	*holder1 = generate();
	identify(holder1);
	delete (holder1);
	
	holder1 = generate();
	identify(holder1);
	delete (holder1);
	
	holder1 = generate();
	Base	&holder2 = *holder1;
	identify(holder2);
	delete (holder1);
	
	holder1 = generate();
	holder2 = *holder1;
	identify(holder2);
	delete (holder1);

}