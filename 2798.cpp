#include <bits/stdc++.h>
using namespace std;
int n,m,res[303030],num[101];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>num[i];
    
    for(int a=0;a<n-2;a++)
    {
        for(int b=a+1;b<n-1;b++)
        {
            for(int c=b+1;c<n;c++)
            {
                res[num[a]+num[b]+num[c]]=1;
            }
        }
    }

    for(int i=m;i>=0;i--)
    {
        if(res[i]==1)
        {
            cout<<i;
            break;
        }
    }
}