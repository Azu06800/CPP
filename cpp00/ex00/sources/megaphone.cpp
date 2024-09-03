/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:23:20 by nihamdan          #+#    #+#             */
/*   Updated: 2024/08/30 16:54:06 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i = 0;
    int j;
    
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (argv[++i])
        {
            j = -1;
            while(argv[i][++j])
            {
                if (argv[i][j] >= 97 && argv[i][j] <= 122)
                    argv[i][j] -= 32;
            }
            std::cout << argv[i];
        }
    std::cout << std::endl;
    }
    return 0;
}
