#include <iostream>
#include <vector>

void mergeSort(std::vector<int>&);
void ms(std::vector<int>&, int, int);
void merge(std::vector<int>&, int, int, int);

int main(int argc, char const *argv[])
{
	std::vector<int> v{4,2,6,3,2,5,1,7,3};
	for(int& i : v)
		std::cout << i << " ";
	std::cout << std::endl;

	mergeSort(v);	

	for(int& i : v)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}


void mergeSort(std::vector<int>& A)
{
	ms(A, 0, A.size()-1);
}

void ms(std::vector<int>& A, int u, int v)
{
	if(u < v)
	{
		int m = (u+v-1)/2;
		ms(A, u, m);
		ms(A, m+1, v);
		merge(A, u, m, v);
	}
}

void merge(std::vector<int>& A, int u, int m, int v)
{
	// copy

	int d = m - u;
	std::vector<int> Z(d+1);
	int i = u;

	while(i <= m)
	{
		Z[i-u] = A[i];
		i++;
	}

	// merge

	int k = u;
	int j = 0;
	i = m+1;

	// from Z[j] and A[i] copy the smaller element into A[k]

	while(i <= v && j <= d)
	{
		if(A[i] < Z[j])
		{
			A[k] = A[i];
			i++;
		}
		else
		{
			A[k] = Z[j];
			j++;
		}
		k++;
	}

	// if Z[0..d] is empty the we're finished
	// if A[m+1..v] is empty then copy the rest from Z 
	
	while(j <= d)
	{
		A[k] = Z[j];
		k++;
		j++;
	}
}