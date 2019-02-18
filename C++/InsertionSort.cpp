#include <iostream>
#include <vector>

void insertionSort(std::vector<int>&);

int main()
{
    std::vector<int> v = {4,3,1,3,5,2,6,4};
    for(int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    
    insertionSort(v);
    
    for(int i : v)
        std::cout << i << " ";
    
    return 0;
}


void insertionSort(std::vector<int>& A)
{
    int i = 1;
    while(i < A.size())
    {
        if(A[i-1] > A[i])
        {
            int x = A[i];
            A[i] = A[i-1];
            int j = i - 1;
            while(j >= 0 && A[j] > x)
            {
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = x;
        }
        i++;
    }
}