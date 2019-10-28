#include <Data.hpp>
#include <iostream>
#include <string>

Data	add_data(void)
{
	std::string	str;
	Data		res;

	std::cout << "First name: ";
	std::getline(std::cin, str);
	res.firstname = str;

	std::cout << "Last name: ";
	std::getline(std::cin, str);
	res.lastname = str;

	std::cout << "Nickname: ";
	std::getline(std::cin, str);
	res.nickname = str;
	
	std::cout << "Login: ";
	std::getline(std::cin, str);
	res.login = str;
	
	std::cout << "Address: ";
	std::getline(std::cin, str);
	res.address = str;
	
	std::cout << "Email: ";
	std::getline(std::cin, str);
	res.email = str;
	
	std::cout << "Phone number: ";
	std::getline(std::cin, str);
	res.phone_number = str;
	
	std::cout << "Birthday date: ";
	std::getline(std::cin, str);
	res.birthday_date = str;
	
	std::cout << "Favorite meal: ";
	std::getline(std::cin, str);
	res.favorite_meal = str;
	
	std::cout << "Underwear color: ";
	std::getline(std::cin, str);
	res.underwear_color = str;
	
	std::cout << "Darkest secret: ";
	std::getline(std::cin, str);
	res.darkest_secret = str;

	std::cout << "OK!" << std::endl;
	return (res);
}