#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
typedef pair<int, string> pis;

ifstream fi("telephone.inp");
ofstream fo("telephone.out");
int main()
{
    int n, m;
    fi >> n;
    vector<pis> tx(n), pz(n), fr(n);
    string name;
    int taxi, pizza, friends;
    int max_tx = 0, max_pz = 0, max_fr = 0;

    auto get_type = [&](string s) {
        if (s[0] == s[1] and s[1] == s[3] and s[3] == s[4] and s[4] == s[6] and s[6] == s[7])
            return 0;
        if (s[0] > s[1] and s[1] > s[3] and s[3] > s[4] and s[4] > s[6] and s[6] > s[7])
            return 1;
        return 2;
    };

    auto get_static = [&]() {
        fi >> m >> name;
        taxi = 0;
        pizza = 0;
        friends = 0;
        vector<string> ds(m);
        for (string &x : ds)
            fi >> x;
        sort(ds.begin(), ds.end());

        int it;
        it = unique(ds.begin(), ds.end()) - ds.begin();
        ds.resize(it);

        for (string x : ds)
        {
            int t = get_type(x);
            if (t == 0)
                ++taxi;
            else if (t == 1)
                ++pizza;
            else
                ++friends;
        }
    };

    for (int i = 0; i <= n - 1; ++i)
    {
        get_static();
        tx[i] = {taxi, name};
        pz[i] = {pizza, name};
        fr[i] = {friends, name};
        max_tx = max(max_tx, taxi);
        max_pz = max(max_pz, pizza);
        max_fr = max(max_fr, friends);
    }
    fo << "Taxi: ";
    int k = 0;
    for (auto x : tx)
        if (x.ff == max_tx)
        {
            if (k++)
                fo << ", ";
            fo << x.ss;
        }
    fo << ".\nPizza: ";
    k = 0;
    for (auto x : pz)
        if (x.ff == max_pz)
        {
            if (k++)
                fo << ", ";
            fo << x.ss;
        }
    fo << ".\nFriends: ";
    k = 0;
    for (auto x : fr)
        if (x.ff == max_fr)
        {
            if (k++)
                fo << ", ";
            fo << x.ss;
        }
    return 0;
}
