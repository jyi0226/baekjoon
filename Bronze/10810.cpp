#include <iostream>
using namespace std;
int n,m;
int a,b,c;
int num[101];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        for(int j=a;j<=b;j++)num[j]=c;
    }
    for(int i=1;i<=n;i++)cout<<num[i]<<" ";
}
