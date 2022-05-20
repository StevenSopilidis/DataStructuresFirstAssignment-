#include <exception>

#pragma once
namespace Errors
{
    class OutOfBounds : public std::exception
    {
        const char* what() const throw()
        {
            return "Tried to access an element that is out of bounds";
        }
    };
}
