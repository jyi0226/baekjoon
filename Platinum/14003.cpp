#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int num[1010101];
int dp[1010101];
int n;
vector<int> v;
stack<int> s;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        if(v.empty()){
            v.push_back(num[i]);
            dp[i]=1;
        }
        else{
            if(v.back()<num[i]){
                v.push_back(num[i]);
                dp[i]=v.size();
            }
            else{
                int idx=lower_bound(v.begin(),v.end(),num[i])-v.begin();
                v[idx]=num[i];
                dp[i]=idx+1;
            }
        }
    }
    int idx=0,Max=0;
    for(int i=0;i<n;i++){
        if(dp[i]>Max){
            Max=dp[i];
            idx=i;
        }
    }

    s.push(num[idx]);
    for(int i=idx;i>=0;i--){
        if(dp[idx]==dp[i]+1){
            if(num[idx]>num[i]){
                s.push(num[i]);
                idx=i;
            }
        }
        
    }
    cout<<Max<<"\n";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
