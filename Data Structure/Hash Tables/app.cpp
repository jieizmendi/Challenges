/*****************************************
Title
	Pair Sums 
Autor
	Juan Eizmendi
*****************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	unsigned long long int N, K;
	vector<unsigned long long int> A;
	bool flag = false;

	cin >> N >> K;
	A.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	
	for (vector<unsigned long long int>::iterator i = A.begin(); i != A.end()-1; ++i)
	{
		for (vector<unsigned long long int>::iterator j = i+1; j != A.end(); ++j)
		{
			if(*i + *j == K)
			{
				flag = true;
				//goto ans;
				i = A.end()-1;
				j = A.end();
			}
			cout << "par" << endl;
		}
	}
	ans:
	cout << (flag?"YES":"NO") << endl;
	return 0;
}

/*****************************************
Title
	Difficult Characters
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;

bool comprarator(pair<char, unsigned long long int> a, pair<char, unsigned long long int> b)
{
	if(a.second < b.second) return true;
	if(a.second > b.second) return false;
	if(a.first < b.first ) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	int T;
	vector< pair<char, unsigned long long int> > vec;
	
	

	cin >> T;
	while(T--)
	{
		cin >> str;
		vec.clear();
		for (int i = 'a'; i <= 'z'; ++i) vec.push_back(pair<char, unsigned long long int>(i,0));
		for (string::iterator i = str.begin(); i != str.end(); ++i) vec[(*i)-'a'].second++;
		sort(vec.begin(), vec.end(), comprarator);
		for (vector< pair<char, unsigned long long int> >::iterator i = vec.begin(); i != vec.end(); ++i) cout << i->first << " ";
		cout << endl;
	}
	return 0;
	
}
*/
/*****************************************
Title
	Maximum occurrence
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	int abc[256], max = 0;
	char c;

	for (int i = 0; i < 256; ++i) abc[i] = 0;

	getline(cin, str);
	
	for (string::iterator i = str.begin(); i != str.end(); ++i) abc[*i]++;
	
	for (int i = 0; i < 256; ++i) 
	{
		if(abc[i] > max)
		{
			max = abc[i];
			c = i;
		}
	}
	cout << c << " " << max << endl;
	return 0;
}
*/
/*****************************************
Title
	Xsquare And Double Strings
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string str, ans;
	int T, abc[26];
	bool flag;

	cin >> T;
	while(T--)
	{
		cin >> str;
		ans = "Yes";

		

		for (int i = 0; i < 26; ++i) abc[i] = 0;
		
		for (string::iterator i = str.begin(); i != str.end(); ++i) abc[(*i)-97]++;
		
		flag = true;
		while(flag)
		{
			flag = false;
			for (int i = 0; i < 26; ++i)
			{
				if(abc[i]%2 == 1)
				{
					abc[i]--;
					flag = true;
				}
			}	
		}
		flag = false;
		for (int i = 0; i < 26; ++i)
		{
			if(abc[i] == 1) ans = "No";
			if(abc[i] != 0) flag = true;
		}
		
		cout << (flag?ans:"No") << endl;

	}
	return 0;
}
*/