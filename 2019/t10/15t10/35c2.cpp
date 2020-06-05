#include <bits\stdc++.h>
using namespace std;
struct ps
{
    int a, b;
};
bool operator<(ps x, ps y)
{
    return (x.a * y.b - x.b * y.a) * (x.b * y.b) < 0;
}
bool operator==(ps x, ps y)
{
    return x.a * y.b == x.a * y.b;
}
int main()
{
    set<ps> s;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            s.insert({j,i});
    set<ps>::iterator p;
    for (p= s.begin();p!=s.end();p++)
    {
        cout<<(*p).a<<" "<<(*p).b<<endl;
    }
}