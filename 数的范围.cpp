#include<stdio.h>
#include<iostream>
using namespace std;
int qq;
const int N = 100010;
int n, m;
int q[N];
int bsearch_1(int l,int r)
{
    while(l<r)
    {
        int mid = l + r >> 1;
        if(q[mid]>=qq) r=mid;
        else l = mid+1;
    }
    return l;
}
int bsearch_2(int l,int r)
{
    while(l<r)
    {
        int mid = l+r+1>>1;
        if(q[mid]>qq) r = mid-1;
        else l = mid;
    }
    return l;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);
    while(m--){
        scanf("%d", &qq);
        int l = bsearch_1(0,n-1);
        if (q[l] != qq) cout << "-1 -1" << endl;
        else{
            cout<<l<<" ";
            l = bsearch_2(0,n-1);
            cout<<l<<endl;
        }
    }
}
