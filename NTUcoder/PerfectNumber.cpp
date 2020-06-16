
    #include <iostream>
    using namespace std;
    int main()
    {
        int k = 0, m = 19, c = 0, tong;
        int n;
        cin >> k;
        while (0 == 0)
        {
            n = m;
            tong = 0;
            while (n != 0)
            {
                tong = tong + n % 10;
                n = n / 10;
            }
            if (tong == 10)
                c++;
            if (c == k)
                break;
            m++;
        }
        cout << m;
    }