int test(int n)
{
    int c = 0;
    int a = 0, dem = 0, b = 0;
    string s1, s2 = "";
    while (n > 0)
    {
        dem++;
        s1 = to_string(c);
        if (n % 2 == 1)
        {
            if (dem % 2)
                a += stoi(s1);
            else
                b += stoi(s1);
        }
        n = n / 2;
        c++;
    }
    return abs(a - b);
}

