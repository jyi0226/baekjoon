#include <bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
char w[55];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n;
    
    for(int i=0;i<n;i++)cin>>w[i];
    
    for(int i=0;i<n;i++)
    {
        long long m=1;
        for(int j=0;j<i;j++)
        {
            m = (m*31)%1234567891;
        }
        sum=(sum+(w[i]-96)*m)%1234567891;
    }
    cout<<sum;
}
