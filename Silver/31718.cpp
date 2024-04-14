#include <bits/stdc++.h>
using namespace std;
int res=0;
map<int,int> m;
int n,num;
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        while(num%2==0)num/=2;
        m[num]++;
        res=max(res,m[num]);
    }
    cout<<res;
}
