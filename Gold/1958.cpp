#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
string a,b,c;
int lcs[111][111][111];
int main()
{
    cin>>a>>b>>c;
    string s1=' '+a;
    string s2=' '+b;
    string s3=' '+c;
    int x=s1.size(),y=s2.size(),z=s3.size();
    for(int i=1;i<x;i++){
        for(int j=1;j<y;j++){
            for(int k=1;k<z;k++){
                if(s1[i]==s2[j]&&s2[j]==s3[k]){
                    lcs[i][j][k]=lcs[i-1][j-1][k-1]+1;
                }
                else{
                    lcs[i][j][k]=max({lcs[i-1][j][k],lcs[i][j-1][k],lcs[i][j][k-1]});
                }
            }
        }
    }
    cout<<lcs[x-1][y-1][z-1];
}
