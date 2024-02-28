#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int num[1010101];
int dp[1010101];
int n;

vector<int> v;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        if(v.empty())v.push_back(num[i]);
        else{
            if(v.back()<num[i])v.push_back(num[i]);
            else v[lower_bound(v.begin(),v.end(),num[i])-v.begin()]=num[i];
        }
    }
    cout<<v.size();
}
