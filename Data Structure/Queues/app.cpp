/*****************************************
Title
	Haunted
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>

class Gosth
{
public:
	long long int age, wins;
};

class GosthCompare
{
public:
	bool operator()(Gosth *a, Gosth *b)
	{
		if(a->wins > b->wins) return true;
		if(a->wins < b->wins) return false;
		if(a->age > b->age) return true
		return false;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
    
    priority_queue<Gosth, vector<Gosth>, GosthCompare> queue;
	long long int N, M, n;
	
	Node *root;
	//cin >> N >> M >> n;
	scanf("%lld%lld%lld", &N, &M, &n);
	root = new Node(n);
	root->print();
	
	while(--N)
	{
		scanf("%lld", &n);
		root->addWin(n);
		root->print();
	}
    return 0;
}
*/
/*
#include <cstdio>
#include <algorithm>
using namespace std;

class Node
{
	struct DataNode
	{
		long long int age, wins;	
	};
	Node *previous, *next;
public:
	DataNode *data;

	Node(long long int _age, Node *p = NULL)
	{
		data = new DataNode();
		data->age = _age;
		data->wins = 1;
		previous = p;
		next = NULL;
	}

	void addWin(long long int _age)
	{
		if(data->age == _age)
		{
			data->wins++;
			Order();
			return;
		}
		if(next == NULL)
		{
			next = new Node(_age, this);
			next->Order();
			return;
		}
		next->addWin(_age);
	}

	void Order()
	{
		if(previous == NULL) return;

		if(data->wins > previous->data->wins)
		{
			swap(data, previous->data);
			previous->Order();
		}else if(data->wins == previous->data->wins && data->age > previous->data->age)
		{
			swap(data, previous->data);
			previous->Order();
		}
		return;
	}

	void print()
	{
		printf("%lld %lld\n", data->age, data->wins);
		//cout << data->age << " " << data->wins << endl;
	}

	~Node();
};

int main()
{
	
	long long int N, M, n;
	Node *root;
	//cin >> N >> M >> n;
	scanf("%lld%lld%lld", &N, &M, &n);
	root = new Node(n);
	root->print();
	
	while(--N)
	{
		scanf("%lld", &n);
		root->addWin(n);
		root->print();
	}
    return 0;
}
*/
/*****************************************
Title
	Monk And Champions League 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PriorityQueue
{
	vector<unsigned long long int> values;

public:
	PriorityQueue(unsigned long long int N)
	{
		values.reserve(N);
	}

	void Add(unsigned long long int v)
	{
		vector<unsigned long long int>::iterator it;
		it = values.begin();
		while(*it > v) it++;
		values.insert(it, v);
	}

	void Rest()
	{
		vector<unsigned long long int>::iterator it;
		it = values.begin();
		(*it)--;
		while(*it < *(it+1))
		{
			swap(*it, *(it+1));
			it++;
		}
	}

	unsigned long long int getValue()
	{
		return *(values.begin());
	}

	void printList()
	{
		vector<unsigned long long int>::iterator it;
		it = values.begin();
		cout << "List: ";
		while(it != values.end()) cout << *(it++) << " ";
		cout << endl;
	}
};

int main()
{
	long long int N, M, n;
	PriorityQueue *queueu;
	cin >> N >> M;
	queueu = new PriorityQueue(N);
	while(N--)
	{
		cin >> n;
		queueu->Add(n);
	}
	n = 0;
	while(M--)
	{
		//queueu->printList();
		//cout << "N: " << n << endl;
		n += queueu->getValue();
		queueu->Rest();
	}
	cout << n << endl;
    return 0;
}
*/
/*****************************************
Title
	Monk and Multiplication 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <algorithm> 
using namespace std;

class Maxs
{
	long long int maxs[3];
	bool ready;
public:
	Maxs()
	{
		for (int i = 0; i < 3; ++i)
			maxs[i] = -1;
		ready = false;
	}

	void addNumber(long long int num)
	{
		if(num > maxs[0])
		{
			maxs[2] = maxs[1];
			maxs[1] = maxs[0];
			maxs[0] = num;
		}else if(num > maxs[1])
		{
			maxs[2] = maxs[1];
			maxs[1] = num;
		}else if(num > maxs[2])
		{
			maxs[2] = num;
		}
		if(!ready) checkReady();
	}

	void checkReady()
	{
		if(maxs[0] != -1 && maxs[1] != -1 && maxs[2] != -1) ready = true;
	}

	long long int Multiplication()
	{
		if(!ready) return -1;
		return maxs[0]*maxs[1]*maxs[2];
	}

	~Maxs();
};

int main()
{
	long long int N, n;
	Maxs *maxs = new Maxs();

	cin >> N;
	while(N--)
	{
		cin >> n;
		maxs->addNumber(n);
		cout << maxs->Multiplication() << endl;
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
		int j = i - 1;
		while(s[j-1] > s[j] && j > 0)
		{
			std::swap(s[j], s[j-1]);
			j--;
		}
		return;
	}

	void Dequeue(){
		i--;
		return;
	}

	int Front()
	{
		return i==0 ? -1 : s[i-1];
	}

};

int main()
{
	int T, q, c;
	Queue s;
	s.Init();

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> q;
		s.Enqueue(q);
	}

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> q;
		if(q == 2)
		{
			cout << s.Front() << endl;
		}else{
			cin >> c;
			s.Enqueue(c);
		}
	}
    return 0;
}
*/
/*****************************************
Title
	Basics of Queues
Autor
	Juan Eizmendi
*****************************************/

#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

struct Queue
{
	int s[MAX], front, end, c;

	void Init()
	{
		front = end = c = 0;
		return;
	}

	void Enqueue(int v)
	{
		s[end] = v;
		if (c == MAX)
			return;
		end = (end + 1) % MAX;
		c++;
	}

	void Dequeue()
	{
		if (c == 0)
			return;
		front = (front + 1) % MAX;
		c--;
	}

	int Front()
	{
		return c == 0 ? -1 : s[front];
	}

	int Size()
	{
		return c;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in", "r", stdin);

	int T, n;
	char c;
	Queue s;
	s.Init();

	cin >> T;
	while (T--)
	{
		cin >> c;
		if (c == 'D')
		{
			n = s.Front();
			s.Dequeue();
			cout << n << " " << s.Size() << endl;
		}
		else
		{
			cin >> n;
			s.Enqueue(n);
			cout << s.Size() << endl;
		}
	}
	return 0;
}
