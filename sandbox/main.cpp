/*
    THIS CODE IS UNDER THE MIT LICENSE, SEE LICENSE FOR MORE DETAILS
*/
#include "../engine/core/include/application_control.hpp"

// STD
#include <iostream>

int main()
{
    Umbra::Core::ApplicationControl app{"Umbra!"};
    try
    {
        app.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
