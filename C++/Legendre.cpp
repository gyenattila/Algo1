#include <iostream>

int legendre(int, int);

int main()
{
    std::cout << legendre(3, 11);
    return 0;
}

int legendre(int a, int k)
{
    int s = 0;
    if(a != 0)
        s = 1;
    
    while(k > 0)
    {
        if(k % 2 == 0)
        {
            a = a*a;
            k = k / 2;
        }
        else
        {
            s = s*a;
            k--;
        }
    }
    return s;
}