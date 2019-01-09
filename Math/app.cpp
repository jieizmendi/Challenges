/*****************************************
Title
	Roy and Maximum XOR
Autor
	Juan Eizmendi
*****************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	unsigned long long int N, T, n, max;
	int c;
	cin >> T;
	while(T--)
	{
		cin >> N;
	    c = 0;
	    n = N;
	    while(n)
	    {
	    	c++;
	    	n = n>>1;
	    }
	    max = pow(2, c)-1;
	    
    	cout << max << " " << ((N-(max>>1))*2) << endl;
	}
}
