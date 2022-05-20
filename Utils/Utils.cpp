#include "Utils.h"

int Utils::GetRandomInt(int min, int max)
{ 
    std::default_random_engine generator;
    std::uniform_int_distribution<int> data_element_distribution(min, max);
    auto random_element = std::bind(data_element_distribution, generator);
    int data_element = random_element();
    return data_element;
}

float Utils::GetRandomFloat()
{
    std::default_random_engine generator;
    std::chi_squared_distribution<float> my_distribution(0.5);
    auto random_num = std::bind(my_distribution, generator);
    return random_num() * 10000.0;
}