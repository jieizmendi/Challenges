#include <iostream>
using namespace std;

int main()
{
	int N, M, n, o = -1;
    cin >> N >> M;
    for(int i=0; i<N; i++) 
	{
		cin >> n;
		if(n == M) o = i+1;
	}
    cout << o << endl;
    return 0;
}
/*
#include <iostream>
using namespace std;

int main()
{
	int N, M, o = -1;
    cin >> N >> M;
    int *A = new int[N];
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<N; i++) if(A[i] == M) o = i;
    cout << o+1 << endl;
    return 0;
}
*/