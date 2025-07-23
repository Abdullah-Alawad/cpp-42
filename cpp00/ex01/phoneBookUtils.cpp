#include "phoneBook.hpp"

Contact::Contact()
{
	firstName = "";
	lastName = "";
	nickname = "";
	phoneNumber = "";
	darkSecret = "";
}

void Contact::getValues()
{
	if (!firstName.empty())
		std::cout << firstName << std::endl;
	if (!lastName.empty())
		std::cout << lastName << std::endl;
	if (!nickname.empty())
		std::cout << nickname << std::endl;
	if (!phoneNumber.empty())
		std::cout << phoneNumber << std::endl;
	if (!darkSecret.empty())
		std::cout << darkSecret << std::endl;
}

std::string Contact::getNickname()
{
	return nickname;
}

std::string Contact::getFirstName()
{
	return firstName;
}

std::string Contact::getLastName()
{
	return lastName;
}

bool allDigits(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

void Contact::setContact()
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, this->firstName);
	while (this->firstName.empty())
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, this->firstName);
	}

	std::cout << "Enter last name: ";
	std::getline(std::cin, this->lastName);
	while (this->lastName.empty())
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, this->lastName);
	}

	std::cout << "Enter nickname: ";
	std::getline(std::cin, this->nickname);
	while (this->nickname.empty())
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, this->nickname);
	}

	std::cout << "Enter phone number: ";
	std::getline(std::cin, this->phoneNumber);
	while (this->phoneNumber.empty())
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, this->phoneNumber);
	}
	while (this->phoneNumber.length() != 10 || !allDigits(this->phoneNumber))
	{
		std::cout << RED << "phone number must be only 10 digits" << RESET << std::endl;
		std::cout << "Enter again: "; 
		std::getline(std::cin, this->phoneNumber);
		while (this->phoneNumber.empty())
		{
			std::cout << "Enter phone number: ";
			std::getline(std::cin, this->phoneNumber);
		}
	}

	std::cout << "Enter Dark Secret: ";
	std::getline(std::cin, this->darkSecret);
	while (this->darkSecret.empty())
	{
		std::cout << "Enter Dark Secret: ";
		std::getline(std::cin, this->darkSecret);
	}
}

bool Contact::isEmpty()
{
	return (firstName.empty());
}

void PhoneBook::addContact(Contact newOne)
{
	if (size < 8)
	{
		this->contacts[size] = newOne;
		this->size++;
		if (this->oldest == -1)
			this->oldest = this->size - 1;
	}
	else
	{
		this->contacts[oldest] = newOne;
		if (this->oldest < 7)
			this->oldest++;
		else
			this->oldest = 0;
	}
	
}

PhoneBook::PhoneBook()
{
	size = 0;
	oldest = -1;
}

void PhoneBook::getContacts()
{
	for(int i = 0; i < 8; i++)
	{
		std::cout << "-----------------" << std::endl;
		if (!contacts[i].isEmpty())
			contacts[i].getValues();
		std::cout << "-----------------" << std::endl;
	}
}

std::string formatString(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
		//continjklfdjg;lf
}

void PhoneBook::display()
{
	std::cout<< YELLOW << std::right << std::setw(10) << "|  index|  ";
	std::cout<< std::right << std::setw(10) << "first name|";
	std::cout<< std::right << std::setw(10) << "last name|";
	std::cout<< std::right << std::setw(10) << "nickname|" << RESET << std::endl;
    for (int i = 0; i < 8; i++)
	{
		if (!contacts[i].isEmpty())
		{
			std::cout<< GREEN << std::right  << "|      "<< i << "|";
			std::cout<< std::right << std::setw(10) << contacts[i].getFirstName() << "|";
			std::cout<< std::right << std::setw(10) << contacts[i].getLastName() << "|";
			std::cout<< std::right << std::setw(10)<< contacts[i].getNickname() << "|" << RESET << std::endl;
		}
	}
}