#include <bits/stdc++.h>
using namespace std;

int gua[5050]={0,};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    for(int i=2;i<=5000;i++)
    {
        int sum=0;
        for(int j=1;j<=i/2;j++)
        {
            if(i%j==0)sum+=j;
        }
        if(i<sum)gua[i]=1;
    }    
    //for(int i=2;i<=5000;i++)if(gua[i]==1)cout<<i<<"\n";
    for(int i=2;i<=5000;i++)
    {
        if(gua[i]==1)
        {
            for(int j=2;i*j<=5000;j++)gua[i*j]=0;
        }
    }

    int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        if(gua[n]==1)cout<<"Good Bye\n";
        else cout<<"BOJ 2022\n";
    }
}
