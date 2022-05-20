#include "Utils.h"

int Utils::GetRandomInt(int min, int max)
{ 
    int value = min + (rand() % static_cast<int>(max - min + 1));
    return value;
}

float Utils::GetRandomFloat()
{
    std::default_random_engine generator;
    std::chi_squared_distribution<float> my_distribution(0.5);
    auto random_num = std::bind(my_distribution, generator);
    return random_num() * 10000.0;
}