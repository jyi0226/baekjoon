#include <bits/stdc++.h>
using namespace std;
int a,b,v;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>a>>b>>v;
    int day=(v-b)/(a-b);
    if((v-b)%(a-b)!=0)day++;
    cout<<day;
}
