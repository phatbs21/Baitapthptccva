#include <bits/stdc++.h>
using namespace std;
bool is_shuffled_palindrome(const string &s)
{
    vector<long long int> occurrence(26, 0);
    long long int odd_count = 0;
    for (char i : s)
    {
        occurrence[i - 'a']++;
    }
    for (long long int value : occurrence)
    {
        if (value % 2 != 0)
        {
            odd_count++;
        }
    }
    return odd_count <= 1;
}
long long int solution(string s)
{
    long long int s_size = s.size();
    long long int result = 0;
    long long int start = 0, end = s_size - 1;
    if ((s_size == 0) || (!is_shuffled_palindrome(s)))
    {
        return -1;
    }

    while (end > start)
    {
        if (s[start] != s[end])
        {
            long long int i = end;
            while (i > start && s[i] != s[start])
            {
                --i;
            }
            if (i == start)
            {
                swap(s[start], s[start + 1]);
                ++result;
            }
            else
            {
                while (i < end)
                {
                    swap(s[i], s[i + 1]);
                    ++result;
                    ++i;
                }
                ++start;
                --end;
            }
        }
        else
        {
            ++start;
            --end;
        }
    }
    return result;
}

int main()
{
    //freopen("swap.inp", "r", stdin);
    string s;
    cin >> s;
    cout << solution(s);
    return 0;
}
