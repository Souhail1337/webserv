/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGI.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:05:12 by sel-fcht          #+#    #+#             */
/*   Updated: 2022/05/26 16:25:17 by sel-fcht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "CGI.hpp"

#include <math.h>
CGI::CGI()
{
    ;
}

static std::pair<std::string, std::map<std::string, std::string> > exec_file(std::string path, Request &res, std::string pathfile)
{
    char **args = fill_argd(cgiPath, path);
    char **envp;
    if (res.getMethod() == "POST")
    {
        if (!(res.getHeader("Content-Type").empty())
            setenv("CONTENT_TYPE",res.getHeader("CONTENT_TYPE"))
    }
    setenv("REDIRECT_STATUS",true,1);
    setenv("QUERY_STRING",res.getQueryString(),1);
    setenv("REQUEST_METHOD",res.getMethod(),1);
    setenv("SCRIPT_NAME",res.getPath(),1);
    setenv("SERVER_NAME",res.getHost(),1);
    setenv("SERVER_PORT",res.getPort(),1);
    setenv("SERVER_PROTOCOL",res.getProtocol(),1);
    setenv("SERVER_SOFTWARE",res.getServer(),1);
    setenv("GATEWAY_INTERFACE",res.getGateway(),1);
    setenv("REMOTE_ADDR",res.getClient(),1);
    setenv("REMOTE_PORT",res.getClientPort(),1);
    setenv("REQUEST_URI",res.getRequestURI(),1);
    setenv("DOCUMENT_ROOT",res.getDocumentRoot(),1);
    setenv("SCRIPT_FILENAME",pathfile,1);
    setenv("PATH_INFO",res.getPathInfo(),1);
    setenv("PATH_TRANSLATED",res.getPathTranslated(),1);
    setenv("CONTENT_LENGTH",res.getContentLength(),1);
    setenv("CONTENT_TYPE",res.getContentType(),1);
    setenv("HTTP_ACCEPT",res.getAccept(),1);
    setenv("HTTP_ACCEPT_CHARSET",res.getAcceptCharset(),1);
    setenv("HTTP_ACCEPT_ENCODING",res.getAcceptEncoding(),1);
    setenv("HTTP_ACCEPT_LANGUAGE",res.getAcceptLanguage(),1);
    setenv("HTTP_CONNECTION",res.getConnection(),1);
    setenv("HTTP_HOST",res.getHost(),1);
    setenv("HTTP_REFERER",res.getReferer(),1);
    setenv("HTTP_USER_AGENT",res.getUserAgent(),1);
    setenv("HTTP_COOKIE",res.getCookie(),1);
    setenv("HTTP_CACHE_CONTROL",res.getCacheControl(),1);
    setenv("HTTP_PRAGMA",res.getPragma(),1);
    setenv("HTTP_DNT",res.getDNT(),1);
    
        
}
CGI::~CGI()
{
    
}




