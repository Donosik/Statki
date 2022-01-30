#include "App.h"
#include <iostream>

int main()
{
    try
    {
        App app;
    }
    catch (std::exception &ex)
    {
        std::cout<<"Error:"<<std::endl;
        std::cout<<ex.what()<<std::endl;
    }
    return 0;
}
