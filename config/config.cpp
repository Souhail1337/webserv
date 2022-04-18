/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:58:18 by sel-fcht          #+#    #+#             */
/*   Updated: 2022/04/18 03:18:53 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mayhelp.hpp"
#include "config.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
Config::Config()
{
    ;
}
Config::Config(std::string s)
{
   std::ifstream file(s);
   if (file)
   {
       std::stringstream os;
       std::string str;
       os << file.rdbuf();
       str = os.str();
       
       std::stringstream input(str);
       while(std::getline(input, str))
       {
           if (Help::kaynadieze(str))
                continue;
            parse_server(str);
       }
   }
    
}
void Config::initialize(int i)
{
    srv[i].name = "NULL";
    srv[i].host = "NULL";
    srv[i].root = "NULL";
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
    loc->bodySize = -1;
    loc->cgi_path = "NULL";
    loc->extension = "NULL";   
}

void Config::parse_server(std::string inputfile)
{
    std::cout << inputfile << std::endl;
    std::string str;
    std::string str2;
    std::string str3;
    if(inputfile.find(";") != std::string::npos)
    {
        str = inputfile.substr(inputfile.find_first_of(";")+1, inputfile.length() - 1);
       // std::cout << "-> " << str << std::endl;
    }
    
}
Config::~Config()
{
    ;
}