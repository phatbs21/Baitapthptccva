#include <iostream>
using namespace std;
int x[1000] = {0}, t[1000] = {0}, n;
void print(int i)
{
    for (int k = 1; k <= i; k++)
    {
        cout << x[k] << " ";
    }
    cout << endl;
}
void thu(int i)
{
    for (int j = x[i - 1]; j <= (n - t[i - 1]); j++)
    {
        x[i] = j;
        t[i] = t[i - 1] + x[i];
        if (t[i] == n)
            print(i);
        else
            thu(i + 1);
    }
}
int main()
{
    x[0] = 1;
    cin >> n;
    thu(1);
    return 0;
}