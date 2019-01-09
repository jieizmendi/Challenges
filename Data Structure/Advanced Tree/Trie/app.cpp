/*****************************************
Title
	Tutorial
Autor
	Juan Eizmendi
*****************************************/
#include <vector>
#include <cstdio>
using namespace std;

class Trie
{
	int weight;
	char chr;
	vector<Trie> childrens;

public:
	Trie(char c)
	{
		chr = c;
		weight = 0;
	}
	
	Trie(char c, int w)
	{
		chr = c;
		weight = w;
	}
	
	char getChar()
	{
		return chr;
	}
	int getWeight()
	{
		return weight;
	}
	void setWeight(int w)
	{
		weight = w;
	}

	void setWord(char *str, int w)
	{
		for (vector<Trie>::iterator it = childrens.begin() ; it != childrens.end(); it++)
		{
            if(str[0] == it->getChar())
            {
            	if(str[0] == '\0')
				{
					if( it->getWeight() < w)
						it->setWeight(w);
					return;
				}
            	return it->setWord(&str[1], w);
            }
		}

		if(str[0] == '\0')
		{
			childrens.push_back(Trie(str[0], w));
			return;
		}else{
			childrens.push_back(Trie(str[0]));
			return childrens.back().setWord(&str[1], w);	
		}
	}

	Trie* findLastChild(char *str)
	{
		for (vector<Trie>::iterator it = childrens.begin() ; it != childrens.end(); it++)
		{
            if(str[0] == it->getChar())
            {
            	if(str[1] == '\0')
				{
					return &(*it);
				}
            	return it->findLastChild(&str[1]);
            }
		}
		return NULL;
	}

	void findWeigth(int *w)
	{
		for (vector<Trie>::iterator it = childrens.begin() ; it != childrens.end(); it++)
		{
			if(it->getWeight() > *w)
			{
				*w = it->getWeight();
			}
        	it->findWeigth(w);
		}
	}

	int findMaxWeigth(char *str)
	{
		Trie *root = findLastChild(str);
		if(root == NULL)
			return -1;
		int c = root->getWeight();
		root->findWeigth(&c);
		return c;
	}
};

int main()
{
	Trie *tree = new Trie('$');
	int N, Q, w, last_w;
	char str[10000], last_str[10000];
	scanf("%d%d", &N, &Q);
	while(N--)
	{
		scanf("%s%d", str, &w);
		tree->setWord(str, w);
	}
	while(Q--)
	{
		scanf("%s", str);
		w = 0;
		N = 0;
		while(str[w] != '\0') {
			if(str[w] != last_str[w]){
				N = -1;
			}
			last_str[w] = str[w++];
		}
		if(N == -1)
		{
			last_w = tree->findMaxWeigth(str);
		}
		printf("%d\n", last_w);
	}

    return 0;
}
  

  
/* std=c++11
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Trie
{
	int weight;
	char chr;
	vector<Trie*> childrens;

public:
	Trie(char c)
	{
		chr = c;
	}
	
	Trie(char c, int w)
	{
		weight = w;
	}
	
	char getChar()
	{
		return chr;
	}
	int getWeight()
	{
		return weight;
	}
	void setWeight(int w)
	{
		weight = w;
	}

	void setWord(string s, int w)
	{
		bool set = true;
		for (auto &it : childrens)
		{
            if(s[0] == it->getChar())
            {
            	set = false;
            	if(s.size() < 1 && it->getWeight() > w)
				{
					it->setWeight(w);
					return;
				}
            	it->setWord(s.substr(1, s.size()-1), w);
            }
		}
		if(set)
		{
			childrens.push_back(new Trie(s[0]));
		
			if(s.size() < 1)
			{
				childrens.back()->setWeight(w);
				return;
			}

			childrens.back()->setWord(s.substr(1, s.size()-1), w);
		}
	}

	Trie* findLastChild(string s)
	{
		for (auto &it : childrens)
		{
            if(s[0] == it->getChar())
            {
            	//cout << it->getChar();
            	if(s.size() == 1)
				{
					return it;
				}
            	return it->findLastChild(s.substr(1, s.size()-1));
            }
		}
		return NULL;
	}

	void findWeigth(int *w)
	{
		for (auto &it : childrens)
		{
			if(it->getWeight() > *w)
			{
				*w = it->getWeight();
			}
        	it->findWeigth(w);
		}
	}

	int findMaxWeigth(string s)
	{
		Trie *root = findLastChild(s);
		if(root == NULL)
			return -1;
		int c = root->getWeight();
		root->findWeigth(&c);
		return c;
	}
};

int main()
{
	Trie *tree = new Trie('$');
	int N, Q, w;
	string str;
	cin >> N >> Q;
	while(N--)
	{
		cin >> str >> w;
		tree->setWord(str, w);
	}
	while(Q--)
	{
		cin >> str;
		cout << tree->findMaxWeigth(str) << endl;	
	}
    return 0;
}
*/