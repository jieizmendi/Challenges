/*****************************************
Title
	Monk and his Friends 
Autor
	Juan Eizmendi
*****************************************/
#include <iostream>
using namespace std;

struct Node
{
	long long int data;
	Node *l, *r;

	Node(int v)
	{
		data = v;
		l = NULL;
		r = NULL;
	}
};

class BinaryTree
{
	Node *root;
	
public:
	BinaryTree(int v)
	{
		root = new Node(v);
	}

	bool auxInsert(Node *n, long long int v) {
	    if(n->data > v) {
	        if(n->l != NULL) {
	            auxInsert(n->l, v);
	        } else {
	            n->l = new Node(v);
	            return true;
	        }
	    } else if(n->data < v) {
	        if(n->r != NULL) {
	            auxInsert(n->r, v);
	        } else {
	            n->r = new Node(v);
	            return true;
	        }
	    } else {
	    	return false;
	    }
	}

	bool insert(long long int v)
	{
		return auxInsert(root, v);
	}
};

int main()
{
    BinaryTree *tree;
	
    int N, M, T;
    long long int n;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
    	cin >> N >> M >> n;
    	tree = new BinaryTree(n);
	    for (int j = 0; j < N-1; j++)
	    {
	    	cin >> n;
	   		tree->insert(n);
	    }
	    
	    for (int j = 0; j < M; j++)
	    {
	    	cin >> n;

	   		if(tree->insert(n))
	   			cout << "NO" << endl;
	   		else
	   			cout << "YES" << endl;

	    }
	    
    }
    return 0;
}
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
	long long int data;
	Node *l, *r;

	Node(int v)
	{
		data = v;
		l = NULL;
		r = NULL;
	}
};

class BinaryTree
{
	Node *root;
	
public:
	BinaryTree(int v)
	{
		root = new Node(v);
	}

	void auxInsert(Node *n, long long int v) {
	    if(n->data > v) {
	        if(n->l != NULL) {
	            auxInsert(n->l, v);
	        } else {
	            n->l = new Node(v);
	        }
	    } else {
	        if(n->r != NULL) {
	            auxInsert(n->r, v);
	        } else {
	            n->r = new Node(v);
	        }
	    }
	}

	void insert(long long int v)
	{
		auxInsert(root, v);
	}

	Node* search(int v)
	{
		Node *n = root;
		while(n->data != v)
		{
			if(n->data > v)
				n = n->l;
			else
				n = n->r;
		}
		return n;
	}

	void printPreOrder(Node *n)
	{
		cout << n->data << endl;
		if(n->l != NULL) printPreOrder(n->l);
		if(n->r != NULL) printPreOrder(n->r);
	}

	void print(int v)
	{
		printPreOrder(search(v));
	}
};

int main()
{
    BinaryTree *tree;
	
    int N;
    long long int n;
    cin >> N >> n;
    tree = new BinaryTree(n);
    for (int i = 0; i < N-1; i++)
    {
    	cin >> n;
   		tree->insert(n);
    }
    cin >> n;
    tree->print(n);
    return 0;
}
*/
