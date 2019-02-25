#include <iostream>

class Stack
{
private:
    int* A;
    int m;
    int n;
    
public:
    Stack(int);
    ~Stack();
    
    void push(int);
    int pop();
    int top();
    inline bool isFull() const { return n == m; }
    inline bool isEmpty() const { return n == 0; }
    void setEmpty();
};

Stack::Stack(int m)
{
    A = new int[m];
    this->m = m;
    n = 0;
}

Stack::~Stack() { delete[] A; }


void Stack::push(int x)
{
    if(n < m)
    {
        n++;
        A[n] = x;
    }
    else
        std::cerr << "FullStackError" << std::endl;
}

int Stack::pop()
{
    if(n > 0)
    {
        n--;
        return A[n+1];
    }
    else
    {
        std::cerr << "EmptyStackError" << std::endl;
        return -1;
    }
}

int Stack::top()
{
    if(n > 0)
        return A[n];
    else
    {
        std::cerr << "EmptyStackError" << std::endl;
        return -1;
    }
}

void Stack::setEmpty() { n = 0; }

int main(int argc, char const *argv[]) { }
