#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int demA = 0, demB = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
                demA++;
            if (s[i] == 'B')
                demB++;
        }
        if (demA == 0)
        {
            demB = demB % 2;
            cout << demB << "\n";
            continue;
        }
        if (demB == 0)
        {
            cout << demA << "\n";
            continue;
        }
        int dem = 0, dem1 = 0, demB2 = demB;
        int z = 0;
        for (int i = 0; i < n && demA >= 0 && demB > 0; i++)
        {
            if (s[i] == 'A')
            {
                if (demB2 - dem > 0)
                {
                    demA--;
                    demB--;
                    dem1 = 0;
                    z++;
                }
                else
                    break;
            }
            else
            {
                dem++;
                if (z > 0)
                {
                    z--;
                    continue;
                }
                if (dem1 > 0 && demB >= 2)
                {
                    demB -= 2;
                    dem1 = 0;
                }
                dem1++;
            }
        }
        cout <<  demA + demB << "\n";
    }
}