#include <iostream>
#include <vector>

void maximumSort(std::vector<int>&);
void swap(int&, int&);

int main()
{
    std::vector<int> v = {4,1,5,2,3};
    
    for(int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    
    maximumSort(v);
    
    for(int i : v)
        std::cout << i << " ";

    return 0;
}

void maximumSort(std::vector<int>& A)
{
    int i = A.size()-1;
    while(i >= 1)
    {
        int ind = 0;
        int j = 1;
        while(j <= i)
        {
            if(A[j] > A[ind])
            {
                ind = j;
            }
            j++;
        }
        swap(A[ind], A[i]);
        i--;
    }
}

void swap(int& i, int& j)
{
    int tmp = i;
    i = j;
    j = tmp;
}