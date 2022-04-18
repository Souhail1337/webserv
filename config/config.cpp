/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:58:18 by sel-fcht          #+#    #+#             */
/*   Updated: 2022/04/18 01:54:11 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.hpp"

void Config::initialize(int i)
{
    srv[i].name = "";
    srv[i].host = NULL;
    srv[i].root = NULL;
    srv[i].port = -1;
    srv[i].bodySize = -1;
    srv[i].error_page = "NULL";
}

void Config::Linit(location *loc)
{
    loc->path = "NULL";
    loc->method = "NULL";
    loc->root = " NULL";
    loc->autoind = false;
    loc->bodySize = "-1";
    loc->cgi_path = "NULL";
    loc->extension = "NULL";   
}
void Config::start_parse(std::string input)
{
    std::ifstream file(input);
    if (file < 0)
        return ("File couldnt open",1);
    else
    {
        
    }
}

