#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int arr[1010];
int dp[1010];
int n,res=0;
int idx;
stack<int> s;

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
        if(dp[i]>res){
            res=dp[i];
            idx=i;
        }
    }
    s.push(arr[idx]);
    for(int j=idx-1;j>0;j--){
        if(dp[idx]==dp[j]+1){
            if(arr[idx]>arr[j]){
                s.push(arr[j]);
                idx=j;
            }
        }
    }
    cout<<res<<"\n";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
