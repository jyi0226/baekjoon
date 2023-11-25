#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t,n;
int board[101010][2];
int dp[101010][2];
int main()
{
    cin>>t;
    vector<int> v;
    for(int T=0;T<t;T++){
        cin>>n;
        for(int j=0;j<2;j++){
            for(int i=1;i<=n;i++){
                cin>>board[i][j];
            }
        }
        dp[0][0]=0;
        dp[0][1]=0;
        dp[1][0]=board[1][0];
        dp[1][1]=board[1][1];
        for(int i=2;i<=n;i++){
            dp[i][0]=max(dp[i-1][1],dp[i-2][1])+board[i][0];
            dp[i][1]=max(dp[i-1][0],dp[i-2][0])+board[i][1];
        }
        v.push_back(max(dp[n][0],dp[n][1]));
    }
    for(int i=0;i<t;i++)cout<<v[i]<<"\n";
}
