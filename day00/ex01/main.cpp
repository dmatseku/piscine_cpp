#include <main.hpp>
#include <Data.hpp>
#include <string>
#include <iostream>

int	main(void)
{
	int			data_count;
	std::string	str;
	Data		data[MAX];

	data_count = 0;
	while (1)
	{
		std::getline(std::cin, str, '\n');
		if (std::cin.eof())
		{
			break;
		}
		else if (str == "ADD")
		{
			if (data_count < MAX)
			{
				data[data_count] = add_data();
				data_count++;
			}
			else
			{
				std::cout << "Book is full!" << std::endl;
			}
		}
		else if (str == "SEARCH")
		{
			if (data_count)
			{
				search(data, data_count);
			}
			else
			{
				std::cout << "Book is empty!" << std::endl;
			}
		}
		else if (str == "EXIT")
		{
			break ;
		}
		if (!std::cin.good())
			std::cin.clear();
	}
}
