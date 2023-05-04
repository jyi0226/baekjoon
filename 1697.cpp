#include <bits/stdc++.h>
using namespace std;

int dp[1010101];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n,k;
    
    cin>>n>>k;
    if(n>=k)cout<<n-k;
    else
    {
        for(int i=0;i<=1000000;i++)
        {
            if(n>=i)dp[i]=n-i;
            else
            {
                if(i%2!=0)
                {
                    dp[i]=dp[i-1]+1;
                }
                else
                {
                    dp[i]=min({dp[i-1]+1,dp[i/2]+1});
                }
            }
        }
        for(int i=1;i<1000000;i++)
        {
            if(i%2!=0)
            {
                dp[i]=min({dp[i],dp[i-1]+1,dp[i+1]+1});
            }
            else
            {
                dp[i]=min({dp[i],dp[i-1]+1,dp[i+1]+1,dp[i/2]+1});
            }
        }
        cout<<dp[k];
    }
}