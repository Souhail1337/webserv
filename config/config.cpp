/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:58:18 by sel-fcht          #+#    #+#             */
/*   Updated: 2022/04/18 08:43:41 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mayhelp.hpp"
#include "config.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstddef>
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
            str.erase(0, str.find_first_not_of("\t {}"));
            str.erase(str.find_last_not_of("\t {}") + 1);
            if (Help::kaynadieze(str))
                continue;
            size_t i = str.find_first_of('#');
            str = str.substr(0,i);
           
            str.erase(0, str.find_first_not_of("\t {}"));
            str.erase(str.find_last_not_of("\t {}") + 1);
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
    srv[i].error_page = "../error_pages/index.html";
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

void Config::parse_server(std::string &inputfile)
{
    //std::cout << inputfile << std::endl;
   // std::string str;
    //initialize(2);
    std::string str2;
    std::string str3;
    server serv;
    if(inputfile[0] == '[')
    {
        int len = inputfile.length() - 1; // retrieve the "]"
        if (inputfile[len] != ']')
        {
            std::cout << "makamlash ] dyal lhost" << std::endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            
            std::string name = inputfile.substr(inputfile.find("[") + 1, inputfile.find("]") - 1);
            serv.name = name;
            srv.push_back(serv);
            initialize(shhalmnserver);
            
            std::cout << "smit server " << serv.host << std::endl; 
        }
        shhalmnserver++;
    }
    else
    {
       switch(inputfile[0])
       {
            case 'h':
            {

            }
            case 'p':
            {   
                
            }
            case 'd':
            {   

            }
            case 'b':
            {   
                
            }
            case 'l':
            {
                parse_location();      
            }
        }
        default:
            ...
    }
}
    //std::cout << "CH7AL MN SERVER " << shhalmnserver << std::endl;
  
}
Config::~Config()
{
    ;
}