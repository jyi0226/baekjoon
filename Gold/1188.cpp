#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    cout<<m-gcd(m,n);
}
