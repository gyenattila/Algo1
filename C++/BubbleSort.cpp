#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>&);
void swap(int&, int&);

int main()
{
    std::vector<int> v = {3,5,2,4,1};
    for(int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    
    bubbleSort(v);
    
    for(int i : v)
        std::cout << i << " ";
    
    return 0;
}


void bubbleSort(std::vector<int>& A)
{
    int i = A.size();
    while(i >= 2)
    {
        int j = 0;
        while(j < i - 1)
        {
            if(A[j] > A[j+1])
                swap(A[j], A[j+1]);
            j++;
        }
        i--;
    }
}

void swap(int& i, int& j)
{
    int tmp = i;
    i = j;
    j = tmp;
}