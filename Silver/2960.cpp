#include <bits/stdc++.h>
using namespace std;

int prime[1010];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=2;i<=n;i++)prime[i]=1;
    int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(prime[i]!=0)
        {
            for(int j=1;i*j<=n;j++)
            {
                if(prime[i*j]!=0)
                {
                    prime[i*j]=0;
                    cnt++;
                    if(cnt==k)
                    {
                        cout<<i*j;
                        break;
                    }
                }
            }
        }
    }
}
