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
	std::cout << YELLOW << "first name:   " << RESET <<firstName << std::endl;
	std::cout << YELLOW << "last name:    " << RESET << lastName << std::endl;
	std::cout << YELLOW << "nickname:     " << RESET << nickname << std::endl;
	std::cout << YELLOW <<"phone number: " << RESET << phoneNumber << std::endl;
	std::cout << YELLOW <<"dark secret:  " << RESET << darkSecret << std::endl;
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

std::string formatString(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
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
			std::cout<< std::right << std::setw(10) << formatString(contacts[i].getFirstName()) << "|";
			std::cout<< std::right << std::setw(10) << formatString(contacts[i].getLastName()) << "|";
			std::cout<< std::right << std::setw(10)<< formatString(contacts[i].getNickname()) << "|" << RESET << std::endl;
		}
	}
}

int PhoneBook::countEntries()
{
	int len = 0;

	if (contacts[0].isEmpty())
		return (-1);
	for (int i = 0; i < 8; i++)
	{
		if (contacts[i].isEmpty())
			break ;
		len++;
	}
	return (len - 1);
}

void PhoneBook::displayEntry(int entries)
{
	std::string entry;

	entry = "";
	std::cout << "Enter index entry: ";
	std::getline(std::cin, entry);
	while (entry.empty())
	{
		std::cout << "Enter index entry: ";
		std::getline(std::cin, entry);
	}
	while (entry.length() != 1 || atoi(entry.c_str()) > entries || atoi(entry.c_str()) < 0)
	{
		std::cout << RED << "Invalid Input Entry..." << RESET << std::endl;
		std::cout << "Enter index entry: ";
		std::getline(std::cin, entry);
	}
	contacts[atoi(entry.c_str())].getValues();
}