/*****************************************
Title
	The Football Fest 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

class Player
{
	unsigned long long int id;
	Player *back;
public:
	Player(unsigned long long int i, Player *b = NULL)
	{
		id = i;
		back = b;
	}

	Player* Pass(unsigned long long int i)
	{
		return new Player(i, this);
	}

	Player* Back()
	{
		return new Player(back->getId(), this);
	}

	unsigned long long int getId()
	{
		return id;
	}

	~Player();
	
};
int main()
{
	int T;
	unsigned long long int N, id;
	char type;
	Player *player;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N >> id;
		player = new Player(id);
		while(N--)
		{
			cin >> type;
			if(type == 'P')
			{
				cin >> id;
				player = player->Pass(id);
			}else{
				player = player->Back();
			}
		}
		cout << "Player " << player->getId() << endl;
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
