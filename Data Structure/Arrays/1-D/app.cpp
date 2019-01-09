/*****************************************
Title
	Micro and Array Update
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

	long long int T, N, K, i, a, aa;

	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		a = K;
		for (i = 0; i < N; i++)
		{
			cin >> aa;
			if (a > aa)
				a = aa;
		}

		cout << K - a << endl;
	}

	return 0;
}
*/
/*****************************************
Title
	 Monk and Power of Time
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <algorithm> 
using namespace std;
struct Queue
{
	int s[1000000], i;

	void Init(){
		i = 0;
		return;
	}

	void Enqueue(int v){
		s[i++] = v;
		return;
	}

	void Dequeue(){
		i--;
		int j = 0;
		while(j < i)
		{
			std::swap(s[j], s[j+1]);
			j++;
		}
		return;
	}

	int Front()
	{
		return i==0 ? -1 : s[0];
	}

	void Rotate()
	{
		Enqueue(Front());
		Dequeue();
	}
};

int main()
{
	int N, n, c;
	Queue s;
	s.Init();

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		s.Enqueue(n);
	}
	c = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> n;
		while(s.Front() != n) 
		{
			s.Rotate();
			c++;
		}
		s.Dequeue();
	}

	cout << c+N << endl;
    return 0;
}
*/
/*****************************************
Title
	Speed 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;
int main()
{
	int T;
	long int N;
	long long int n, c, max;
	cin >> T;
	while(T--)
	{
		c = 1;
		cin >> N;
		cin >> max;
		N--;
		while(N--)
		{
			cin >> n;
			if(n < max) 
			{
				c++;
				max = n;
			}
		}
		cout << c << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Two Arrays and Minimum
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

int main()
{
	unsigned long long int a, b, c, N, out, ab, abc, ac, Aabc, Aab, Aac, Babc, Bab, Bac, bc, Bbc;
	unsigned long long int i, act[2], next[2]; 
	unsigned long long int minsA[2], indexsA[2];
	unsigned long long int minsB[2], indexsB[2];
	for (int j = 0; j < 2; j++)
	{
		minsA[j] = 1000000007;
		indexsA[j] = 0;
		minsB[j] = 1000000007;
		indexsB[j] = 0;
	}
	out = 1000000007;

	cin >> a >> b >> c >> N;

	act[0] = (a*c)%1000000007;
	act[1] = (b*c)%1000000007;
	minsA[0] = act[0];
	minsB[0] = act[1];

	for (i = 1; i < N; i++)
	{
		ab = (a*b)%1000000007;
		ac = (a*c)%1000000007;
		bc = (b*c)%1000000007;
		abc = (ac*b)%1000000007;
		Aabc = (act[0]*abc)%1000000007;
		Aab = (act[0]*ab)%1000000007;
		Aac = (act[0]*ac)%1000000007;
		Babc = (act[1]*abc)%1000000007;
		Bab = (act[1]*ab)%1000000007;
		Bbc = (act[1]*bc)%1000000007;
		next[0] = (((Aabc + Aab)%1000000007) + Aac)%1000000007;
		next[1] = (((Babc + Bab)%1000000007) + Bbc)%1000000007;

		if(next[0] < minsA[1])
		{
			if(next[0] < minsA[0])
			{
				minsA[1] = minsA[0];
				indexsA[1] = indexsA[0];
				minsA[0] = next[0];
				indexsA[0] = i;
			}else
			{
				minsA[1] = next[0];
				indexsA[1] = i;
			}
		}
		if(next[1] < minsB[1])
		{
			if(next[1] < minsB[0])
			{
				minsB[1] = minsB[0];
				indexsB[1] = indexsB[0];
				minsB[0] = next[1];
				indexsB[0] = i;
			}else
			{
				minsB[1] = next[1];
				indexsB[1] = i;
			}
		}
		act[0] = next[0];
		act[1] = next[1];
	}
	
	for (int j = 0; j < 2; j++)
	{
		for (int k = 0; k < 2; k++)
		{
			if(indexsA[j] != indexsB[k])
			{
				if((minsA[j] + minsB[k]) < out)
				{
				 	out = minsA[j] + minsB[k];
				}
			}
		}
	}
	cout << out << endl;
    return 0;
}
*/
/*****************************************
Title
	 Litte Jhool and world tour 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class ISet
{
	unsigned long long int lower, upper;
public:
	ISet(unsigned long long int l, unsigned long long int u)
	{
		lower = l;
		upper = u;
	}

	unsigned long long int getLower()
	{
		return lower;
	}
	unsigned long long int getUpper()
	{
		return upper;
	}
	void setLower(unsigned long long int v)
	{
		lower = v;
	}
	void setUpper(unsigned long long int v)
	{
		upper = v;
	}
};

class ISets
{
	vector<ISet> _set;
public:
	ISets(ISet set)
	{
		_set.push_back(set); 
	}

	int Out()
	{
		return _set.size();
	}

	void addSet(ISet set)
	{
		vector<ISet> A, B;
		A = unionSet(set);

		cout << "A: " << endl;
		for (vector<ISet>::iterator it = A.begin(); it != A.end(); it++)
			cout << "\t[" << it->getLower() << ", " << it->getUpper() << "] ";
		cout << endl;
		
		B = intersectionSet(set);
		
		cout << "B: " << endl;
		for (vector<ISet>::iterator it = B.begin(); it != B.end(); it++)
			cout << "\t[" << it->getLower() << ", " << it->getUpper() << "] ";
		cout << endl;
		
		_set = differenceSet(A, B);

		cout << "SET: " << endl;
		for (vector<ISet>::iterator it = _set.begin(); it != _set.end(); it++)
			cout << "\t[" << it->getLower() << ", " << it->getUpper() << "] ";
		cout << endl;
	}

	vector<ISet> unionSet(ISet set)
	{
		vector<ISet> internal = _set;
		internal.push_back(set);
		for (vector<ISet>::iterator it = internal.begin(); it != internal.end()-1; it++)
		{
			for (vector<ISet>::iterator _it = it+1; _it != internal.end(); _it++)
			{
				if(it->getLower() <= _it->getLower() && it->getUpper() >= _it->getUpper()) //in
				{
					internal.erase(_it);
					it = internal.begin()-1;
					break;
				}else if(it->getLower() <= _it->getLower() && it->getUpper() >= _it->getLower() && it->getUpper() < _it->getUpper()) //interA
				{
					it->setUpper(_it->getUpper());
					internal.erase(_it);
					it = internal.begin()-1;
					break;
				}else if(it->getLower() >= _it->getLower() && it->getLower() <= _it->getUpper() && it->getUpper() > _it->getUpper()) //interB
				{
					it->setLower(_it->getLower());
					internal.erase(_it);
					it = internal.begin()-1;
					break;
				}
			}
		}
		return internal;		
	}

	vector<ISet> intersectionSet(ISet set)
	{
		vector<ISet> internal = _set;
		internal.push_back(set);
		for (vector<ISet>::iterator it = internal.begin(); it != internal.end()-1; it++)
		{
			for (vector<ISet>::iterator _it = it+1; _it != internal.end(); _it++)
			{
				if(it->getLower() <= _it->getLower() && it->getUpper() >= _it->getUpper()) //in
				{
					internal.erase(it);
					it = internal.begin()-1;
					break;
				}else if(it->getLower() <= _it->getLower() && it->getUpper() >= _it->getLower() && it->getUpper() < _it->getUpper()) //interA
				{
					it->setLower(_it->getLower());
					internal.erase(_it);
					it = internal.begin()-1;
					break;
				}else if(it->getLower() >= _it->getLower() && it->getLower() <= _it->getUpper() && it->getUpper() > _it->getUpper()) //interB
				{
					it->setUpper(_it->getUpper());
					internal.erase(_it);
					it = internal.begin()-1;
					break;
				}
			}
		}
		return internal;	
	}

	vector<ISet> differenceSet(vector<ISet> setA, vector<ISet> setB)
	{
		for (vector<ISet>::iterator itA = setA.begin(); itA != setA.end(); itA++)
		{
			for (vector<ISet>::iterator itB = setB.begin(); itB != setB.end(); itB++)
			{
				if(itA->getLower() >= itB->getLower() && itA->getUpper() <= itB->getUpper()) //A
				{
					setA.erase(itA);
					itA = setA.begin()-1;
					break;
				}else if(itA->getLower() < itB->getLower() && itA->getUpper() > itB->getUpper()) //B
				{
					setA.push_back(ISet(itB->getLower()+1, itA->getUpper()));
					itA->setUpper(itB->getLower()-1);
					itA = setA.begin()-1;
					break;
				}else if(itA->getLower() <= itB->getUpper() && itA->getUpper() > itB->getUpper()) //C
				{
					itA->setLower(itB->getUpper()+1);
					itA = setA.begin()-1;
					break;
				}else if(itA->getLower() < itB->getLower() && itA->getUpper() >= itB->getLower()) //D
				{
					itA->setUpper(itB->getLower()-1);
					itA = setA.begin()-1;
					break;
				}
			}
		}
		return setA;
	}
};

int main()
{
	int T;
	unsigned long long int N, M, x, y, i, j;
	ISets *sets;
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		cin >> x >> y;
		x = x%N;
		y = y%N;
		if(x < y)
		{
			sets = new ISets(ISet(x, y));
		}
		else if(x > y)
		{
			sets = new ISets(ISet(x, N-1));
			sets->addSet(ISet(0, y));
		}
		else
		{
			sets = new ISets(ISet(0, N-1));
		}
		M--;
		while(M--)
		{
			cin >> x >> y;
			x = x%N;
			y = y%N;
			if(x < y)
			{
				sets->addSet(ISet(x, y));
			}
			else if(x > y)
			{
				sets->addSet(ISet(x, N-1));
				sets->addSet(ISet(0, y));
			}
			else
			{
				sets->addSet(ISet(0, N-1));
			}
		}
		cout << sets->Out() << endl;
	}
	return 0;
}
*/
/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;
	unsigned long long int N, M, x, y, i, j;
	vector<int> vec;
	bool flag;
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		vec.clear();
		vec.resize(N);
		for (i = 0; i < M; i++)
		{
			cin >> x >> y;
			x = x%N;
			y = y%N;
			if(x < y)
			{
				for (j = x; j <= y; j++)
					if(vec[j] < 2)
						vec[j]++;

			}else if(x > y)
			{
				for (j = x; j < N; j++)
					if(vec[j] < 2)
						vec[j]++;
				for (j = 0; j <= y; j++)
					if(vec[j] < 2)
						vec[j]++;
			}else
			{
				for (j = 0; j < N; j++)
					if(vec[j] < 2)
						vec[j]++;
			}
		}
		flag = false;
		for(i = 0; i < N; i++)
			if(vec[i] < 2)
			{
				flag = true;
				break;
			}
		cout << (flag ? "YES" : "NO") << endl;
	}
    return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int T;
	unsigned long long int N, M, x, y, i, j;
	vector< pair<unsigned long long int, unsigned long long int> > vec;
	vector< pair<unsigned long long int, unsigned long long int> > intersecciones;
	bool num;
	cin >> T;
	while(T--)
	{
		cin >> N >> M;
		vec.clear();
		vec.resize(M);
		j = 0;
		for (i = 0; i < M; i++)
		{
			cin >> x >> y;
			x = x%N;
			y = y%N;
			if(x < y)
			{
				vec[j].first = x;
				vec[j].second = y;
			}else (y < x)
			{
				vec[j].first = 0;
				vec[j].second = y;
				j++;
				vec[j].first = x;
				vec[j].second = N-1;
			}else
			{
				vec[j].first = 0;
				vec[j].second = N-1;
			}
			j++;
		}
		x = vec[i].first;
		y = 0;
		for (i = 1; i < j; i++)
		{
			if(vec[i].first)

			cin >> x >> y;
			x = x%N;
			y = y%N;
			if(x < y)
			{
				vec[j].first = x;
				vec[j].second = y;
			}else (y < x)
			{
				vec[j].first = 0;
				vec[j].second = y;
				j++;
				vec[j].first = x;
				vec[j].second = N-1;
			}else
			{
				vec[j].first = 0;
				vec[j].second = N-1;
			}
		}
		for(x = 0; x < N; x++)
		{
			num = false;
			for(y = 0; y < M; y++)	
			{
				if(vec[y].first < vec[y].second)
				{
					if(vec[y].first <= x && vec[y].second >= x)
					{
						if(num)
						{
							num = false;
							break;
						}
						else num = true;
					}
				}else if(vec[y].first > vec[y].second)
				{
					if(vec[y].first <= x || vec[y].second >= x)
					{
						if(num)
						{
							num = false;
							break;
						}
						else num = true;
					}
				}else
				{
					if(num)
					{
						num = false;
						break;
					}
					else num = true;
				}
			}
			if(num) break;
		}
		cout << (num ? "YES" : "NO") << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Modify Sequence 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

int main()
{
	int N, n[10001], c, s;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> c;
		n[i] = c;
	}

	do{
		c = 0;
		for (int i = 0; i < N-1; i++)
		{
			if(n[i] != 0 && n[i+1] != 0)
				c++;
			if(n[i] > n[i+1])
			{
				n[i] -= n[i+1];
				n[i+1] = 0;
			}else
			{
				n[i+1] -= n[i];
				n[i] = 0;
			}
		}
	}while(c != 0);
	
	c = 0;
	for (int i = 0; i < N; i++)
	{
		if(n[i] != 0)
		{
			c++;
			break;
		}
	}

	if(c != 0)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

    return 0;
}
*/
/*****************************************
Title
	Nice Arches 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, c = 0, a;
	string str;
	cin >> N;
	while(N--)
	{
		cin >> str;
		a = 0;
		if(str.length()%2 != 1)
		{
			for (int i = 0; i < str.length(); i++)
				if(str[i] == 'A')
					a++;

			if(a%2 != 1)
			{
				if(str.length() > 2)
				{
					do
					{
						a = 0;
						for (int i = 0; i < str.length()-1; i++){
							if(str[i] == str[i+1]){
								str.erase(i, 2);
								a++;
								if(str.length() == 2) break;
							}
						}
					}while(a != 0 && str.length() != 2);
				}

				if(str.length() == 2)
					if(str[0] == str[1])
						c++;
			}
		}
	}
	cout << c << endl;
    return 0;
}
*/
/*****************************************
Title
	The Amazing Race
Autor
	Juan Eizmendi
*****************************************/
/*
#include <cstdio>
#include <vector>
#define gc getchar_unlocked
using namespace std;
void scan_integer( long long int &x )
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for( ; ((c<48 || c>57) && c != '-'); c = gc() );
    if( c=='-' ) {
        neg=1;
        c=gc();
    }
    for( ;c>47 && c<58; c = gc() ) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    if( neg )
        x=-x;
} 
 
int main()
{
    int T;
    bool first = true;
	long long int N, temp, max, i;
	vector<long long int> vec, _vec;
	vector<long long int>::iterator it_max, _it, __it , it;
	scanf("%d", &T);
	while(T--)
	{
		scan_integer(N);
		vec.resize(N);
		for (i = 0; i < N; i++)
		{
			scan_integer(vec[i]);
		}
 		if(!first) if(vec == _vec) goto answer;
 		
		it_max = vec.begin();
		max = 0;
		for (it = vec.begin(); it != vec.end(); it++)
		{
			_it = it;
			__it = it;
			while(++_it != vec.end() && *it > *_it);
			while(--__it >= vec.begin() && *it > *__it);
			
			if(max < (_it-__it-1)*(it-vec.begin()+1))
			{
				it_max = it;
				max = (_it-__it-1)*(it-vec.begin()+1);
			}
		}
	answer:
		printf("%lld\n", (long long int)(it_max-vec.begin()+1));
		_vec = vec;
	}
    return 0;
}
*/
/*****************************************
Title
	I Demand Trial by Combat
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
#define in_v(vec) vec.begin(), vec.end()
using namespace std;

int scan_int()
{
    register int c = getchar_unlocked();
    int x = 0;
    for( ;c<48 || c>57; c = getchar_unlocked() );
    for( ;c>47 && c<58; c = getchar_unlocked() ) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    return x;
} 

int main()
{
	int T, L, hours;
	bool back, actual;
	vector<bool> a;

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &L);
		scanf("%d", &hours);
		a.resize(L);
		generate(in_v(a), scan_int);
		
		while(hours--)
		{
			vector<bool>::iterator it = a.begin();
			back = *it;
			*it = *(it+1);

			while(++it != a.end()-1)
			{
				actual = *it;
				*it = back & (*(it+1));
				back = actual;
			}

			*it = back;
		}
		std::copy(in_v(a), ostream_iterator<int>(std::cout, " "));
		printf("\n");
	}
    return 0;
}
*/
/*
#include <cstdio>
using namespace std;

inline void fastRead_int(bool &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-') {
    	neg = 1;
    	c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked()) {
    	x = (bool)((x<<1) + (x<<3) + c - 48);
    }

    if(neg)
    	x = -x;
}

int main()
{
	int T, L, hours, i, idx, _idx;
	bool vec[2][101];

	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &L);
		scanf("%d", &hours);
		i = 0;
		while(i < L)
			fastRead_int(vec[0][i++]);
		
		idx = 0;
		_idx = 1;
		while(hours--)
		{
			
			vec[_idx][0] = vec[idx][1];
	
			i = 0;
			while(i++ < L-1)
				vec[_idx][i] = vec[idx][i-1] & vec[idx][i+1];

			vec[_idx][L-1] = vec[idx][L-2];

			i = idx;
			idx = _idx;
			_idx = i;
		}
		i = 0;
		while(i < L)
			printf("%d ", vec[idx][i++]);
		printf("\n");
	}
    return 0;
}
*/
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T, L, hours;
	bool temp;
	vector<bool> *vec, *_vec;
	vector<bool>::iterator it, _it;
	cin >> T;
	while(T--)
	{
		vec = new vector<bool>();
		cin >> L >> hours;
		while(L--)
		{
			cin >> temp;
			vec->push_back(temp);
		}
		while(hours--)
		{
			_vec = new vector<bool>();
			
			it = vec->begin()+1;
			if( *(it) )
				_vec->push_back(true);
			else
				_vec->push_back(false);

			for (it = vec->begin()+1; it != vec->end()-1; it++)
			{
				if( *(it-1) && *(it+1) )
					_vec->push_back(true);
				else
					_vec->push_back(false);
			}

			it = vec->end()-1;
			if( *(it-1) )
				_vec->push_back(true);
			else
				_vec->push_back(false);

			*vec = *_vec;
		}

		for (it = vec->begin(); it != vec->end(); it++)
			cout << *it << " ";
		cout << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Mark The Answer 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

int main()
{
	long long int N, X, skiped=0, ok=0, n;
	cin >> N >> X;
	while(N--)
	{
		cin >> n;
		if(n > X) skiped++;
		else if(skiped < 2) ok++;
		else break;
	}
	cout << ok << endl;
    return 0;
}
*/
/*****************************************
Title
	Biased Chandan 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

int main()
{
	int N, sum=0, temp;
	int vec[10000];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vec[i] = temp;
	}
	for (int i = N-1; i >= 0; i--)
	{
		if(vec[i] == 0)
		{
			for (int j = i-1; j >= 0; j--)
			{
				if(vec[j] != 0 && vec[j] != -1)
				{
					vec[j] = -1;
					break;
				}
			}
		}else if(vec[i] != -1){
			sum += vec[i];
		}
	}
	cout << sum << endl;
    return 0;
}
*/
/*****************************************
Title
	Monk's Love for Food
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

struct Stack
{
	int s[10000], i;
	void Init(){
		i = 0;
		return;
	}

	void Push(int v){
		s[i++] = v;
		return;
	}

	int Pop(){
		return Empty() ? -1 : s[--i];
	}

	bool Empty()
	{
		return i==0 ? true : false;
	}
};

int main()
{
	int T, q, c;
	Stack s;
	s.Init();
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> q;
		if(q == 1)
		{
			c = s.Pop();
			if(c == -1)
				cout << "No Food" << endl;
			else
				cout << c << endl;
		}else{
			cin >> c;
			s.Push(c);
		}
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
using namespace std;

int main()
{
	int N;
	cin >> N;
	int *n = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> n[i];
	}
	for (int i = N-1; i >= 0; i--)
	{
		cout << n[i] << endl;
	}
    return 0;
}
*/