#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int t,w;
int fall[1010];
int dp[1010][33][2];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>t>>w;
    for(int i=1;i<=t;i++)cin>>fall[i];
    for(int i=0;i<=w;i++){
        for(int j=1;j<=t;j++){
            if(i==0){
                dp[j][i][0]=dp[j-1][i][0]+(fall[j]==1);
            }
            else{
                dp[j][i][0]=max(dp[j-1][i][0],dp[j-1][i-1][1])+(fall[j]==1);
                dp[j][i][1]=max(dp[j-1][i][1],dp[j-1][i-1][0])+(fall[j]==2);
            }
        }
    }
    int Max=0;
    for(int i=0;i<=w;i++){
        for(int j=1;j<=t;j++)Max=max({dp[j][i][0],dp[j][i][1],Max});
    }
    cout<<Max;
}
