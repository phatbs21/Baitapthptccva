#include <bits/stdc++.h>
using namespace std;
struct matrix
{
    long long o[3][3];
};
int n = 3;
matrix operator*(matrix A, matrix B)
{
    matrix C;
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
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
matrix luythua(matrix A, int k)
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
            M = M * X;
        X = X * X;
        k = k / 2;
    }
    return M;
}
void viet(matrix A)
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
void test_nhan_1()
{
    matrix A, B, C;
    A.o[0][0] = 2;
    A.o[0][1] = 3;
    A.o[0][2] = 1;
    A.o[1][0] = 1;
    A.o[1][1] = 3;
    A.o[1][2] = 1;
    A.o[2][0] = 2;
    A.o[2][1] = 4;
    A.o[2][2] = 1;
    B.o[0][0] = 2;
    B.o[0][1] = 3;
    B.o[0][2] = 1;
    B.o[1][0] = 3;
    B.o[1][1] = 3;
    B.o[1][2] = 1;
    B.o[2][0] = 2;
    B.o[2][1] = 4;
    B.o[2][2] = 1;
    C = A * B;
    viet(C);
}

int main()
{
    test_nhan_1();
}