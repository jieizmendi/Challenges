/*****************************************
Title
	Assorted Arrangement
Autor
	Juan Eizmendi
*****************************************/

#include <bits/stdc++.h>
using namespace std;

//freopen("out","w",stdout);
typedef unsigned long int uli;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in","r",stdin);

	uli N, M, min = 0, n;
	vector<uli> A, C, ans;
	bool flag = false;

	cin >> N >> M;
	A.resize(N);
	ans.resize(N);
	C.resize(M);
	
	for (uli i = 0; i < M; ++i) cin >> C[i];
	for (uli i = 0; i < N; ++i) cin >> A[i];
	for (uli i = 0; i < N; ++i)
	{
		flag = true;
		ans[i] = ((min/C[A[i]-1])+1)*C[A[i]-1];
		while(flag)
		{
			flag = false;
			uli j = A[i];
			while(j<M)
			{
				if(ans[i]%C[j] == 0)
				{
					flag = true;
					break;
				}
				j++;
			}
			ans[i] += C[A[i]-1];
		}
		ans[i] -= C[A[i]-1];
		min = ans[i];
	}
	cout << ans[N-1] << endl;
	return 0;
}