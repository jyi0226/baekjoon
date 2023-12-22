#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a,b;
int dp[505];
int n,res=0;
vector<pair<int,int>> v;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    v.push_back({0,0});
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=i-1;j>=1;j--){
            if(v[i].second>v[j].second){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        res=max(res,dp[i]);
    }
    cout<<n-res;
}
