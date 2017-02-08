#ifndef TEST_HELLO_
#define TEST_HELLO_
#include<string>
using std::string;

#if defined_WIN32
    #if LIBHELLO_BULID
        #define LIBHELLO_API_declspec(dllexport)
    #else
        #define LIBHELLO_API_declspec(dllexport)
    #endif
#else
    #define LIBHELLO_API 
#endif

LIBHELLO_API void display(const string& name);

#endif