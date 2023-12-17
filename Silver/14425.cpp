#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<string,bool> mp;
int n,m,num;
string s;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        mp[s]=1;
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        cin>>s;
        if(mp[s])cnt++;
    }
    cout<<cnt;
}
