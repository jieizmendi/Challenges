#include <iostream>
using namespace std;

bool contain(int n)
{
	int d = n % 10;
	n /= 10;
	if(d == 1 && (n % 10) == 2) return true;
	if(n <= 0) return false;
	contain(n);
}

int main()
{
    int N, n;
    cin >> N;
    for(int i=0; i<N; i++)
	{
		cin >> n;
		
		if(n % 21 == 0 or contain(n))
		{
			cout << "The streak is broken!" << endl;
			continue;
		}
		cout << "The streak lives still in our heart!" << endl;
	}
    return 0;
}


/*
#include <iostream>
using namespace std;

int main()
{
    int N, n, d;
    bool s;
    cin >> N;
    for(int i=0; i<N; i++)
	{
		s = false;
		cin >> n;
		
		if(n % 21 == 0)
		{
			cout << "The streak is broken!" << endl;
			break;
		} s = true;

		while (n > 0 && !s){
			d = n % 10;
			n /= 10;

			if(d == 1 && (n % 10) == 2) s = true;
		} 

		if(s)
			cout << "The streak is broken!" << endl;
		else
			cout << "The streak lives still in our heart!" << endl;
	}
    return 0;
}
*/