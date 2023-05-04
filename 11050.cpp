#include <bits/stdc++.h>
using namespace std;
int n,m,a=1,b=1;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        a*=(n-i);
        b*=(i+1);
    }
    cout<<a/b;
}