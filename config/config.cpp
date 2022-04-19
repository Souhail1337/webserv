/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:58:18 by sel-fcht          #+#    #+#             */
/*   Updated: 2022/04/19 11:32:42 by sel-fcht         ###   ########.fr       */
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
    shhalmnserver = 0;
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
         //  
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
            
            std::cout << "smit server " << serv.name << std::endl; 
        }
        shhalmnserver++;
    }
    else
    {
       // std::cout << "shhal mn server " << shhalmnserver << std::endl;
       switch(inputfile[0])
       {
            case 'h':
            {
                std::string zb = inputfile.substr(0, inputfile.find_first_of("="));
                if (zb == "host")
                {
                    std::string host = inputfile.substr(inputfile.find("host =") + 7 , inputfile.length() - 7);
                    std::cout << "smit lhpost  " << host << std::endl; 
                    srv[shhalmnserver].host = host;
                }
            }
            case 'p':
            {
                std::string nameof = inputfile.substr(0, inputfile.find_first_of("="));
                if (nameof == "port")
                {    
                    std::string port = inputfile.substr(inputfile.find("port=") + 5, inputfile.length()- 5);
                    srv[shhalmnserver].port = Help::atoi(port.c_str());
                                                                                            //handle ra9m dlport later 
                    std::cout << "smit port :" << port << std::endl;
                }
                // else
                // {
                //     std::cout << "kteb port mzyan" << std::endl;
                //     exit(0);
                // }
            }
            case 'd':
            {   
              //  std::string erorpage = inputfile.substr(inputfile.find("default_error_page=") + 20 ,inputfile.length() - 20);
                //serv.error_page = erorpage;
            //    std::cout << "error page " << srv[shhalmnserver].error_page << std::endl;
            }

            case 'b':
            {   
                
            }
            case 'l':
            {
        //        parse_location();      
            }
        }
      
    }
}
    //std::cout << "CH7AL MN SERVER " << shhalmnserver << std::endl;
  
Config::~Config()
{
    ;
}