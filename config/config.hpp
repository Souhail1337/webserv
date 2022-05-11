/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:38:57 by sel-fcht          #+#    #+#             */
/*   Updated: 2022/05/11 18:33:25 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
#define CONFIG_HPP
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <string>

class Config
{
    public:
        Config();
        ~Config();
        Config(std::string input);
        Config &operator=(const Config &con);
          struct location
        {
            std::string path;
            std::string method;
            std::string root;
            std::string autoind;
            int bodySize;
            std::string index;
            std::string cgi_path;
            std::string extension;
            std::string allowedMethods;
            // some of those are optional but still mzyan tziddhum ..
        };

        struct server
        {
            std::string name;
            std::string host;
            std::string root;
            int port;
            int bodySize;
            std::string index;
            std::string error_page;
            std::vector<location> locations;
        };
      
        
        std::vector<server> srv;
        //start parsing had zbi;
        void initialize(int i);  
        void Linit(location *loc);      
        void parse_server(std::string &inputfile);
        void parse_location(std::string &loc,const std::string &chars);
        unsigned int shhalmnserver ; 
        unsigned int shhalmnlocation;
};



#endif