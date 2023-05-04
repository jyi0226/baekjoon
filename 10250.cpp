#include <bits/stdc++.h>
using namespace std;
int t,h,w,n;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>h>>w>>n;
        if(n%h==0)
        {
            cout<<100*h+n/h<<"\n";
        }
        else
        {
            cout<<100*(n%h)+1+n/h<<"\n";
        }
    }
}