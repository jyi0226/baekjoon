#include <iostream>
#include <algorithm>

using namespace std;
int arr[1010];
int dp[1010];
int n,res=0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>arr[i];
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=i-1;j>=1;j--){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(res,dp[i]);
    }
    cout<<res;
}
