#include <bits/stdc++.h>
using namespace std;
int n,m,prime[1010]={1,1,0,0,},cnt=0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n;
    for(int i=2;i<=1000;i++)
    {
        if(prime[i]==0)
        {
            for(int j=2;i*j<=1000;j++)prime[i*j]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>m;
        if(prime[m]==0)cnt++;
    }
    cout<<cnt<<"\n";
}