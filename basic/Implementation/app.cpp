/*****************************************
Title
	Bob and Bombs 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long int T, k;
	long long int N, M, a, b, x, y, da, db, c;
	string str;
	cin >> T;
	while(T--)
	{
		x = 1;
		y = 1;
		c = 0;
		cin >> N >> M >> k;
		while(k--)
		{
			cin >> a >> b;
			if(a<0) da = floor((x-1)/(-a));
			else if(a>0) da = floor((N-x)/a);
			else da = N;
			if(b<0) db = floor((y-1)/(-b));
			else if(b>0) db = floor((M-y)/b);
			else db = M;


			if(da < db)
			{
				x += da*a;
				y += da*b; 
				c += da;
			}else
			{
				x += db*a;
				y += db*b; 
				c += db;
			}
		}
		cout << c << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Bob and Bombs 
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	unsigned int T, c;
	string str;
	cin >> T;
	while(T--)
	{
		cin >> str;
		str = "00"+str+"00";
		for (string::iterator it = str.begin(); it != str.end(); it++)
		{
			if(*it == 'B')
			{
				if(*(it+1) == 'W') *(it+1) = '1';
				if(*(it+2) == 'W') *(it+2) = '1';
				if(*(it-1) == 'W') *(it-1) = '1';
				if(*(it-2) == 'W') *(it-2) = '1';
			}
		}
		c = 0;
		for (string::iterator it = str.begin(); it != str.end(); it++)
			if(*it == '1') c++;
		cout << c << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	War 
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
using namespace std;

int main()
{
	int T;
	unsigned long long int N, alice, bob, temp;
	cin >> T;
	while(T--)
	{
		cin >> N;
		alice = 0;
		for (unsigned long long int i = 0; i < N; i++)
		{
			cin >> temp;
			if(temp > alice) alice = temp;
		}
		bob = 0;
		for (unsigned long long int i = 0; i < N; i++)
		{
			cin >> temp;
			if(temp > bob) bob = temp;
		}
		if(alice < bob) cout << "Bob" << endl;
		else if(alice > bob) cout << "Alice" << endl;
		else cout << "Tie" << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Final Destination 
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
	long int x = 0, y = 0;
	cin >> str;
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		switch(*it)
		{
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;
			case 'L':
				x--;
				break;
			case 'R':
				x++;
				break;
		}
	}
	cout << x << " " << y << endl;
    return 0;
}
*/
/*****************************************
Title
	Little Jhool and psychic powers 
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
	char chr = '0';
	int c = 0;
	cin >> str;
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		if(*it != chr)
		{
			chr = *it;
			c = 0;
		}
		else c++;
		if(c == 6) break;
	}
	cout << (c==6 ? "Sorry, sorry!" : "Good luck!") << endl;
    return 0;
}
*/
/*****************************************
Title
	Dushhera special 
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
using namespace std;

int main()
{
	unsigned long int T, N, k, p;
	cin >> T;
	while(T--)
	{
		cin >> p >> k;
		k++;
		for (int i = 1; i <= p; ++i) cout << (k*i) << " ";
		cout << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Dalton and Compiler Design 
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
using namespace std;

int main()
{
	unsigned long int T, N, a;
	cin >> T;
	while(T--)
	{
		cin >> N;
		a = N>>1;
		if(N&1)
			cout << (N>>1) << " " << (N>>1)+1 << endl;
		else
			cout << (N>>1) << " " << (N>>1) << endl;
	}
    return 0;
}
*/
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
	int c[10];
	for (int i = 0; i < 10; ++i) c[i] = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		switch(str[i])
		{
			case '0':
				c[0]++;
				break;
			case '1':
				c[1]++;
				break;
			case '2':
				c[2]++;
				break;
			case '3':
				c[3]++;
				break;
			case '4':
				c[4]++;
				break;
			case '5':
				c[5]++;
				break;
			case '6':
				c[6]++;
				break;
			case '7':
				c[7]++;
				break;
			case '8':
				c[8]++;
				break;
			case '9':
				c[9]++;
				break;

		}
	}
	for (int i = 0; i < 10; i++) cout << i << "  " << c[i] << endl;
    return 0;
}
*/