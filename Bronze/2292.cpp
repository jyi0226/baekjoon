#include <bits/stdc++.h>
using namespace std;
long long n,cnt=1,num=1;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n;
    while(num<n)
    {
        num=num+6*(cnt++);
    }
    cout<<cnt;
}
