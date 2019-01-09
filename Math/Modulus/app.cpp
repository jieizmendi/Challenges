/*****************************************
Title
	Tutorial
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unsigned int N;
    unsigned long int n, s=1;
	cin >> N;
	while(N--)
	{
		cin >> n;
		s = ((n%1000000007)*(s%1000000007))%1000000007;
	}
	cout << s << endl;
    return 0;
}
*/
/*****************************************
Title
	Easy Factorial-A
Autor
	Juan Eizmendi
Input 23 14567
Output
*****************************************/
/*
#include <iostream>
using namespace std;

int main()
{
    int n = 24;
    long long int N=1;
    while(n--){
    	N = (N*n);
    	cout << N << endl;
    	N = N%14567;
    	cout << N << endl;
    }
	cout << N << endl;
    return 0;
}
*/
/*****************************************
Title
	Big Values
Autor
	Juan Eizmendi
Input 23 14567
Output
*****************************************/
#include <iostream>
using namespace std;

long long int factorial(long long int n)
{
	long long int s=1;
	while(n>0) s = ((s*n--)%1000000007);
	return s;
}

long long int findMMI(long long int n)
{
    long long i=1;
    while(i<1000000007)
    {
        if(( i * n ) % 1000000007 ==1)
            return i;
        i++;
    }
    return -1;//MMI doesn't exist
}

int main()
{
    long long int N, n;
    cin >> n;
    N = (factorial(6)*factorial(n-6))%1000000007;
    N = findMMI(N);
    N = (factorial(n)*N)%1000000007;
    cout << N << endl;
    return 0;
}
