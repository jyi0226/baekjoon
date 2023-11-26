#include <iostream>

using namespace std;
int dp[1010][10]={};
int n;
int main()
{
    cin>>n;
    for(int i=0;i<10;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<=j;k++){
                dp[i][j]+=(dp[i-1][k]%10007);
                
            }
            //cout<<dp[i][j]<<" ";
        }
    }
    int sum=0;
    for(int i=0;i<10;i++)sum+=(dp[n][i]%10007);
    cout<<sum%10007;
}
