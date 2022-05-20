#include <exception>

#pragma once
namespace Errors
{
    class OutOfMemory : public std::exception
    {
        const char* what() const throw()
        {
            return "Data structures has no more space";
        }
    };
}