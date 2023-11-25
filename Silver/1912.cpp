#include <iostream>
#include <algorithm>

using namespace std;
int num[101010];
int dp[101010];
int res;
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>num[i];
    dp[0]=num[0];
    res=num[0];
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1]+num[i],num[i]);
        res=max(res,dp[i]);
    }
    cout<<res;
}
