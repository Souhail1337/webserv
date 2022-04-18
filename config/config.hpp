/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:38:57 by sel-fcht          #+#    #+#             */
/*   Updated: 2022/04/18 01:02:48 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_HPP
#define CONFIG_HPP


class Config
{
    public:
        Config();
        ~Config();
        Config(std::string input);
        Config &operator=(const Config &con);
        struct server
        {
            std::string name;
            std::string host;
            int port;
            int bodySize;
            std::vector<location> locations;
        };
        struct location
        {
            std::string 
        };
        std::vector<server> srv;
        //start parsing had zbi;
        void initialize(int i);        
        
};



#endif