#include <bits/stdc++.h>
using namespace std;

int board[333][333];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>board[i][j];
        }
    }
    int t,a,b,c,d;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int result=0;
        cin>>a>>b>>c>>d;
        for(int j=a;j<=c;j++)
        {
            for(int k=b;k<=d;k++)
            {
                result+=board[j][k];
            }
        }
        cout<<result<<"\n";
    }
}