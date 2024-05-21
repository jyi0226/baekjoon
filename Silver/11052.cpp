#include <iostream>
using namespace std;

int n;
int dp[1010];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    dp[0]=0;
    for(int i=1;i<=n;i++)cin>>dp[i];
    
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i-j;j++){
            dp[i]=max(dp[i],dp[i-j]+dp[j]);
        }
    }
    cout<<dp[n];
}
