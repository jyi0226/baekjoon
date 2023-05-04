#include <bits/stdc++.h>
using namespace std;
int x,y,w,h;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>x>>y>>w>>h;
    int result=min({x,y,(w-x),(h-y)});
    cout<<result;
}
