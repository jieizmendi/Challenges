/*****************************************
Title
	Bayes’ rules, Conditional probability, Chain rule
Autor
	Juan Eizmendi
*****************************************/
#include <bits/stdc++.h>
using namespace std;	

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("in","r",stdin);
	double pct, pot, N;

    cin >> pct >> pot >> N;
    
    cout << fixed << setprecision(6);
    cout << (pot*(1-pct) + pct*2/N) << endl;

	return 0;
}