/*****************************************
Title
    Tutorial
Autor
    Juan Eizmendi
*****************************************/
#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort (int *A, int n, int x)
{
	int minimum;
	for(int i = 0; i < x ; i++)
	{
		minimum = i ;
		for(int j = i+1; j < n ; j++ )
		{
			if(A[ j ] < A[ minimum ])
			{
				minimum = j ;
			}
		}
		swap(A[minimum], A[i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int N, n[101], x;
    cin >> N >> x;
    for (int i = 0; i < N; ++i)
        cin >> n[i];
    selection_sort(n, N, x);
    for (int i = 0; i < N; ++i)
        cout << n[i] << " ";
    cout << endl;
}