#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int n;
string s[101];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=n-i;j>0;j--)s[i]+=' ';
        for(int j=1;j<=2*i-1;j++)s[i]+='*';
    }
    for(int i=1;i<=n;i++)cout<<s[i]<<"\n";
    for(int i=n-1;i>0;i--)cout<<s[i]<<"\n";
}
