#include "phoneBook.hpp"

int main()
{
	PhoneBook	myBook;
	std::string	command;	

	std::cout << GREEN << "Welcome to your phone book program :)..."<< std::endl;
	std::cout << "You can use 3 commands: ADD, SEARCH, and EXIT..." << std::endl;
	std::cout << "when you're finished, type 'EXIT' to close..." << RESET << std::endl;
	
	while (command.compare("EXIT") != 0)
	{
		std::cout << "What's in your mind?... ";
		std::getline(std::cin, command);
		if (command.empty())
			continue ;
		if (command.compare("ADD") == 0)
		{
			Contact newContact;
				newContact.setContact();
			myBook.addContact(newContact);
		}
		if (command.compare("SEARCH") == 0)
		{
			int entries = myBook.countEntries();
			if (entries == -1)
			{
				std::cout<< RED << "Phone Book is Empty, add books to review them..." << RESET << std::endl;
			}
			else
			{
				myBook.display();
				myBook.displayEntry(entries);
			}		
		}
	}
}