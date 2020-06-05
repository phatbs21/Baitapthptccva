#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string kitu = "W";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            cout << kitu;
            if (kitu == "W")
                kitu = "B";
            else
                kitu = "W";
        }
        cout << endl;
        if (n % 2 == 0)
            if (kitu == "W")
                kitu = "B";
            else
                kitu = "W";
    }
    return 0;
}
