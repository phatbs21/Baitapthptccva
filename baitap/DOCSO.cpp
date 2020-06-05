#include <bits/stdc++.h>

using namespace std;
string docso1[] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
string docso4[] = {"", "mot", "hai", "ba", "bon", "lam", "sau", "bay", "tam", "chin"};
string docso3[] = {"Khong", "Mot", "Hai", "Ba", "Bon", "Nam", "Sau", "Bay", "Tam", "Chin"};
string docso2[] = {"", "nghin", "tram", "muoi"};
int so[5], dem = 0;
stack<int> q;
int kt(int n)
{
    while (n != 0)
    {
        dem++;
        q.push(n % 10);
        n = n / 10;
    }
    return 0;
}
int main()
{
    //freopen("DOCSO.INP", "r", stdin);
    //freopen("DOCSO.OUT", "w", stdout);
    int n;
    cin >> n;
    kt(n);
    if ((n % 1000 == 0) && (dem == 4))
    {
        cout << docso3[q.top()] << " " << docso2[1];
        return 0;
    }
    else if ((dem == 4) && ((n / 10) % 100 == 0))
    {
        cout << docso3[q.top()] << " nghin khong tram linh ";
        q.pop();
        q.pop();
        q.pop();
        cout << docso1[q.top()];
        return 0;
    }
    else if ((n % 100 == 0) && (dem = 4))
    {
        cout << docso3[q.top()] << " " << docso2[1] << " ";
        q.pop();
        cout << docso1[q.top()] << " " << docso2[2] << " ";
        return 0;
    }
    else if (((n / 10) % 10 == 0) && (dem == 3))
    {
        cout << docso3[q.top()] << " tram linh ";
        q.pop();
        q.pop();
        cout << docso1[q.top()];
        return 0;
    }
    else if ((n % 100 == 0) && (dem == 3))
    {
        cout << docso3[q.top()] << " " << docso2[2];
        return 0;
    }
    if (dem == 4)
    {
        cout << docso3[q.top()] << " " << docso2[1] << " ";
        q.pop();
        cout << docso1[q.top()] << " " << docso2[2] << " ";
        q.pop();
        cout << docso1[q.top()] << " " << docso2[3] << " ";
        q.pop();
        cout << docso4[q.top()];
    }
    else if (dem == 3)
    {
        cout << docso3[q.top()] << " " << docso2[2] << " ";
        q.pop();
        cout << docso1[q.top()] << " " << docso2[3] << " ";
        q.pop();
        cout << docso4[q.top()];
    }
    else if (dem == 2)
    {
        if (q.top() == 1)
        {
            q.pop();
            cout << "Muoi " << docso4[q.top()];
        }
        else
        {
            cout << docso3[q.top()] << " " << docso2[3] << " ";
            q.pop();
            cout << docso4[q.top()];
        }
    }
    else if (dem == 1)
    {
        cout << docso3[q.top()];
    }
    else
    {
        cout << "Khong";
    }
}