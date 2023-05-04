#include <bits/stdc++.h>
using namespace std;

int num[1010101];
int order[1010101];


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    
    map<int,int> mp;

    int n;
    cin>>n;
    int n2=n;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        order[i]=num[i];
    }
    sort(order,order+n);
    for(int i=0;i<n;i++)
    {
        if(i!=n-1&&order[i]==order[i+1])
        {
            order[i]=1000000005;
            n2--;
        }
    }
    sort(order,order+n);
    int cnt=0;
    for(int i=0;i<n2;i++)
    {
        mp.insert({order[i],i});
    }
    for(int i=0;i<n;i++)
    {
        cout<<mp.at(num[i])<<" ";
    }

}