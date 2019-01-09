/*****************************************
Title
	Tutorial
Autor
	Juan Eizmendi
*****************************************/

/*****************************************
Title
	The SILLY SNAIL
Autor
	Juan Eizmendi
*****************************************/
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long int ULI;

struct Node
{
	ULI data, l, r;
	//vector< Node* >::iterator l, r;

	Node(ULI v)
	{
		data = v;
		l = r = 0;
	}
};

class Tree
{
	vector< Node* > tree;
	
public:
	Tree(ULI v)
	{
		tree.push_back(new Node(v));
	}

	void insert(ULI x, ULI y, ULI z)
	{
		vector< Node* >::iterator it = tree.begin();
		
		while((*it)->data != x && it != tree.end()) it++;
		
		if(it == tree.end()) return;

		Node* node = *it;
		
		if(y != 0)
		{
			tree.push_back(new Node(y));
			node->l = tree.end()-tree.begin()-1;
		}

		if(z != 0)
		{
			tree.push_back(new Node(z));
			node->r = tree.end()-tree.begin()-1;
		}
	}
	
	void printPreOrder(vector< Node* >::iterator it)
	{
		cout << (*it)->data << " ";
		if((*it)->l != 0)
			printPreOrder((*it)->l + tree.begin());
		if((*it)->r != 0)
			printPreOrder((*it)->r + tree.begin());
	}

	void print()
	{
		printPreOrder(tree.begin());
		cout << endl;
	}

	~Tree()
	{
		tree.clear();
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
    Tree *tree;
	
    int T;
    ULI N, x, y, z;
    cin >> T;
    while(T--)
    {
    	cin >> N;
    	tree = new Tree(1);
    	while(N--)
    	{
    		cin >> x >> y >> z;
    		tree->insert(x, y, z);
    	}
    	tree->print();
    	
    	delete tree;
    }
    return 0;
}
	/*
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long int ULI;

struct Node
{
	ULI data;
	Node *l, *r;

	Node(ULI v)
	{
		data = v;
		l = r = NULL;
	}
};

class BinaryTree
{
	Node *root;
	
public:
	BinaryTree(ULI v)
	{
		root = new Node(v);
	}

	void insert(ULI x, ULI y, ULI z)
	{
		Node *n = search(x); 
		if(!n) return;
		if(y!=0) n->l = new Node(y);
		if(z!=0) n->r = new Node(z);
	}

	Node* search(ULI v)
	{
		if(root == NULL) return NULL;
		vector< Node* > stackNodes;
		Node* current;
		stackNodes.push_back(root);
		while(stackNodes.size()!=0)
		{
			current = stackNodes.back();
			stackNodes.pop_back();
			if(current->data == v) break;
			if(current->l) stackNodes.push_back(current->l);
			if(current->r) stackNodes.push_back(current->r);
			current = NULL;
		}
		return current;
	}

	void printPreOrder(Node *n)
	{
		cout << n->data << " ";
		if(n->l != NULL) printPreOrder(n->l);
		if(n->r != NULL) printPreOrder(n->r);
	}

	void print()
	{
		printPreOrder(root);
		cout << endl;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    BinaryTree *tree;
	
    int T;
    ULI N, x, y, z;
    cin >> T;
    while(T--)
    {
    	cin >> N;
    	tree = new BinaryTree(1);
    	while(N--)
    	{
    		cin >> x >> y >> z;
    		tree->insert(x, y, z);
    	}
    	tree->print();
    }
    return 0;
}
*/
/*****************************************
Title
	Comrades - II
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;
typedef unsigned long int uli;

uli height(uli *A, uli node)
{
	uli out = 0;
	while(A[node] != node)
	{
		out++;
		node = A[node];
	}
	return out;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    uli A[100001], h[100001], N, fits, hands, hei;
    cin >> T;
    
    while(T--)
    {
    	A[0] = h[0] = fits = hands = 0;
    	cin >> N;
    	for (uli i = 1; i <= N; ++i)
    	{
    		cin >> A[i];
    		h[i] = 0;
    	}
		for (uli i = 1; i <= N; ++i)
    	{
    		hei = height(A, i);
    		h[hei]++;
    		hands += hei-1;
    		fits += N-hei-2;
    		cout << hei << endl;
    	}
    	cout << hands << " " << fits << endl;
    }
    return 0;
}
*/
/*****************************************
Title
	Gandhi Tree March
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	int data;
	Node *l, *r;

	Node(int v)
	{
		l = NULL;
		r = NULL;
		data = v;
	}
};

class BinaryTree
{
	Node *root;
	
public:
	BinaryTree()
	{
	}

	void setNode(string p, Node *nr)
	{
		for (int i = 2; i < p.length(); i++)
		{
			if(p[i] == '(')
			{
				if(p[i-2] == '(')//a la izq
				{	
					nr->l = new Node(p[i-1]);
					setNode(p.substr(i-1), nr->l);
				}
				if(p[i-2] == ')' || p[i-2] == '.')
				{
					nr->r = new Node(p[i-1]);
					setNode(p.substr(i-1), nr->r);
				}
			}
		}
	}

	void setTree(string p)
	{
		root = new Node(p[0]);
		p = p.substr(2,p.length()-3);
		cout << p << endl;
		//setNode(p, root);
	}

	bool isLeaf(Node *n)
	{
		return n->l == NULL && n->r == NULL ? true : false;
	}

	int max(int a, int b, int c)
	{
		if(b > c)
			return a > b ? a : b;
		else
			return a > c ? a : c;
	}

	void auxHeight(Node *n, int aux, int *h)
	{
		if(n->l != NULL) auxHeight(n->l, aux+1, h);
		if(n->r != NULL) auxHeight(n->r, aux+1, h);
		if(isLeaf(n) && aux > *h) *h = aux;
		
	}

	int height()//Node *n)
	{
		
		if (n == NULL)
			return 0;
		
		int s = 0;
		auxHeight(root, 0, &s);
		return s;
	}

	void auxPrint(Node *n)
	{
		if(n->l != NULL) auxPrint(n->l);
		if(n->r != NULL) auxPrint(n->r);
		cout << (char)n->data << " ";
	}

	void Print()
	{
		auxPrint(root);
	}

};

int main()
{
    BinaryTree tree;
    int a[10][10];

    tree.setTree("a(c(f(.h(..))b(g(..).))e(.d(..)))");
    //tree.Print();
    return 0;
}
*/
/*****************************************
Title
	Karan and Trees 
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int T;
    unsigned long long int x, y;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
    	cin >> x >> y;
    	while(x != y)
    	{
    		while(x > y)
    		{
    			x = floor(x/2);
    		}
    		while(y > x)
    		{
    			y = floor(y/2);	
    		}
    	}
    	cout << x << endl;
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

struct Node
{
	int data;
	Node *l, *r;

	Node()
	{
		l = NULL;
		r = NULL;
	}
};

class BinaryTree
{
	Node *root;
	
public:
	BinaryTree()
	{
		root = new Node;
	}

	void setNode(string p, int v)
	{
		Node *pointer;
		pointer = root;

		for (int i = 0; i < p.length(); i++)
		{
			if(p[i] == 'L')
			{
				if(pointer->l == NULL) pointer->l = new Node;
				pointer = pointer->l;
			}
			if(p[i] == 'R')
			{
				if(pointer->r == NULL) pointer->r = new Node;
				pointer = pointer->r;
			}
		}
		pointer->data = v;
	}

	bool isLeaf(Node *n)
	{
		return n->l == NULL && n->r == NULL ? true : false;
	}

	int max(int a, int b, int c)
	{
		if(b > c)
			return a > b ? a : b;
		else
			return a > c ? a : c;
	}

	void auxHeight(Node *n, int aux, int *h)
	{
		if(n->l != NULL) auxHeight(n->l, aux+1, h);
		if(n->r != NULL) auxHeight(n->r, aux+1, h);
		if(isLeaf(n) && aux > *h) *h = aux;
	}

	int height(Node *n)
	{
		if (n == NULL)
			return 0;
		int s = 0;
		auxHeight(n, 0, &s);
		return s;
	}

	int diameter(Node *n)
	{
		if (n == NULL)
			return 0;
		
		int h = height(n->l) + height(n->r) + 1;
		int ld = diameter(n->l);
		int rd = diameter(n->r);

		return max(h, ld, rd);
	}

	int getDiameter()
	{
		return diameter(root) + 2;
	}
};

int main()
{
    BinaryTree tree;
	
    string s;
    int T, x;
    cin >> T >> x;
    tree.setNode("", x);
    for (int i = 0; i < T-1; i++)
    {
    	cin >> s >> x;
    	tree.setNode(s, x);	
    }

    cout << tree.getDiameter() << endl;
    return 0;
}
*/