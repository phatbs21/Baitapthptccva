#include <bits/stdc++.h>
using namespace std;
int so[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int ss[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
#define bignum string
bignum cong(bignum s1, bignum s2)
{
    while (s1.length() < s2.length())
        s1 = "0" + s1;
    while (s2.length() < s1.length())
        s2 = "0" + s2;
    bignum k = "";
    int c, nho = 0;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        c = (s1[i] - 48) + (s2[i] - 48) + nho;
        nho = c / 10;
        c = c % 10;
        k = char(c + 48) + k;
    }
    if (nho > 0)
        k = "1" + k;
    return k;
}
int sosanh(bignum s1, bignum s2)
{
    if (s1.length() > s2.length())
        return 1;
    if (s2.length() > s1.length())
        return -1;
    if (s1 == s2)
        return 0;
    if (s1 > s2)
        return 1;
    return -1;
}
bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
    {
        if (str1[i] < str2[i])
            return true;
        else if (str1[i] > str2[i])
            return false;
    }
    return false;
}
string findDiff(string str1, string str2)
{
    if (isSmaller(str1, str2))
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n1 - n2;
    int carry = 0;
    for (int i = n2 - 1; i >= 0; i--)
    {
        int sub = ((str1[i + diff] - '0') - (str2[i] - '0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }
    for (int i = n1 - n2 - 1; i >= 0; i--)
    {
        if (str1[i] == '0' && carry)
        {
            str.push_back('9');
            continue;
        }
        int sub = ((str1[i] - '0') - carry);
        if (i > 0 || sub > 0)
            str.push_back(sub + '0');
        carry = 0;
    }
    reverse(str.begin(), str.end());
    return str;
}
string longDivision(string number, int divisor)
{
    // As result can be very large store it in string
    string ans;

    // Find prefix of number that is larger
    // than divisor.
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');

    // Repeatedly divide divisor with temp. After
    // every division, update temp to include one
    // more digit.
    while (number.size() > idx)
    {
        // Store result in answer i.e. temp / divisor
        ans += (temp / divisor) + '0';

        // Take next digit of number
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }

    // If divisor is greater than number
    if (ans.length() == 0)
        return "0";

    // else return ans
    return ans;
}

bignum nhan1(bignum s, int a)
{
    string k;
    int nho = 0, c;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        c = a * (s[i] - 48) + nho;
        nho = c / 10;
        c = c % 10;
        k = char(c + 48) + k;
    }
    while (nho > 0)
    {
        k = char(nho % 10 + 48) + k;
        nho /= 10;
    }
    return k;
}
bignum nhan(bignum s1, bignum s2)
{
    bignum k, t, d;
    for (int i = s2.length() - 1; i >= 0; i--)
    {
        t = nhan1(s1, s2[i] - 48) + d;
        k = cong(k, t);
        d = d + "0";
    }
    return k;
}
int tach(string n)
{
    int dem = 0;
    bignum z = n;
    while (sosanh(z, "0") == 1)
    {
        dem++;
        z = longDivision(z, 10);
    }
    int sum = 0;
    while (sosanh("0", n) == -1)
    {
        sum += so[n[n.length() - 1] - '0'];
        n = longDivision(n, 10);
    }
    return sum;
}
int main()
{
    string n;
    cin >> n;
    if (n == "1")
    {
        cout << "NO SOLUTION";
        return 0;
    }
    string i = n;
    i = cong(i, "1");
    while (tach(n) != tach(i))
    {
        i = cong(i, "1");
    }
    cout << i;
}