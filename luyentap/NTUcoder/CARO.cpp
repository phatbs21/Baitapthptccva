#include <bits/stdc++.h>
using namespace std;
int check = -1; //0 thi teo, 1 thi ti

int teo()
{
    cout << "Teo wins";
    check = 0;
    return 0;
}
int ti()
{
    cout << "Ti wins";
    check = 0;

    return 0;
}
int hoa()
{
    cout << "Not yet";
    check = 0;

    return 0;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'x')
                a[i][j] = 1;
            if (s[j] == 'o')
                a[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int demx = 0, demo = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
                demo++;
            if (a[i][j] == 1)
                demx++;
        }
        if (demo >= 5)
            teo();
        if (demx >= 5)
            ti();
    }
    if (check == 0)
        return 0;

    for (int i = 0; i < n; i++)
    {
        int demx = 0, demo = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j][i] == 0)
                demo++;
            if (a[j][i] == 1)
                demx++;
        }
        if (demo >= 5)
            teo();
        if (demx >= 5)
            ti();
    }
    if (check == 0)
        return 0;
    //phai
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int demx = 0, demo = 0;
            for (int h = 0; h < 5; h++)
            {
                if (i + h >= n || j - h >= n)
                    break;
                if (a[i + h][j - h] != 1)
                    break;
                demx++;
            }
            for (int h = 0; h < 5; h++)
            {
                if (i + h >= n || j - h >= n)
                    break;
                if (a[i + h][j - h] != 0)
                    break;
                demo++;
            }

            if (demo >= 5)
                teo();
            if (demx >= 5)
                ti();
        }
    }
    if (check == 0)
        return 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int demx = 0, demo = 0;
            for (int h = 0; h < 5; h++)
            {
                if (i + h >= n || j + h >= n)
                    break;
                if (a[i + h][j + h] != 1)
                    break;
                demx++;
            }
            for (int h = 0; h < 5; h++)
            {
                if (i + h >= n || j + h >= n)
                    break;
                if (a[i + h][j + h] != 0)
                    break;
                demo++;
            }
            if (demo >= 5)
                teo();
            if (demx >= 5)
                ti();
        }
    }
    if (check == 0)
        return 0;

    hoa();
}