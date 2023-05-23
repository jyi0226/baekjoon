#include <bits/stdc++.h>
using namespace std;
int num[1010101],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int j=i;
        int sum=j+j%10;
        while(j>=10)
        {
            j/=10;
            sum+=(j%10);
        }
        if(num[sum]==0)num[sum]=i;
        else
        {
            num[sum]=min(num[sum],i);
        }
    }
    cout<<num[n];
    //for(int i=1;i<=n;i++)cout<<i<<" "<<num[i]<<endl;
}
