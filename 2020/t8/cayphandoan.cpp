#include <bits/stdc++.h>
using namespace std;
int h[1001];//lưu giá trị vị trí
int a[1001]={0,1, 3, 5, 7, 9, 11};// lưu giá trị

void build(int v, int l, int r)
//nút v quản lí đoạn từ l..r
{
    if (l == r)
    {
        h[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    h[v] = h[2 * v] + h[2 * v + 1];
    return;
}
int getsum(int v, int l, int r, int p, int q)
//tính tổng trên đoạn p..q riêng trên nhánh do nút v quản lí trên đoạn l..r
//độ phức tạp O(log n)
{
    if (q < l || r < p)
        return 0;
    if (p <= l && r <= q)
        return h[v];
    int mid = (l + r) / 2;
    return getsum(2 * v, l, mid, p, q) + getsum(2 * v + 1, mid + 1, r, p, q);
}
void update(int v,int l,int r,int i,int x)
//cập nhật giá trị a[i]=x trên nhánh v để quản lí đoạn l..r
//độ phức tạp O(log n)
{
    if (i<l&&i>r) return; 
    if (l==r) h[v]=x;
    int mid = (l+r)/2;
    update(2*v,l,mid,i,x);
    update(2*v+1,mid,r,i,x);
    return;
}
int main()
{
    int n=6;
    build(1, 1, n);
    cout<<getsum(1,1,n,1,n);
    update(1,1,n,2,9);
}