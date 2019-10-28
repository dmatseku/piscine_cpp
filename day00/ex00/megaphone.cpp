/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 15:47:48 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/26 15:47:50 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	to_upper(int ac, char** av)
{
	int	len;
	
	for (int i = 1; i < ac; i++)
	{
		len = std::strlen(av[i]);
		for (int j = 0; j < len; j++)
			av[i][j] = (char)std::toupper(av[i][j]);
		std::cout << av[i];
	}
	std::cout << std::endl;
}

int		main(int ac, char** av)
{
	if (ac > 1)
		to_upper(ac, av);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}