#include <chrono>
#include <iostream>
using namespace std;
int start()
{
    auto start = chrono::steady_clock::now();
}
int end()
{
    //bỏ phần này
    auto start = chrono::steady_clock::now();
    //bỏ phần này copy ở dưới
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout <<endl<< "Runtime: " << chrono::duration<double>(diff).count() << " seconds" << endl;
}
// thư viện này không dùng được
// copy 2 phần start bỏ ở đầu và end ở cuối để tính thời gian