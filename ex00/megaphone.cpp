/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaraguler <dilaraguler@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 16:21:46 by diguler           #+#    #+#             */
/*   Updated: 2024/12/31 21:01:36 by dilaraguler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < ac; i++)
    {
        for (int j = 0; av[i][j]; j++)
            std::cout << (char)toupper(av[i][j]);
        if (ac > 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
