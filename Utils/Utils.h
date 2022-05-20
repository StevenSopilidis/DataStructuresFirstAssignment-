#include <random>
#include <functional>
#include <ctime>

class Utils
{
public:
    // function for returning a random int number in a given range
    // @param min: lower bound of range
    // @param max: upper bounnd of range 
    static int GetRandomInt(int min, int max);
    // function for generating a random float value
    static float GetRandomFloat();
};
