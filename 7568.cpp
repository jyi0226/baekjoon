#include <bits/stdc++.h>
using namespace std;

int compare(int a,int b)
{
    return a>b;
}

int n,x[55],y[55];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<n;i++)
    {
        int cnt=1;
        for(int j=0;j<n;j++)
        {
            if(x[i]<x[j]&&y[i]<y[j])cnt++;
        }
        cout<<cnt<<"\n";
    }
}