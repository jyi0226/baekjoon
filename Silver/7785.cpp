#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<string,int,greater<string>> mp;
int n;
string s,ord;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>ord;
        if(ord=="enter")mp[s]=1;
        else{
            if(mp[s])mp.erase(s);
        }
    }
    map<string,int>::iterator iter;
    for(iter=mp.begin();iter!=mp.end();++iter){
        cout<<iter->first<<"\n";
    }
}
