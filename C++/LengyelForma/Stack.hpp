#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED

#include <iostream>
#include <vector>

class Stack
{
private:
    std::vector<char> vec;
    int size;

public:
    Stack(int m) : size(0) { vec.resize(m); }
    ~Stack() { }

    void push(char c);
    char pop();
    char top();
    inline bool isFull() { return (size == vec.size()-1); }
    inline bool isEmpty() { return (size == 0); }
    inline void setEmpty() { size = 0; }
};

#endif // STACK_HPP_INCLUDED
