#ifndef RESPONSES_HPP
#define RESPONSES_HPP

#include <iostream>
#include <string>

class Responses
{
    private:
    
    
    public:
        static int ok()
        {
            return 200;
        }
        static int CREATED()
        {
            return 201;
        }
        static int ACCEPTED()
        {
            return 202;
        }
        static int NOT_AUTHORIZED()
        {
            return 203;
        }
        static int NO_CONTENT()
        {
            return 204;
        }        
        static int RESET_CONTENT()
        {
            return 205;
        }
        static int PARTIAL_CONTENT()
        {
            return 206;
        }
        static int CONTINUE()
        {
            return 100;
        }
        static int SWITCHING_PROTOCOLS()
        {
            return 101;
        }
        static int EARLY_HINTS()
        {
            return 103;
        }
        static int MULTIPLE()
        {
            return 300;
        }    
        static int MOVED()
        {
            return 301;
        }
        static int FOUND()
        {
            return 302;
        }
        static int SEE_OTHER()
        {
            return 303;
        }
        static int NOT_MODIFIED()
        {
            return 304;
        }
        static int BAD_REQUEST()
        {
            return 400;
        }
        static int UNAUTHORIZED()
        {
            return 401;
        }
        static int PAYMENT_METHOD()
        {
            return 402;
        }
        static int FORBIDEN()
        {
            return 403;
        }
        static int NOT_FOUND()
        {
            return 404;
        }
        static int METHOD_NOT_ALLOWED()
        {
            return 405;
        }
        static int NOT_ACCEPTABLE()
        {
            return 406;
        }
        static int PROXY_AUTHENTIFICATION_REQUIRED()
        {
            return 407;
        }
        static int REQUEST_TIMEOUT()
        {
            return 408;
        }
        static int CONFLICT()
        {
            return 409;
        }
        static int GONE()
        {
            return 410;
        }
        static int LENGHT_REQUIRED()
        {
            return 411;
        }
        static int PAYLOAD_TOO_LARGE()
        {
            return 413;
        }
        static int URI_TOO_LONG()
        {
            return 414;
        }
        static int UNSUPPORTED()
        {
            return 415;
        }
        static int 
};




#endif