/*****************************************
Title
	Tutorial
Autor
	Juan Eizmendi
*****************************************/
#include <bits/stdc++.h>
using namespace std;	
typedef long long int lli;

class SegmentTree
{
	int tree[100005], A[100005];
	int N;
public:
	SegmentTree(int _N)
	{
		N = _N;
		for (int i = 0; i < N; ++i)
			cin >> A[i];
	}

	void build(int node, int start, int end)
	{
		cout << "tree[ " << start << " : " << end << " ], in node" << node << endl;
	    if(start == end)
	    {
	        // Leaf node will have a single element
	        tree[node] = A[start];
	    }
	    else
	    {
	        int mid = (start + end) / 2;
	        // Recurse on the left child
	        build(2*node, start, mid);
	        // Recurse on the right child
	        build(2*node+1, mid+1, end);
	        // Internal node will have the sum of both of its children
	        tree[node] = tree[2*node] + tree[2*node+1];
	    }
	}

	void printTree()
	{
		for (int i = 1; i < 14; ++i)
		{
			cout << "tree[" << i << "] = " << tree[i] << endl;
			//cout << "A[" << i << "] = " << A[i] << endl;
		}
	}

	~SegmentTree();
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in","r",stdin);
	lli N, Q, a, b;

	cin >> N >> Q;

	SegmentTree *tree = new SegmentTree(N);

	tree->build(1,0,5);
	tree->printTree();

	return 0;
}