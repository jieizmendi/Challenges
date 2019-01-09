/*****************************************
Title
	Joseph and Array
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef unsigned long int uli;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in","r",stdin);

	uli N, K, n, qua = 1, _qua[100001], arr[100001], counter = 0;

	cin >> N >> K;
	
	for (uli i = 0; i < N; ++i)
	{
		cin >> n;
		qua = (qua*n)%MOD;
	}

	for (uli i = 0; i <= K; ++i)
	{
		arr[i] = qua;
		if(i == K-1)
			_qua[i] = qua;	
		else
			_qua[i] = pow(qua, K-i+1);
	}

	while(arr[K]==qua)
	{
		if(_qua[0] == qua) (++counter)%MOD;

		uli i;
		for (i = 0; arr[i] == 1; ++i)
			arr[i] = qua;
		--arr[i];

		for (int j = i; j >= 0; --j)	
		{
			if(j == K-1)
				_qua[j] = arr[j];	
			else
				_qua[j] = (arr[j]*_qua[j+1])%MOD;
		}
	}
	
	cout << counter << endl;
	return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef unsigned long int uli;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in","r",stdin);

	uli N, K, n, qua = 1, _qua, arr[100001], counter = 0;

	cin >> N >> K;
	
	for (uli i = 0; i < N; ++i)
	{
		cin >> n;
		qua = (qua*n)%MOD;
	}

	for (uli i = 0; i <= K; ++i)
	{
		arr[i] = qua;
	}

	while(arr[K]==qua)
	{
		_qua = 1;
		for (uli i = 0; i < K; ++i)
			_qua = (_qua*arr[i])%MOD;

		if(_qua == qua) (++counter)%MOD;

		uli i;
		for (i = 0; arr[i] == 0; ++i)
			arr[i] = qua;
		--arr[i];
	}
	cout << counter << endl;
	return 0;
}
*/
/*****************************************
Title
	Greedy chairman
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef unsigned long long int uli;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in","r",stdin);

	uli N, Q, l, r, k, w, max=0;
	uli Arr[200005], Ans[200005];
	vector<uli> factorials;

	cin >> N >> Q;

	for (uli i = 1; i <= N; ++i)
	{
		cin >> Arr[i];
		if(Arr[i]>max) max = Arr[i];
	}

	factorials.resize(max+1);
	factorials[0] = 1;
	for (uli i = 1; i <= max; ++i)
		factorials[i] = (i*factorials[i-1])%MOD;

	while(Q--)
	{
		cin >> l >> r >> k;
		w = 1;
		for (uli i = l; i <= r; ++i) Ans[w++] = Arr[i];
		sort(Ans, Ans+w);
		w = k;
		while(Ans[w] == Ans[w+1]) w++;
		cout << ((factorials[w] / ((factorials[k]*factorials[w-k])%MOD))%MOD) << endl;
	}

	return 0;
}
*/
/*****************************************
Title
	Joseph and Tree
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int uli;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in","r",stdin);

	uli N, a, b, w, Q;
	pair<uli,uli> Adj[100005];
	uli ans[100005];

	cin >> N;

	for (uli i = 0; i < N; ++i)
	{
		Adj[i].first = 0;
		Adj[i].second = 0;
	}

	for (uli i = 1; i < N; ++i)
	{
		cin >> a >> b >> w;
		if(a>b) swap(a,b);
		Adj[b].first = a;
		Adj[b].second = Adj[a].second + w;
	}

	cin >> Q;

	while(Q--)
	{
		cin >> a >> b;
		w = 0;
		for (uli i = 1; i <= N; ++i)
		{
			uli j = i;
			while(Adj[j].first != a && Adj[j].first != 0)
			{
				j = Adj[j].first;
			}
			if(Adj[j].first == a)
			{
				ans[w++] = Adj[i].second - Adj[a].second;
			}
		}
		sort(ans, ans+w);
		if(b>w) cout << "-1" << endl;
		else cout << ans[b-1] << endl;
	}

	return 0;
}
*/
/****************************************
Title
	Joseph and String
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;

//freopen("out","w",stdout);
typedef unsigned long int uli;

uli ocurrs(const std::string& str, const std::string& sub)
{
	if (sub.length() == 0) return 0;
	uli count = 0;
    size_t nPos = str.find(sub, 0); // fist occurrence
    while(nPos != string::npos)
    {
        count++;
        nPos = str.find(sub, nPos+1);
    }
	return count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in","r",stdin);

	string str, sub;
	uli N, Q, v, l, r, F, max;
	vector< pair<string, uli> > Fs;

	cin >> N >> str >> Q;

	for (uli i = 0; i < Q; ++i)
	{
		cin >> v >> l >> r;
		max = 0;
		for (uli j = l; j <= r; ++j)
		{
			sub = str.substr(v-1, j);
			F = 0;
			for (int k = 0; k < Fs.size(); ++k)
			{
				if(sub == Fs[k].first)
				{
					F = Fs[k].second;
					break;
				}
			}
			if (F == 0)
			{
				F = ocurrs(str, sub) * j;
				Fs.push_back(pair<string, uli>(sub, F));
			}
			if(F>max) max = F;
		}
		cout << max << endl;
	}
	return 0;
}
*/
/*****************************************
Title
	 Joseph and Pizzeria 
Autor
	Juan Eizmendi
*****************************************/

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long int uli;

struct Client
{
	long double x, y, t, w;
	uli i;
};

bool comparator(Client a, Client b)
{
	return a.t < b.t;
}

string concat(string s, uli k)
{
	stringstream str;
	str << s << k;
	return str.str();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in","r",stdin);

	vector<string> ans;
	uli N, K, k;
	long double V, time, move_time;
	vector<Client> clients;
	Client temp, pizzeria, me;

	cin >> N >> K >> V;

	for (uli i = 0; i < N; ++i)
	{
		cin >> temp.x >> temp.y >> temp.t >> temp.w;
		temp.i = i+1;
		clients.push_back(temp);	
	}

	sort(clients.begin(), clients.end(), comparator);
	ans.push_back(concat("PICK ", K));
	time = 0;
	pizzeria.x = 0;
	pizzeria.y = 0;
	me.x = 0;
	me.y = 0;
	k = K;

	for (vector<Client>::iterator it = clients.begin(); it != clients.end(); ++it)
	{
		if(k == 0)
		{
			ans.push_back("GO 0");
			ans.push_back(concat("PICK ", K));
			k = K;
			move_time = sqrt(pow(pizzeria.x-me.x, 2) + pow(pizzeria.y-me.y, 2))/V;
			time += move_time;
			me = pizzeria;
		}

		move_time = sqrt(pow(it->x-me.x, 2) + pow(it->y-me.y, 2))/V;
		if(time + move_time <= it->t)
		{
			ans.push_back(concat("GO ", it->i));
			ans.push_back("SELL");
			k--;
			time += move_time;
			me = *it;
		}
	}

	if(ans[ans.size()-1][0] == 'P') ans.pop_back();
	else ans.push_back("GO 0");
	cout << ans.size() << endl;
	for (vector<string>::iterator i = ans.begin(); i != ans.end(); ++i)
	{
		cout << *i << endl;
	}

	return 0;
}
