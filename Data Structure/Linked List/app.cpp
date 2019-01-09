/*****************************************
Title
	Remove Friends 
Autor
	Juan Eizmendi
*****************************************/
#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *next;
	Node(int v)
	{
		value = v;
		next = NULL;
	}
};

void printList(Node *node)
{
	cout << node->value << " ";
	if(node->next)	return printList(node->next);
	cout << endl;
}

void deleteByPopularity(Node *node)
{
	while(node->next->next != NULL)
	{
		if(node->value < node->next->value)
		{
			*node = *node->next;
			return;
		}
		node = node->next;
	}
	if(node->value < node->next->value)
	{
		*node = *node->next;
		return;
	}
	node->next = NULL;
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int T, N, k, temp;

    Node *first, *last;

    cin >> T;
    while(T--)
    {
    	cin >> N >> k >> temp;
    	
    	first = new Node(temp);
		last = first;

    	for (int j = 1; j < N; j++)
    	{
    		cin >> temp;

    		if(last->value < temp && k != 0)
    		{
    			k--;
    			last = new Node(temp);
    		}else{
    			last->next = new Node(temp);
    			last = last->next;
    		}
    	}
    	while(k--) deleteByPopularity(first);

    	printList(first);
    	//cout << "Puta imprimir"<< endl;
    }
    return 0;
}
/*
#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *next;
	Node(int v)
	{
		value = v;
		next = NULL;
	}
};
class LinkedList
{
	Node *first;
	Node *last;

public:
	LinkedList()
	{
		first = new Node(0);
		last = first;
	}
	
	void printLenght()
	{
		cout << "Longitud: " << first->value << endl;
	}

	void addNode(int v)
	{
		last->next = new Node(v);
		last = last->next;
		first->value++;
	}

	void printList()
	{
		Node *n = first;
		while(n->next != NULL)
		{
			n = n->next;
			cout << n->value << " ";
		}
		cout << endl;
	}

	void deleteNode(Node *n)
	{
		*n = *n->next;
	}

	void deleteByPopularity(int c)
	{
		Node *n = first;
		bool flag = false;
		while(n->next->next != NULL)
		{
			n = n->next;
			if(n->value < n->next->value)
			{
				deleteNode(n);
				flag = true;
				break;
			}
		}
		if(!flag)
			deleteNode(n->next);
		if(c > 1)
			deleteByPopularity(c-1);
	}
};

int main()
{
    int T, N, n, q;
    LinkedList *list;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
    	cin >> N >> n;
    	list = new LinkedList();
    	for (int j = 0; j < N; j++)
    	{
    		cin >> q;
    		list->addNode(q);
    	}
    	list->deleteByPopularity(n);
    	list->printList();
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
#include <stdio.h>  
#include <stdlib.h>

struct LinkedList{
	int data;
	struct LinkedList *next;
}; 

typedef struct LinkedList *node;

node createNode(){

	node temp;
	temp = (node)malloc(sizeof(node));
	temp->next = NULL;
	return temp;
} 

void addNode(node head, int value){

	node temp,p;
	p = head;
	temp = createNode();
	temp->data = value;
	while(p->next != NULL){
	    p = p->next;
	}
	p->next = temp;
} 
void printList(node head){

	node p;
	p = head;
	while(p->next != NULL){//Enter the last node condition here
		p = p->next;
		printf("%d\n", p->data);//Enter the code to access data field of the node
	}
} 
int main() {
	node head;
	head = (node)malloc(sizeof(node));
	head->next = NULL;
	addNode(head, 1);
	addNode(head, 2);
	addNode(head, 3);
	addNode(head, 4);
	printList(head);
	return 0;
}
*/