#include <Data.hpp>
#include <main.hpp>
#include <iostream>
#include <string>
#include <iomanip>

void				search_index(Data* data, int count)
{
	int	index;

	std::cout << "Enter the index: ";
	std::cin >> index;
	std::cout << std::endl;
	if (index >= 0 && index < count)
	{
		std::cout << "First name: " << data[index].firstname << std::endl;
		std::cout << "Last name: " << data[index].lastname << std::endl;
		std::cout << "Nickname: " << data[index].nickname << std::endl;
		std::cout << "Login: " << data[index].login << std::endl;
		std::cout << "Address: " << data[index].address << std::endl;
		std::cout << "Email: " << data[index].email << std::endl;
		std::cout << "Phone number: " << data[index].phone_number << std::endl;
		std::cout << "Birthday date: " << data[index].birthday_date << std::endl;
		std::cout << "Favorite meal: " << data[index].favorite_meal << std::endl;
		std::cout << "Underwear color: " << data[index].underwear_color << std::endl;
		std::cout << "Darkest secret: " << data[index].darkest_secret << std::endl;
	}
	else
	{
		std::cout << "Contact not found" << std::endl;
	}
}

std::string			trunc(std::string str)
{
	if (str.length() > FIELD_WIDTH)
	{
		str = str.erase(FIELD_WIDTH - 1, str.length() - (FIELD_WIDTH - 1));
		str.append(".");
	}
	return (str);
}

void				search(Data* data, int count)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;

	std::cout << '|' << std::setw(FIELD_WIDTH) << "Index"
			<< '|' << std::setw(FIELD_WIDTH) << "First name"
			<< '|' << std::setw(FIELD_WIDTH) << "Last name"
			<< '|' << std::setw(FIELD_WIDTH) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < count; i++)
	{
		first_name = trunc(data[i].firstname);
		last_name = trunc(data[i].lastname);
		nickname = trunc(data[i].nickname);

		std::cout << '|' << std::setw(FIELD_WIDTH) << i
			<< '|' << std::setw(FIELD_WIDTH) << first_name
			<< '|' << std::setw(FIELD_WIDTH) << last_name
			<< '|' << std::setw(FIELD_WIDTH) << nickname << "|" << std::endl;
	}
	search_index(data, count);
}
