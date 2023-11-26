#include <iostream>
#include <algorithm>
using namespace std;
string a,b;
int lcs[1010][1010];
int main()
{
    cin>>a>>b;
    string s1='0'+a;
    string s2='0'+b;
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            if(i==0||j==0){
                lcs[i][j]=0;
                continue;
            }
            if(s1[i]==s2[j]){
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
            else{
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    cout<<lcs[a.size()][b.size()];
}
