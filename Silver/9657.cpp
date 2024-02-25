#include <iostream>
#include <algorithm>
using namespace std;

bool dp[1010];
int n;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp[1]=1;dp[2]=0;dp[3]=1;dp[4]=1;dp[5]=1;
    cin>>n;
    for(int i=6;i<=n;i++){
        dp[i]=!(dp[i-1]&&dp[i-3]&&dp[i-4]);
    }
    if(dp[n])cout<<"SK";
    else cout<<"CY";
}
