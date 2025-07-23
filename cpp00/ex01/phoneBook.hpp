#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define RESET   "\033[0m"

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkSecret;
	
	public:
		Contact();
		void setContact();
		void getValues();
		bool isEmpty();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
};

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		size;
		int		oldest;

	public:
		PhoneBook();
		void addContact(Contact newOne);
		void display();
		void displayEntry(int entries);
		int countEntries();
};

#endif