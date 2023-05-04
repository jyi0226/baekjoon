#include <bits/stdc++.h>
using namespace std;
int num[15][15],t,n,m;

int main()
{
    for(int i=0;i<15;i++)
    {
        num[0][i]=i;
    }
    for(int i=1;i<15;i++)
    {
        for(int j=1;j<15;j++)
        {
            for(int k=1;k<=j;k++)num[i][j]+=num[i-1][k];
        }
    }
    
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        cout<<num[n][m]<<"\n";
    }
}
