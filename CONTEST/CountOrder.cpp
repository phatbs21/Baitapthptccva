#include <bits/stdc++.h>
#define MAX 10
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options

int n;
int Bool[MAX] = {0}; //Đánh dấu chưa có phần tử nào sử dụng hết
int A[MAX];          //Lưu hoán vị vào mảng A
int p[MAX], q[MAX];
int vt1, vt2;
int dem = 0;
void xuatvt2()
{
    int b = 0;
    for (int i = 1; i <= n; i++)
    {
        if (A[i] == q[i])
        {
            b++;
        }
        else
            return;
    }
    if (b == n)
    {
        vt2 = dem;
    }
    else
        return;
}

void xuatvt1()
{
    int a = 0;
    for (int i = 1; i <= n; i++)
    {
        if (A[i] == p[i])
        {
            a++;
        }
        else
            return;
    }
    if (a == n)
    {
        vt1 = dem;
    }
    else
        return;
}

void thu(int k)
{
    for (int i = 1; i <= n; i++)
    {
        //Kiểm tra nếu phần tử chưa được chọn thì sẽ đánh dấu
        if (!Bool[i])
        {
            A[k] = i;    // Lưu một phần tử vào hoán vị
            Bool[i] = 1; //Đánh dấu đã dùng
            if (k == n)  //Kiểm tra nếu đã chứa một hoán vị thì xuất
            {
                dem++;
                xuatvt1();
                xuatvt2();
            }
            else
                thu(k + 1);
            Bool[i] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
    }
    thu(1);
    cout << abs(vt1 - vt2);
}