#include "Base.hpp"

int 	main(void)
{
	// to do it one at the start
	std::srand(std::time(NULL));

	Base *base = generate();

	identify(base);
	identify(*base);

	delete base;

}