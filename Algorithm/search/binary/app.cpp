#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int N, M, q, low, high, mid;
    
    cin >> N;
    int *A = new int[N];
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A, A + N);
	
	cin >> M;
	for(int m=0; m<M; m++)
	{
		cin >> q;
		low = 0;
		high = N-1;

		while(A[mid] != q && high>low)
		{
			mid = (low+high)>>1;
			//if(A[mid] == q) break;
			if(A[mid] > q) high = mid-1;
			else low = mid+1;
		}

		cout << low << endl;
	}

    return 0;
}