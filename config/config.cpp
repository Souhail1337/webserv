/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:58:18 by sel-fcht          #+#    #+#             */
/*   Updated: 2022/04/28 23:32:08 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

this ois only a test

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
    loc->allowedMethods = "NULL";
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
            case 'i':
            {
                std::string inde = inputfile.substr(0, inputfile.find_first_of("="));
                if (inde == "index")
                {
                    std::string indexx = inputfile.substr(inputfile.find("index=") + 6, inputfile.length() - 6);
                    indexx = indexx.substr(0, indexx.length() - 1);
                    srv[shhalmnserver].index = indexx;
                    std::cout << "index: " <<  indexx<<std::endl;
                }
            }
            case 'l':
            {
                std::string location = inputfile.substr(0, inputfile.find_first_of("="));
                if (location == "location")
                {
                    std::string loc = inputfile.substr(inputfile.find("location={") +10, inputfile.length() -10);
                    loc = loc.substr(0,inputfile.length() - 1);
                  //  std::cout << "location :" << loc << std::endl;
                    parse_location(loc, ",");
                }
            }
        }  
    }
}

std::string removeacc(std::string loc)
{
    std::string str;
    str = loc.substr(loc.find_first_of("{") + 1 , loc.find_last_of("}") - 2);
    std::cout << " hihi : |" << str << std::endl;
    return str; 
}

void Config::parse_location(std::string &loc, const std::string &chars)
{
    //std::cout << "location :"<< loc << std::endl;
    //std::cout << "characters :" << chars << std::endl;
    location loca;
    std::string vir;
    std::string str;
    std::vector<std::string> strs; // where to stock parametres of the location;
    Linit(&loca);
    loca.bodySize = srv[shhalmnserver].bodySize;
    loca.index = srv[shhalmnserver].index;
    loc = removeacc(loc);
    int i;
    int virg = 0;
    while(i < loc.length())
    {
        if(loc[i]== ',')
        {
            virg++;
            i++;
        }
        else
            i++;
        //std::cout << " virg" << virg << std::endl;
    }
    shhalmnlocation = i;
    i = 0;
    virg = 0;
    while((i = loc.find_first_of(",", virg)) != std::string::npos)
    {
        if (i > virg)
        {
            str = loc.substr(virg, i - virg);
            std::cout << "string is |" << str << "|" << std::endl;
            strs.push_back(str);
        }
        virg = i + 1;
    }
    int x = -1;
    while(++x < strs.size())
    {
        switch (strs[x][0])
        {
            case 'p':
            {
                std::string nameof = strs[x].substr(0, strs[x].find_first_of("="));
                    if (nameof == "path" && loca.path == "NULL")
                    {
                        str = strs[x].substr(strs[x].find("path=")+5, strs[x].length());
                        std::cout << "path = "<< str<< std::endl; 
                        loca.path = str;
                    }
            }
            case 'm':
            {
            std::string nameof = strs[x].substr(0, strs[x].find_first_of("="));
            if (nameof == "methods" && loca.method == "NULL")
                {
                str = strs[x].substr(strs[x].find("methods=") + 8, strs[x].length());
                std::cout << "methods =" << str << std::endl;
               }       
            }
            case 'r':
            {
                std::string nameof  = strs[x].substr(0, strs[x].find_first_of("="));
                if (nameof == "root" && loca.root == "NULL")
                {
                    str = strs[x].substr(strs[x].find("root=") + 5, strs[x].length());
                    std::cout << "root :" << str << std::endl; 
                }
            }
            case 'a':
            {
                std::string nameof = strs[x].substr(0, strs[x].find_first_of("="));
                if (nameof == "auto-index")
                {
                    std::cout << "allowed " << std::endl;
                }
                if (nameof == "allowed-methods")
                {
                    if (loca.allowedMethods == "NULL")
                    {
                        str = strs[x].substr(strs[x].find("allowed-methods=") + 16, strs[x].length());
                        std::cout << "allowed methods = |" << str << "|" << std::endl;
                        
                    }
                    
                }
            }
            case 'e':
            {
                std::string nameof = strs[x].substr(0, strs[x].find_first_of("="));
                if (nameof == "extension" && loca.extension  == "NULL")
                {
                    str = strs[x].substr(strs[x].find("extension=") +10, strs[x].length());
                    std::cout << "extension : " << str << std::endl;
                }
            }
            //ase 'b':
            //
            //   
            //
            //ase ''
        }
    }

}
  
Config::~Config()
{
    
}