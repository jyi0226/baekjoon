#include <iostream>
#include <algorithm>

using namespace std;
int arr[1010];
int dp[1010];
int dp2[1010];
int n,res=0;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=i-1;j>=1;j--){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    for(int i=n;i>=1;i--){
        dp2[i]=1;
        for(int j=i+1;j<=n;j++){
            if(arr[i]>arr[j]){
                dp2[i]=max(dp2[i],dp2[j]+1);
            }
        }
    }/*
    cout<<"\n";
    for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++)cout<<dp2[i]<<" ";
    cout<<"\n";*/
    for(int i=1;i<=n;i++){
        res=max(res,dp[i]+dp2[i]);
    }
    cout<<res-1;
}
