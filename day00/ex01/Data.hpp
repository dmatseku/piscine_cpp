#ifndef DATA_HPP
#define DATA_HPP
#define MAX 8

#include <string>

class Data
{
	public:
		Data(void);
		~Data(void);
		std::string		firstname;
		std::string		lastname;
		std::string		nickname;
		std::string		login;
		std::string		address;
		std::string		email;
		std::string		phone_number;
		std::string		birthday_date;
		std::string		favorite_meal;
		std::string		underwear_color;
		std::string		darkest_secret;
};

#endif