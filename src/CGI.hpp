/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:36:54 by sel-fcht          #+#    #+#             */
/*   Updated: 2022/05/26 00:01:54 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CGI_HPP
#define CGI_HPP

#include <map>

// #include "Request.hpp"

#include <iostream>
#include <string>
#include <algorithm>
//must include parser of the config file
//must include request/response i guess
//So how does the whole interface work? Most servers expect CGI programs and scripts to reside in a special directory, usually called cgi-bin, and/or to have a certain file extension. (These configuration parameters are discussed in the Configuring the Server section in this chapter.) When a user opens a URL associated with a CGI program, the client sends a request to the server asking for the file.
class CGI
{
    public:
        CGI();
        ~CGI();
        static std::pair<std::string , std::map<std::string, std::string> > exec_file(std::string path , Request &req, std::string path_cgi);

}






#endif