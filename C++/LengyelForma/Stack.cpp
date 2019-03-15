#include "Stack.hpp"


void Stack::push(char c)
{
    if(size < vec.size())
    {
        vec[size] = c;
        ++size;
    }
}

char Stack::pop()
{
    if(size > 0)
    {
        --size;
        return vec[size];
    }
    else
    {
        std::cerr << "ERROR" << std::endl;
        return -1;  
    }
}

char Stack::top()
{
    if(size > 0)
        return vec[size-1];
    else
    {
        std::cerr << "ERROR" << std::endl;
        return -1;
    }
}
