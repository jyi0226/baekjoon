#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
string s;
map<string,int> mp;
int n,m;
bool cmp(pair<string,int> a,pair<string,int> b){
    if(a.second!=b.second){
        return a.second>b.second;
    }
    else{
        if(a.first.size()!=b.first.size()){
            return a.first.size()>b.first.size();
        }
        else{
            return a.first<b.first;
        }
    }
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s.size()<m)continue;
        if(mp[s]){
            mp[s]++;
        }
        else{
            mp[s]=1;
        }
    }
    vector<pair<string,int>> v(mp.begin(),mp.end());
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)cout<<v[i].first<<"\n";
}
