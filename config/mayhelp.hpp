/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mayhelp.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 02:06:49 by sel-fcht          #+#    #+#             */
/*   Updated: 2022/04/18 21:42:50 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAYHELP_HPP
#define MAYHELP_HPP
#include <iostream>
#include <map>
#include <vector>
#include <list>


class Help
{
    public:
        static int	atoi(const char *str)
            {
            	long long	n;
            	int			sign;
            	int			i;
            
            	i = 0;
            	sign = 1;
            	n = 0;
            	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
            		i++;
            	if (str[i] == '+' || str[i] == '-')
            	{
            		if (str[i++] == '-')
            			sign = -1;
            	}
            	while (str[i] >= '0' && str[i] <= '9')
            	{
            		n = n * 10;
            		n = n + str[i] - '0';
            		i++;
            	}
            	if (n < 0 && sign > 0)
            		return (-1);
            	if (n < 0 && sign < 0)
            		return (0);
            	return (n * sign);
            }
        static bool kaynadieze(std::string str)
        {
            if(str[0] == '#')
                return true;
            return false;
        }
        size_t foundvirg(std::string s)
        {
            size_t i = 0;
            while(s[i] != '\0')
            {
                if (s[i] == ';')
                    return i;
                i++;
            }
            return (i);
        }
		size_t postitionequal(std::string s)
		{
			size_t i = 0;
			while(s[i])
			{
				if (s[i] == '=')
					return i;
				i++;
			}
			return (i);
		}    
};


#endif