/*****************************************
Title
	Prateek and his Friends
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;	
typedef unsigned long long int ulli;
int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("in","r",stdin);
	ulli T, N, X, arr[1000001], sum;
	bool flag;

	cin >> T;
	while(T--)
	{
		cin >> N >> X;
		for (ulli i = 0; i < N; ++i) cin >> arr[i];

		flag = false;
		for (ulli i = 0; i < N; ++i)
		{
			sum = 0;
			for (ulli j = i; j < N && sum < X; ++j) sum += arr[j];
			if(sum == X)
			{
				flag = true;
				break;
			}
		}		
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
*/
/*****************************************
Title
	Chandu and his Girlfriend
Autor
	Juan Eizmendi
*****************************************/

#include <bits/stdc++.h>
using namespace std;	
typedef unsigned long long int ulli;

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("in","r",stdin);
	ulli T, N, arr[1000001];

	cin >> T;
	while(T--)
	{
		cin >> N;
		for (ulli i = 0; i < N; ++i) cin >> arr[i];
		sort(arr, arr+N, std::greater<ulli>());
		for (ulli i = 0; i < N; ++i) cout << arr[i] << " ";
		cout << endl;

	}
	return 0;
}
