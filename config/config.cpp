/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:58:18 by sel-fcht          #+#    #+#             */
/*   Updated: 2022/04/20 09:28:31 by sel-fcht         ###   ########.fr       */
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
        std::string name = inputfile.substr(inputfile.find("[") + 1, inputfile.find("]") - 1);
        if (inputfile[len] != ']')
        {
            std::cout << "makamlash ] dyal lhost" << std::endl;
            exit(EXIT_FAILURE);
        }
        else if (name != "end")
        {
            serv.name = name;
            srv.push_back(serv);
            initialize(shhalmnserver);
            std::cout << "smit server " << srv[shhalmnserver].name<< std::endl; 
        }
        else
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
                if (nameof == "port" && srv[shhalmnserver].port == -1)
                {    
                    std::string port = inputfile.substr(inputfile.find("port=") + 5, inputfile.length()- 4);
                    port = port.substr(0,port.length()-1);//removiw ;
                    if(Help::atoi(port.c_str()) <= 0 || Help::atoi(port.c_str())> 9999 )
                    {
                        std::cout << "wrong port number" << std::endl;
                        exit (1);
                    }
                    srv[shhalmnserver].port = Help::atoi(port.c_str());
                                                                                       //handle ra9m dlport later 
                    std::cout << "smit port :" << port << std::endl;
                }
            }
            case 'd':
            {   
                std::string er = inputfile.substr(0, inputfile.find_first_of("="));
                if (er == "default_error_page")
                {
                    std::string erorpage = inputfile.substr(inputfile.find("default_error_page=") + 19 ,inputfile.length() - 19);
                    srv[shhalmnserver].error_page = erorpage;
                    std::cout << "error page :" << erorpage << std::endl;
                }
            }
            case 'r':
            {
                std::string root = inputfile.substr(0, inputfile.find_first_of("="));
                if (root == "root")
                {
                    std::string root1 = inputfile.substr(inputfile.find("root=") + 5, inputfile.length() - 5);
                    root1 = root1.substr(0,root1.length() -1);
                    srv[shhalmnserver].root = root1;
                    std::cout << "root =" << srv[shhalmnserver].root << std::endl;
                }
            }

            case 'b':
            {   
                std::string body = inputfile.substr(0, inputfile.find_first_of("="));
                if (body == "bodysize_limit")
                {
                    std::string body1 = inputfile.substr(inputfile.find("bodysize_limit=")+15, inputfile.length()-15);
                    body1 = body1.substr(0,body1.length() -1);
                    srv[shhalmnserver].bodySize = Help::atoi(body1.c_str());
                    std::cout << "body size limit = " << srv[shhalmnserver].bodySize << std::endl;
                }
            }
            case 'l':
            {
        //        parse_location();      
            }
        }  
    }
}
  
Config::~Config()
{
    ;
}