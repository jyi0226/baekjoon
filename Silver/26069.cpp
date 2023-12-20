#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
string s,s2;
map<string,int> m;
int n,cnt=1;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    m["ChongChong"]=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>s2;
        if(m[s]){
            if(m[s2])continue;
            m[s2]=1;
            cnt++;
        }
        else if(m[s2]){
            if(m[s])continue;
            m[s]=1;
            cnt++;
        }
    }
    cout<<cnt;
}
