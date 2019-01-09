#include <iostream>
using namespace std;

bool Print(bool **board, unsigned long long int N)
{
    unsigned long long int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cout << board[i][j] ? "1" : "0";
            if (j == N - 1)
            {
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }
}

bool IsSafe(unsigned long long int x, unsigned long long int y, bool **board, unsigned long long int N)
{
    unsigned long long int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (i == x || j == y || (i - j) == (x - y) || (i + j) == (x + y))
            {
                if (board[i][j])
                    return false;
            }
        }
    }

    return true;
}

bool NQueens(bool **board, unsigned long long int N, unsigned long long int Qs)
{
    if (Qs == 0)
        return true;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (IsSafe(i, j, board, N))
            {
                board[i][j] = true;
                if (NQueens(board, N, Qs - 1))
                {
                    return true;
                }
                board[i][j] = false;
            }
        }
    }

    return false;
}

int main()
{
    unsigned long long int N, i, j;
    cin >> N;

    bool **board = new bool *[N];
    for (int i = 0; i < N; i++)
    {
        board[i] = new bool[N];
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            board[i][j] = false;
        }
    }

    if (NQueens(board, N, N))
    {
        cout << "YES" << endl;
        Print(board, N);
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
