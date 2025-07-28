#include "Harl.hpp"

int main()
{
	Harl d;
	d.complain("DEBUG");
	d.complain("INFO");
	d.complain("WARNING");
	d.complain("ERROR");
	d.complain("not existed");
}