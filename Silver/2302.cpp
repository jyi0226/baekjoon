#include <iostream>
using namespace std;

int dp[44];
int n,m,num[44];
int cnt=1;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    
    cin>>n>>m;
    for(int i=3;i<=n;i++)dp[i]=dp[i-1]+dp[i-2];
    for(int i=0;i<m;i++){
        cin>>num[i];
    }
    if(m==0){
        cout<<dp[n];
        return 0;
    }
    cnt*=dp[num[0]-1];
    for(int i=1;i<m;i++){
        cnt*=dp[num[i]-num[i-1]-1];
    }
    cnt*=dp[n-num[m-1]];
    
    cout<<cnt;
}
