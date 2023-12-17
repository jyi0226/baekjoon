#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<string,bool> mp;
string s,a="";
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            a+=s[j];
            mp[a]=1;
        }
        a="";
    }
    cout<<mp.size();
}
