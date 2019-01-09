/*****************************************
Title
	Tutorial
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int n;
	cin >> n;
	cin >> str;
	cin.ignore(256, '\n');
	getline(cin, str);
    cout << n*2 << endl << str << endl;
    return 0;
}
	*/
/*****************************************
Title
	Life, the Universe, and Everything 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while(n != 42)
	{
		cout << n << endl;
		cin >> n;
	}
    return 0;
}
*/

/*****************************************
Title
	Factorial! 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;
int main()
{
	int N=1, n;
	cin >> n;
	while(n > 0)
	{
		N *= n--; 
	}
	cout << N << endl;
    return 0;
}
*/

/*****************************************
Title
	Roy and Profile Picture 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;
int main()
{
	int l, w, h, N=0;
	cin >> l >> N;
	while(N-- > 0)
	{
		cin >> w >> h;
		if(w == h && w >= l) cout << "ACCEPTED" << endl;
		else if(h >= l && w >= l) cout << "CROP IT" << endl;
		else if(h < l || w < l) cout << "UPLOAD ANOTHER" << endl;
	}
    return 0;
}
*/

/*****************************************
Title
	Count Divisors 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int l, r, k, c=0;
	cin >> l >> r >> k;
	for(int i=l; i <= r; i++)
	{
		if(i%k == 0) c++;
	}
	cout << c << endl;
    return 0;
}
*/

/*****************************************
Title
	Find Product
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	long int N, n, s=1;
	cin >> N;
	for(int i=0; i < N; i++)
	{
		cin >> n;
		s = (s * n)%(long int)(pow(10, 9) + 7);
	}
	cout << s << endl;
    return 0;
}
*/

/*****************************************
Title
	Palindromic String
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int l = str.length() - 1;
	bool ok = true;
	for(int i=0; i <= l; i++)
	{
		if(str[i] != str[l-i]) ok = false;
	}
	cout << (ok ? "YES" : "NO") << endl;
    return 0;
}
*/

/*****************************************
Title
	Death, the Multiverse and Nothing
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

int main()
{
	int N, n;
	cin >> N;
	for(int i=0; i<N; i++)
	{
		cin >> n;
		cout << n - 1 << endl;
	}
    return 0;
}
*/

/*****************************************
Title
	Toggle String
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	for(int i=0; i < str.length(); i++)
	{
		if(str[i] < 91) str[i] += 32;
		else str[i] -= 32;
	}
	cout << str << endl;
    return 0;
}
*/

/*****************************************
Title
	Prime Numbers
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

void criba(bool m[], int tam)
{
	m[0] = false;
	m[1] = false;
	for (int i = 2; i <= tam; ++i)
		m[i] = true;

	for (int i = 2; i * i <= tam; ++i)
	{
		if (m[i])
		{
			for (int h = 2; i * h <= tam; ++h)
				m[i * h] = false;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	bool *arr = new bool[N];
	criba(arr, N);
	for(int i=0; i<N;i++){
		if(arr[i]) cout << i << " ";
	}
	cout << endl;
	return 0;
}
*/

/*****************************************
Title
	Magical Word
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

void criba(bool m[], int tam)
{
	m[0] = false;
	m[1] = false;
	for (int i = 2; i <= tam; ++i)
		m[i] = true;

	for (int i = 2; i * i <= tam; ++i)
	{
		if (m[i])
		{
			for (int h = 2; i * h <= tam; ++h)
				m[i * h] = false;
		}
	}

	for (int i = 0; i < 65; ++i) m[i] = false;
	for (int i = 91; i < 97; ++i) m[i] = false;
	for (int i = 123; i < tam; ++i) m[i] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in","r",stdin);
	bool *A = new bool[256];
	int T, N, i, up, down;
	string str;

	criba(A, 256);
	cin >> T;

	while (T--)
	{
		cin >> N >> str;
		for (i = 0; i < N; i++)
		{
			if (A[(int)str[i]])
			{
				cout << str[i];
			}
			else
			{
				up = str[i] + 1;
				down = str[i] - 1;
				while (!A[up] && !A[down])
				{
					up++;
					down--;
				}

				if (A[down] || (A[down] && A[up]))
					cout << (char)down;
				else
					cout << (char)up;
			}
		}
		cout << endl;
	}
	return 0;
}
*/
// 6 AFREEN
/*****************************************
Title
	Cipher 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in","r",stdin);
	int k;
	string str;
	cin >> str >> k;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			cout << (char)(((str[i] - 65 + k) % (90 - 64)) + 65);
		else if (str[i] >= 97 && str[i] <= 122)
			cout << (char)(((str[i] - 97 + k) % (122 - 96)) + 97);
		else if (str[i] >= 48 && str[i] <= 57)
			cout << (char)(((str[i] - 48 + k) % (57 - 47)) + 48);
		else
			cout << str[i];
	}
	cout << endl;
	return 0;
}
*/

/*****************************************
Title
	Play with numbers 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long int N, Q, l, r, i, min;
	long long int A[1000000];

	cin >> N >> Q;
	for (i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (i = 0; i < Q; i++)
	{
		cin >> l >> r;
		min = A[l];
		while (l++ != r-1)
		{
			if (min > A[l])
			{
				min = A[l];
			}
		}
		cout << min << endl;
	}

	return 0;
}
*/

/*****************************************
Title
	ASCII Value 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	char a;
	cin >> a;
	cout << (int)a << endl;

	return 0;
}
*/

/*****************************************
Title
	Anagrams 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, count;
	string a, b;
	int diff[256];

	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		count = 0;
		for (int i = 0; i < 256; i++)
		{
			diff[i] = 0;
		}
		for (int i = 0; i < a.length(); i++)
		{
			diff[(int)a[i]]++;
		}
		for (int i = 0; i < b.length(); i++)
		{
			diff[(int)b[i]]--;
		}
		for (int i = 0; i < 256; i++)
		{
			if (diff[i] < 0)
				count += (diff[i] * -1);
			else
				count += diff[i];
		}
		cout << count << endl;
	}

	return 0;
}
*/
/*****************************************
Title
	Seating Arrangement
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string *pStr = new string[6]{"WS", "MS", "AS", "AS", "MS", "WS"};
	int *pNum = new int[6]{1, 3, 5, 7, 9, 11};

	int T, n, inFront, d, type;

	cin >> T;
	while (T--)
	{
		cin >> n;
		n--;
		d = floor(n / 6);
		if (d % 2 == 1)
		{
			type = (6 + n) % 6;
			inFront = n - pNum[type] + 1;
		}
		else
		{
			type = n % 6;
			inFront = n + pNum[5 - type] + 1;
		}

		cout << inFront << " " << pStr[type] << endl;
	}

	return 0;
}
*/

/*****************************************
Title
	Anagrams 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, count;
	bool same;
	string a, b;
	int diff[256];

	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		same = true;
		for (int i = 0; i < 256; i++)
		{
			diff[i] = 0;
		}
		for (int i = 0; i < a.length(); i++)
		{
			diff[(int)a[i]]++;
			diff[(int)b[i]]--;
		}
		for (int i = 0; i < 256; i++)
		{
			if (diff[i] != 0)
			{
				same = false;
				break;
			}
		}
		cout << (same ? "YES" : "NO") << endl;
	}

	return 0;
}
*/