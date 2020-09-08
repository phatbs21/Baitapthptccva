#include <bits/stdc++.h>
using namespace std;
struct matrix
{
    long long o[2][2];
};
int n;
matrix nhan(matrix A, matrix B, int m, int n, int p)
{
    matrix C;
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            C.o[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                C.o[i][j] += A.o[i][k] * B.o[k][j];
            }
        }
    }
    return C;
}
matrix luythua(matrix A, int n, int k)
{
    matrix X = A;
    matrix M;
    memset(M.o, 0, sizeof(M.o));
    for (int i = 0; i < n; i++)
    {
        M.o[i][i] = 1;
    }
    while (k)
    {
        if (k % 2 == 1)
            M = nhan(M, X, n, n, n);
        X = nhan(X, X, n, n, n);
        k = k / 2;
    }
    return M;
}
void viet(matrix A, int m, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A.o[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    matrix A;
    A.o[0][0] = 1;
    A.o[0][1] = 1;
    A.o[1][1] = 1;
    A.o[1][1] = 0;
    cin >> n;
    viet(luythua(A, n, n), n, n);
}