#include "Harl.hpp"

void Harl::debug()
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
			<< "I really do!\n" << std::endl;
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\n"
			<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
			<< std::endl;
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\n"
			<< "I've been coming for years, whereas you started working here just last month.\n"
			<< std::endl;
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::info()
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\n"
			<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n"
			<< std::endl;
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\n"
			<< "I've been coming for years, whereas you started working here just last month.\n"
			<< std::endl;
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\n"
			<< "I've been coming for years, whereas you started working here just last month.\n"
			<< std::endl;
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;

}

void Harl::error()
{
	std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	std::string complains[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int complain = -1;
	for (int i = 0 ; i < 4; i++)
	{
		if (complains[i].compare(level) == 0)
		{
			complain = i;
			break;
		}
	}
	switch (complain)
	{
		case 0:
			debug();
			break;
		case 1:
			info();
			break;
		case 2:
			warning();
			break;
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}