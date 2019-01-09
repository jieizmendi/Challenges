/*****************************************
Title
	Tutorial
Autor
	Juan Eizmendi
*****************************************/
#include <iostream>
#include <vector>
using namespace std;

class LCA
{
	vector<int> Adj;
public:
	LCA(int N)
	{
		Adj.resize(N);
		Adj[0] = 0;
		int n;

		//Init tree
		for (int i = 1; i < N; i++)
	    {
	       	cin >> n;
	    	Adj[i] = n;
	    }
	}

	int findLCA(int M)
	{
		vector< vector<int> > c;
		c.resize(M);

		vector<int>::iterator it;
		int n;
		
		for (int i = 0; i < M; i++)
	    {
	    	it = c[i].begin();
	       	cin >> n;
	       	it = c[i].insert(it, n);
	       	while(Adj[n] != n) 
	       	{
	       		it = c[i].insert(it, Adj[n]);
	       		n = Adj[n];
	       	}
	    }

	    bool flag = true;
	    n = -1;
	    while(flag)
	    {
	    	n++;
	    	for (int i = 0; i < M-1; i++)
	    	{
	    		if(c[i][n] != c[i+1][n])
	    		{
	    			flag = false;
	    			break;
	    		}
	    	}
	    }
	    return c[0][n-1];
	}
};

int main()
{
	LCA *lca;
	int N;

    cin >> N;
    lca = new LCA(N);

	cin >> N;
    cout << lca->findLCA(N) << endl;;

    return 0;
}