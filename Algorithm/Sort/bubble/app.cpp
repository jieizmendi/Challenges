/*****************************************
Title
    Tutorial
Autor
    Juan Eizmendi
*****************************************/
/*****************************************
Title
    Save Patients 
Autor
    Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int *A, int n) {
    for(int k = 0; k < n-1; k++)
        for(int i = 0; i < n-k-1; i++)
            if(A[ i ] > A[ i+1] )
                swap(A[i], A[i+1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int N, P[11], V[11];
    bool flag;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> V[i];
    for (int i = 0; i < N; i++)
        cin >> P[i];
    
    bubble_sort(P, N);
    bubble_sort(V, N);
    
    flag = true;
    for (int i = 0; i < N; i++)
        if(P[i] > V[i])
        {
            flag = false;
            break;
        }

    cout << (flag?"Yes":"No") << endl;
    return 0;
}
*/
/*****************************************
Title
    Castle's Stones 
Autor
    Juan Eizmendi
*****************************************/
#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int *A, int n) {
    for(int k = 0; k < n-1; k++)
        for(int i = 0; i < n-k-1; i++)
            if(A[ i ] < A[ i+1] )
                swap(A[i], A[i+1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T, M, N, h[1001], crane, cont, c;

    cin >> T;
    while(T--)
    {
        cin >> M >> N;
        for (int i = 0; i < N; i++) cin >> h[i];    
        cont = 0;
        bubble_sort(h, N);

        crane = 0;
        c = 0;
        for (int i = 0; i < N; i++)
        {
            if(h[i] <= M)
            {
                if(crane+h[i] <= M && c < 2)
                {
                    crane += h[i];
                    c++;
                }
                else
                { 
                    crane = h[i];
                    cont++;
                    c = 1;
                }    
            }
        }
        if(crane > 0) cont++;
        cout << cont << endl;
    }
    return 0;
}
/*****************************************
Title
     Palindromic Revenge 
Autor
    Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int T, cost;
    string str;
    cin >> T;
    while(T--)
    {
        cin >> str;
        string::iterator itF, itL;
        itF = str.begin();
        itL = str.end()-1;
        cost = 0;
        while(itF < itL)
        {
            if(*itF > *itL)
            {
                while(*itF != *itL)
                {
                    (*itF)--;
                    cost++;
                }
            }else if(*itF < *itL) 
            {
                while(*itF != *itL)
                {
                    (*itL)--;
                    cost++;
                }
            }
            itF++;
            itL--;
        }
        cout << cost << endl;
    }
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
#include <algorithm>
using namespace std;

int bubble_sort(int *A, int n) {
    int temp = 0;
    for(int k = 0; k < n-1; k++) {
        for(int i = 0; i < n-k-1; i++) {
            if(A[ i ] > A[ i+1] ) {
                swap(A[i], A[i+1]);
                temp++;
            }
        }
    }
    return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int N, n[101];
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> n[i];
    cout << bubble_sort(n, N) << endl;
}
*/