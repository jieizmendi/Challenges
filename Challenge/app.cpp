/*****************************************
Title
    Practice
Autor
    Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int T, N;
    cin >> T;
    while(T--)
    {
    	cin >> N;
    	for (int i = 1; i <= N; i++)
    	{
    		if(i%3 == 0)
    		{
    			if(i%5 == 0)
    			{
    				cout << "FizzBuzz" << endl;
    			}else{
    				cout << "Fizz" << endl;
    			}
    		}else if(i%5 == 0)
    		{
    			cout << "Buzz" << endl;
    		}else{
    			cout << i << endl;
    		}
    	}
    }
}
*/
/*****************************************
Title
    July Circuit - Little Shino and Coins
Autor
    Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

bool addLetter(char *A, char chr, int *k)
{
	bool flag = true;
	for (int i = 0; i < *k; i++)
	{
		if(A[i] == chr)
		{
			flag = false;
			break;
		}
	}
	if(flag)
	{
		A[*k] = chr;
		(*k)++;
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	string str;
	unsigned int K, count=0, diffs;
	char letters[28];
    cin >> K >> str;

    for (int i = 0; i < str.length(); i++)
    {
    	for (int h = 0; h < K; h++) letters[h] = '\0';

    	int k = 0, j = i;
    	while(k < K && j != str.length())
    	{
    		addLetter(letters, str[j], &k);
    		j++;
    	}
    	if(k==K)
    	{
	    	j--;
	    	while(!addLetter(letters, str[j], &k) && j!= str.length())
			{
	    		count++;
	    		j++;
	    	}
	    }
    }
    cout << count << endl;
    return 0;
}
*/
/*****************************************
Title
    July Circuit - Little Shino and the tournament
Autor
    Juan Eizmendi
*****************************************/
#include <iostream>
#include <cstdio>
#include <vector>
#define gc getchar_unlocked
using namespace std;
typedef long long int uli;


void scan_integer( uli &x )
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
class FF
{
public:
	uli n, q, k;
	FF(uli _n, uli _k)
	{
		n = _n;
		k = _k;
		q = 0;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	uli N, Q, q;
	vector<uli> Qs;
	vector< FF* > Ns;
    cin >> N >> Q;

    Qs.resize(N);

    for (uli i = 0; i < N; i++)
    {
    	scan_integer(q);
    	Ns.push_back(new FF(i, q));
    	Qs[i] = 0;
    }


    while(Ns.size() > 1)
    {
    	uli i = 0;
    	while(i < Ns.size()-1)
    	{
    		Qs[Ns[i]->n]++;
    		Qs[Ns[i+1]->n]++;
    		if(Ns[i]->k > Ns[i+1]->k) Ns.erase(Ns.begin()+i+1);
    		else Ns.erase(Ns.begin()+i);
    		i++;
    	}
    }

    for (uli i = 0; i < Q; i++)
    {
    	scan_integer(q);
    	cout << Qs[q-1] << endl;
    }
    return 0;
}
/*
#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long int uli;

class Fighter
{
public:
	uli _k, _q;
	bool f;
	Fighter(uli k)
	{
		_q = 0;
		f = true;
		_k = k;
	}
	~Fighter();
	
};
int main()
{
	ios_base::sync_with_stdio(false);
	uli count, N, Q, q;
	bool flag = true;
	vector< Fighter* > Ns;
	vector< Fighter* >::iterator it1, it2;
    cin >> N >> Q;
    for (uli i = 0; i < N; i++)
    {
    	cin >> q;
    	Ns.push_back(new Fighter(q));
    }

    while(flag)
    {
    	flag = false;
    	it1 = it2 = Ns.begin();
    	while(it2 < Ns.end())
    	{
	    	while(it1 < Ns.end()-1)
	    	{
	    		if((*it1)->f) break;
	    		it1++;
	    	}
	    	it2 = it1+1;
	    	while(it2 < Ns.end())
	    	{
	    		if((*it2)->f) break;
	    		it2++;
	    	}
	    	if(it2 < Ns.end())
			{
				(*it1)->_q++;
				(*it2)->_q++;
	    		if((*it1)->_k > (*it2)->_k) (*it2)->f = false;
	    		else (*it1)->f = false;
	    		flag = true;
	    	}
	    	it1+=2;
	    }
    }
    for (uli i = 0; i < Q; i++)
    {
    	cin >> q;
    	cout << Ns[q-1]->_q << endl;
    }
    return 0;
}
*/