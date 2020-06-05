#include <bits/stdc++.h>

using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options

string so[10] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
int dso[10] = {5, 3, 3, 2, 3, 3, 3, 3, 3, 4};
string tso[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int main()
{
    freopen("sdt.inp", "r", stdin);
    freopen("sdt.out", "w", stdout);
    string s;
    getline(cin, s);
    s.insert(s.length(), ",");
    int q;
    //cout<<s<<endl;
    int dem = 0;
    int a[100];
    //cout << dem << endl;
    while (s.find(":") != std::string::npos)
    {

        s.erase(0, s.find(":") + 2);
        string s1 = s.substr(0, s.find(","));
        for (int i = 0; i <= 9; i++)
        {
            while ((q = s1.find(so[i])) != std::string::npos)
            {
                //int q = s1.find(so[i]);
                //s1.erase(q,so[i].length());
                //cout<<"Sau khi xoa "<<s1<<endl;
                //s1.insert(q,tso[i]);
                //cout<<"Sau khi them "<<s1<<endl;
                //s1=s1.substr(0,q)+tso[i]+s1.substr(q+so[i].length());
                s1.replace(q, so[i].length(), tso[i]);
            }
        }
        int z = stoi(s1);
        if (binary_search(a + 1, a + dem + 1, z)==true)
            break;
        dem++;
        a[dem] = z;
    }
    /*
    for (int i = 1; i <= dem; i++)
        for (int j = 1; j <= dem; j++)
        {
            if (a[i] == a[j] && i != j)
                dem--;
        }
        */
    cout << dem << endl;
    for (int i = 1; i <= dem; i++)
        cout << a[i] << endl;
}