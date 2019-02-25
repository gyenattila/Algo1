#include <iostream>
#include <vector>

void MinimumSort(std::vector<int>&);
void swap(int&, int&);

int main()
{
    std::vector<int> v{3,2,5,1,4};
    for(int i : v)
        std::cout << i << " ";
    std::cout << std::endl;
    
    MinimumSort(v);
    
    for(int i : v)
        std::cout << i << " ";

    return 0;
}


void MinimumSort(std::vector<int>& A)
{
    int i = 0;
    while(i < A.size()-1)
    {
        int min = i;
        int j = i + 1;
        while(j < A.size())
        {
            if(A[j] < A[min])
                min = j;
            j++;
        }
        swap(A[i], A[min]);
        i++;
    }
}

void swap(int& i, int& j)
{
    int tmp = i;
    i = j;
    j = tmp;
}