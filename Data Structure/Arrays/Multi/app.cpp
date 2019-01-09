/*****************************************
Title
	Saul Goodman's Problem Statement
Autor
	Juan Eizmendi
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;

struct PointXY
{
	long long int x, y;
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("in", "r", stdin);

	long long int T, N, i, j, c;
	vector<PointXY> points(1000000);

	cin >> T;
	while (T--)
	{
		cin >> N;
		c = 0;
		for (i = 0; i < N; i++)
		{
			cin >> points[i].x >> points[i].y;
		}

		for (i = 0; i < N; i++)
		{
			for (j = i+1; j < N; j++)
			{
				if ((points[i].x - points[i].y == points[j].x - points[j].y) || (points[i].x + points[i].y == points[j].x + points[j].y))
					c++;
			}
		}
		cout << c << endl;
	}

	return 0;
}
*/
/*****************************************
Title
	Roy and Symmetric Logos
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> matrix;
	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		matrix.resize(N);
		for (int j = 0; j < N; j++)	cin >> matrix[j];
		
		bool symetric = true;
		//Y-Symetric
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < (N>>1); y++)
			{
				if(matrix[x][y] != matrix[x][N-y-1])
				{
					symetric = false;
					x = N;
					break;
				}
			}
		}

		//X-Symetric
		if(symetric)
		{
			for (int y = 0; y < N; y++)
			{
				for (int x = 0; x < (N>>1); x++)
				{
					if(matrix[x][y] != matrix[N-x-1][y])
					{
						symetric = false;
						y = N;
						break;
					}
				}
			}
		}

		if(symetric)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
    return 0;
}
*/
/*****************************************
Title
	Akash and the Assignment 1
Autor
	Juan Eizmendi
Example
	In
		6 2
		abcdef
		2 6 3
		4 6 1
	Out 
		d
		d
*****************************************/
/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in","r",stdin);
	char str[50001];
	int N, Q, l, r, k, abc[26];
	scanf("%d%d", &N, &Q);
	scanf("%s", str);

	while(Q--)
	{
		scanf("%d%d%d", &l, &r, &k);
		if(r-l+1 < k || r > N || k > N)
		{
			printf("Out of range\n");
		}else
		{
			for (int i = 0; i < 26; i++) abc[i]=0;
			for (int i = l-1; i < r; i++) abc[str[i]-'a']++;
			int j=0;
			while(k > 0 && j < 26) 
				k -= abc[j++];

			printf("%c\n", j+'a'-1);
		}
	}
    return 0;
}
*/

/*****************************************
Title
	tutorial
Autor
	Juan Eizmendi
*****************************************/
/*
#include <iostream>
using namespace std;

int main()
{
	int N, M, n[10][10];
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> n[i][j];
		}
	}

	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			cout << n[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}
*/