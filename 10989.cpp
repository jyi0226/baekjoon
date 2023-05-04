#include <bits/stdc++.h>
using namespace std;
int num[10101]={0, },n,m;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>m;
        num[m]+=1;
    }
    for(int i=1;i<10001;i++)
    {
        if(num[i]!=0)
        {
            while(num[i]!=0)
            {
                cout<<i<<"\n";
                num[i]-=1;
            }
        }
    }
}
