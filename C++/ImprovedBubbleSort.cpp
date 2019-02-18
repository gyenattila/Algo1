#include <iostream>
#include <vector>

void imporvedBubbleSort(std::vector<int>&);
void swap(int&, int&);

int main()
{
    std::vector<int> v = {4,1,5,2,3};
    
    for(int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    
    imporvedBubbleSort(v);
    
    for(int i : v)
        std::cout << i << " ";

    return 0;
}

void imporvedBubbleSort(std::vector<int>& A)
{
    int i = A.size()-1;
    int u = 0;
    int j = 0;
    while(i >= 1)
    {
        u = 0;
        j = 0;
        while(j <= i-1)
        {
            if(A[j] > A[j+1])
            {
                swap(A[j], A[j+1]);
                u = j;
            }
            j++;
        }
        i = u;
    }
}

void swap(int& i, int& j)
{
    int tmp = i;
    i = j;
    j = tmp;
}