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
            return 201;
        }
        static int CREATED()
        {
            return 202;
        }
        static int ACCEPTED()
        {
            return 203;
        }
        static int NOT_AUTHORIZED()
        {
            return 204;
        }
        static int NO_CONTENT()
        {
            return 205;
        }        
        static int RESET_CONTENT()
        {
            return 206;
        }
        static int PARTIAL_CONTENT()
        {
            return 207;
        }
            

};




#endif