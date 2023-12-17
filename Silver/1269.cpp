#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<int,bool> mp;
int n,m,num;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>num;
        mp[num]=1;
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        cin>>num;
        if(mp[num])cnt++;
    }
    cout<<n+m-2*cnt;
}
