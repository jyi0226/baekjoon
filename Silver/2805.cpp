#include <bits/stdc++.h>
using namespace std;
int n,m,wood[1010101];
long long sum,len=-1;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>wood[i];
    sort(wood,wood+n);
    
    long long start=0,end=wood[n-1],mid;
    while(start<=end)
    {
        sum=0;
        mid=(start+end)/2;

        for(int i=0;i<n;i++)
        {
            if(wood[i]-mid>0)sum+=(wood[i]-mid);
        }

        if(sum>m)
        {
            len=max(len,mid);
            start=mid+1;
        }
        else if(sum<m)
        
        {
            end=mid-1;
        }
        else
        {
            cout<<mid;
            return 0;
        }
    }
    cout<<len;
}
