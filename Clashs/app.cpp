/*
5 5 3
1 2 2 3 3
1 1 2 3 4 5
2 4
1 2
4 5
#include <bits/stdc++.h>
using namespace std;	
typedef unsigned long long int ulli;
int main()
{
	ios_base::sync_with_stdio(false);
	ulli N, C, Q;

	cin >> N >> C >> Q
	lli L, K, c, abc[26], ans = 0;
	string str;

	cin >> L >> K >> str;

	for (lli i = 0; i < L-1; ++i)
	{
		for (lli j = i; j < L; ++j)
		{
			if((j-i)*26 > K)
			{
				if(refo(str.substr(i, j-i)))
				{
					for (int k = 0; k < 26; ++k) abc[k] = 0;
					lli h = i;
					while(h <= j) abc[str[h++]-97]++;
					c = 0;
					for (int k = 0; k < 26; ++k) if(abc[k]!=0) c++;
					if(((j-i+1)*c) >= K) ans++;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
*/
-1 -1 -1 -1 -1 -1 -1 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 19 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 48 -1 -1 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 107 14 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 2 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 19 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 48 -1 -1 -1 -1 10 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 107 14 -1 -1 -1 
#include <bits/stdc++.h>
using namespace std;	
typedef long long int lli;
int main()
{
	ios_base::sync_with_stdio(false);
	lli L, K, c, abc[26], ans = 0;
	string str;
	bool flag;

	cin >> L >> K >> str;

	for (lli i = 0; i < L-1; ++i)
	{
		for (lli j = i; j < L; ++j)
		{
			if((j-i)*13 > K)
			{
				//pali
				string::iterator a = str.begin()+i, b = str.begin()+j;
				for (int k = 0; k < 26; ++k) abc[k] = 0;
				flag = true;
				while(a<=b)
				{
					if(*a != *b)
						flag = false;
					abc[*a-97]++;
					abc[*b-97]++;
					a++;
					b--;
				}
				if(flag)
				{
					c = 0;
					for (int k = 0; k < 26; ++k) if(abc[k]!=0) c++;
					if(((j-i+1)*c) >= K) ans++;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;	
typedef long long int lli;

int main()
{
	ios_base::sync_with_stdio(false);
	lli N, C, n[100001], c[100001], cc;
	
	cin >> N >> C;
	n[1] = 1;
	for (lli i = 2; i <= N; ++i)
		cin >> n[i];
	for (lli i = 1; i <= N; ++i)
		cin >> c[i];
	
	for (int i = 1; i <= N; ++i)
	{
		cout << "Color[" << i << "]: " << c[i] << endl;
	}

	for (lli i = 1; i <= N; ++i)
	{
		lli j = n[i], last_match = -1;

		while(n[j] != j)
		{
			if(c[j] == c[i]) last_match = j;
			j = n[j];
		}
		if(c[j] == c[i]) last_match = j;
		cout << last_match << " ";
	}
	cout << endl;
	return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;	
typedef long long int lli;

int es_primo(int N)
{
   int k, raiz;
   raiz = (int) sqrt(N);
   for( k=2; N%k && k<=raiz; k++);
   if(k==raiz+1)
       return 1;
   return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	lli Q, a, b;
	
	cin >> Q;
	while(Q--)
	{
		cin >> a >> b;

	}
	n[1] = 1;
	for (lli i = 2; i <= N; ++i)
		cin >> n[i];
	for (lli i = 1; i <= N; ++i)
		cin >> c[i];
	
	cout << -1 << " ";
	for (lli i = 2; i <= N; ++i)
	{
		lli cc = c[i];
		lli j = i;
		while(n[j] != j)
		{
			if(c[j] == cc) break;
			j = n[j];
		}
		if(c[j] == cc) cout << j << " ";
		else cout << -1 << " ";
	}
	cout << endl;
	return 0;
}

   cout << "Los factores primos son: ";
      for(i=1; i<=num; i++)
         if(num%i==0 && es_primo(i))
            cout << i << " "; 
       */