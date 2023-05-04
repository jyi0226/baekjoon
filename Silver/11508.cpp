#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b)
{
    return a>b;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n;
    int price[101010];
    cin>>n;
    for(int i=0;i<n;i++)cin>>price[i];
    sort(price,price+n,comp);
    for(int i=0;i<n;i++)
    {
        if((i+1)%3==0)price[i]=0;
    }
    long long Sum=0;
    for(int i=0;i<n;i++)Sum+=price[i];
    cout<<Sum;
}
