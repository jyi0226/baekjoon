#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    long long cnt=1,n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int I=i;
        while(I%10==0)
        {
            I/=10;
        }
        cnt*=I;
        if(cnt>100000)
        {
            while(cnt%10000==0)
            {
                cnt/=10;
            }
            cnt%=10;

        }
    }
    while(cnt%10==0)
        {
            cnt/=10;
        }
    cout<<cnt%10;
}
