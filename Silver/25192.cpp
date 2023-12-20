#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
string s;
map<string,int> m;
int n,cnt=0;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="ENTER"){
            m.clear();
        }
        else{
            if(m[s])continue;
            m[s]=1;
            cnt++;
        }
    }
    cout<<cnt;
}
