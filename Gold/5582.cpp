#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a,b;
int res=0;
int lcs[4040][4040];
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>a>>b;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(a[i]==b[j])lcs[i+1][j+1]=lcs[i][j]+1;
            else lcs[i+1][j+1]=0;
            res=max(res,lcs[i+1][j+1]);
        }
    }
    cout<<res;
}
