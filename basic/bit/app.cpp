/*****************************************
Title
	Samu and her Birthday Party 
Autor
	Juan Eizmendi
*****************************************/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	int T;

	cin >> T;
	while(T--)
	{
		cin >> str;
		for (string::iterator i = str.begin()+1; i != str.end(); ++i)
			if(*i == *(i-1)) 
				str.erase(i), i--;
		cout << str << endl;
	}
	return 0;
}
/*****************************************
Title
	 The Castle Gate 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

int main()
{
	int T, N, c;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		c = 0;
		for (int j = 1; j <= N; j++)
		{
			for (int k = j+1; k <= N; k++)
			{
				if((j^k) <= N) c++;
				cout << "Par(" << j << "," << k << ") = " << (j^k) << endl;
			}
		}
		cout << c << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Subset XOR 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <math.h>
using namespace std;

int FastPowerSetXOR(int *A, int N)
{
	if(N==1) return A[0];
	return 0;
}

int PowerSetXOR(int *A, int size)
{
	int conbinations = pow(2, size);
	int set_xor, sets_xor = -1;
	for (int i = 0; i < conbinations; i++)
	{
		set_xor = -1;
		for (int j = 0; j < size; j++)
		{
			if(i & (1<<j))
			{
				if(set_xor == -1)
					set_xor = A[j];
				else
					set_xor ^= A[j];
			}
		}
		if(sets_xor == -1)
			sets_xor = set_xor;
		else
			sets_xor ^= set_xor;
	}

	return sets_xor == -1 ? 0 : sets_xor;
}

int main()
{
	int T, N, A[101];
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> A[j];
		}
		cout << PowerSetXOR(A, N) << endl;
	}
    return 0;
}
*/

/*****************************************
Title
	The Magic
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;
int main()
{
	int T, N, days;
	cin >> T;

	while(T--)
	{
		cin >> N;
		days = 0;
		while(N)
		{
			if(N%2 != 0)
				days++;
			N = N>>1;
		}
		cout << days << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Lucky Numbers
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int T, N, count, sum, j, i;
	cin >> T;

	while(T--)
	{
		cin >> N;
		sum = 0;
		for (i = 3; i <= N; i++)
		{
			j = i;
			count = 0;
			while(j)
			{
				if(j & 1) count++;
				if(count == 3) j=0;
				j = j>>1;
			}
			if(count == 2) sum += i;
		}
		cout << (sum%1000000007) << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Sherlock and XOR
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    long long int N, n, c;
	cin >> T;
	while(T--)
	{
		cin >> N;
		c = (N*(N+1)/2)-1;
		while(N--) cin >> n;
		
		cout << (c>>1) << endl;
	}
    return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    long long int N, A[100001], c;
	cin >> T;
	while(T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++) cin >> A[i];
		
		c = 0;
		for (int i = 1; i < N; i++)
		{
			for (int j = i+1; j <= N; j+=2)
			{
				if((i&1)^(j&1))	c++;
			}
		}

		cout << c << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Monk and Tasks 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task
{
	unsigned long long int task;
    int ones;
};

bool comparator(Task a, Task b)
{
	return a.ones < b.ones;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    unsigned long long int N, temp;
    vector<Task> *tasks;
    Task tempTask;
	cin >> T;
	while(T--)
	{
		cin >> N;
		tasks = new vector<Task>();
		for (int i = 0; i < N; i++)
		{
			cin >> temp;
			tempTask.task = temp;
			tempTask.ones = 0;
			while(temp)
			{
				if(temp&1) tempTask.ones++;
				temp = temp>>1;
			}
			tasks->push_back(tempTask);
		}
		stable_sort(tasks->begin(), tasks->end(), comparator);
		for (vector<Task>::iterator it = tasks->begin(); it != tasks->end(); it++)
			cout << it->task << " ";
		cout << endl;
	}
    return 0;
}
*/

/*****************************************
Title
	Subset AND
Autor
	Juan Eizmendi
*****************************************/
	/*
#include <math.h>
#include <iostream>
#include <stdint.h>

#define cant 52 //Cantidad carateres
#define len 2 //Longitud password
using namespace std;

bool PowerSetAND(unsigned long int *A, int N, int size, unsigned long int Z)
{

	unsigned long int conbination[size], set_and;
	int counters[size], i;
	
	for (i = 0; i < size; i++)
	{
		conbination[i] = A[i];
		counters[i] = i;
	}

	while(counters[0] <= N-size)
	{
		for (i = 0; i < size; ++i)
			cout << conbination[i] << " ";
		cout << endl;

		for(i = 0; counters[i] == size-1; i++)
			conbination[i] = A[counters[i] = counters[i-1]+1];
		conbination[i] = A[++counters[i]];
	}

	return size == 1 ? false : PowerSetAND(A, N, size-1, Z);
}

void powerSet(char *arr, int arrLen, int pos, int startPos, int length)
{
   if (length == 0)
      printf("%.*s\n", pos, arr);
   else
      for (int i = startPos; i < arrLen; i++)
         powerSet(arr, arrLen, pos+1, i+1, length - 1);
}

int main()
{
	int T, N;
	unsigned long int A[1001], Z;
	cin >> T;

	while(T--)
	{
		cin >> Z >> N;
		for (int j = 0; j < N; j++)
			cin >> A[j];
		cout << (PowerSetAND(A, N, N, Z) ? "Yes" : "No") << endl;
	}
}
*/
/*
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string PowerSetAND(unsigned long int *A, int size, unsigned long int Z)
{
	unsigned long int conbinations = pow(2, size);
	unsigned long int set_and;
	for (int i = 0; i < conbinations; i++)
	{
		set_and = -1;
		for (int j = 0; j < size; j++)
		{
			if(i & (1<<j))
			{
				if(set_and == -1)
					set_and = A[j];
				else
					set_and &= A[j];
			}
		}
		if(set_and&Z == 0)
			break;
	}

	return set_and == 0 ? "YES" : "NO";
}

int main()
{
	int T, N;
	unsigned long int A[1001], Z;
	cin >> T;

	while(T--)
	{
		cin >> Z >> N;
		for (int j = 0; j < N; j++)
			cin >> A[j];
		cout << PowerSetAND(A, N, Z) << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Monk and his Friend
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;	

int main()
{
	unsigned int T, N, K, A[1001], temp, i, max, iMax;

	cin >> T;
	while(T--)
	{
		cin >> N >> K;
		for (i = 0; i < N; i++)
		{
			cin >> temp;
			A[i] = 0;
			while(temp) 
			{
				if(temp&1) A[i]++;
				temp = temp>>1;
			}
		}
		temp = 0;
		while(K--)
		{
			max = A[0];
			iMax = 0;
			for (i = 1; i < N; i++)
			{
				if(A[i] > max){
					max = A[i];
					iMax = i;	
				} 
			}
			temp += max;
			A[iMax] = 0;
		}

		cout << temp << endl;
	}
	return 0;
}
*/
/*****************************************
Title
	Maximum AND 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <cmath>
using namespace std;	

int main()
{
	unsigned int T;
	unsigned long long int A, B, max;

	cin >> T;
	while(T--)
	{
		cin >> A >> B;
		if(B-A > 1)
		{
			if(B&1) max = B-1;
			else max = B-2;
			cout << max << endl;
		}else
		{
			cout << (B&A) << endl;
		}

	}
	return 0;
}
*/
/*****************************************
Title
	Sum of Numbers
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;	
typedef long long int lli;
typedef unsigned long long int ulli;

void Solve()
{
	ulli N, conb;
	lli S, set[15], sum;
	
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> set[i];
	cin >> S;
	conb = pow(2,N);
	while(--conb)
	{
		sum = 0;
		for (int i = 0; i < N; ++i)
			if(conb&(1<<i)) sum += set[i];
		if(sum == S) 
		{
			cout << "YES" << endl;
			return;
		}
	}
	
	cout << "NO" << endl;
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	
	cin >> T;
	while(T--)
	{
		Solve();
	}
	return 0;
}
*/
/*****************************************
Title
	Xsquare And Two Strings
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;	

void Solve(string strA, string strB)
{
	string::iterator i, j;
	int chr = 96;
	while(++chr < 123)
	{
		for (i = strA.begin(); *i != chr && i < strA.end(); ++i);
		for (j = strB.begin(); *j != chr && j < strB.end(); ++j);

		if(j != strB.end() && i != strA.end())
		{
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	string strA, strB;
	
	cin >> T;
	while(T--)
	{
		cin >> strA >> strB;
		Solve(strA, strB);

	}
	return 0;
}
*/

/*
val set = {"A", "B", "C"}

val sets = {}

for item in set:
  for set in sets:
    sets.add(set + item)
  sets.add({item})
sets.add({})
*/
/*****************************************
Title
	Power of TWO
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;	
typedef unsigned long long int ulli;

class PowerSet
{
	vector<ulli> A;
	vector<bool> mask;
	int N;

public:
	PowerSet(int n)
	{
		ulli temp;
		N = n;
		A.resize(N);
		mask.resize(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> temp;
			if(temp != 0) A[i] = temp;
			mask[i] = false;
		}
	}

	bool next()
	{
		vector<bool>::iterator it;
		for (it = mask.begin() ; *it ; ++it) *it = false;
		*it = true;

		if(it - mask.begin() == N) return false;
		return true;
	}

	bool is_pow_of_two()
	{
		ulli _and;
		bool first = true;
		for (vector<bool>::iterator it = mask.begin() ; it != mask.end() ; ++it)
		{
			if(*it)
			{
				if(first) _and = A[it-mask.begin()], first = false;
				else  _and &= A[it-mask.begin()];
			}
		}
		if(__builtin_popcount(_and) == 1)
			return true;
		return false;
	}

	void solve()
	{
		//print_act();
		while(next())
		{
			if(is_pow_of_two())
			{
				cout << "YES" << endl;
				return;
			}
		}
		cout << "NO" << endl;
		return;
	}
	~PowerSet();
	
};

int main()
{
	ios_base::sync_with_stdio(false);
	int T, N;
	PowerSet *powerset;

	cin >> T;
	while(T--)
	{
		cin >> N;
		powerset = new PowerSet(N);
		powerset->solve();
	}
	return 0;
}
*/
/*****************************************
Title
	Subset And
Autor
	Juan Eizmendi
*****************************************/
#include <bits/stdc++.h>
using namespace std;	
typedef unsigned long long int ulli;

class PowerSet
{
	vector<ulli> A;
	vector<bool> mask;
	int N;

public:
	PowerSet(int n)
	{
		N = n;
		A.resize(N);
		mask.resize(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> A[i];
			mask[i] = false;
		}
	}

	void solve(ulli Z)
	{
		int j = 0;
		while(Z >= pow(2, j))
		{
			if(Z&(1<<j))
			{
				for (vector<ulli>::iterator i = A.begin(); i != A.end(); ++i)
				{
					if((*i)&(1<<j)) A.erase(i), --i;
				}
			}
			++j;
		}
		if(A.size() > 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		return;
	}
	~PowerSet();
	
};

int main()
{
	ios_base::sync_with_stdio(false);
	int T, N, Z;
	PowerSet *powerset;

	cin >> T;
	while(T--)
	{
		cin >> Z >> N;
		powerset = new PowerSet(N);
		powerset->solve(Z);
	}
	return 0;
}