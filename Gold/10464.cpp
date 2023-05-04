#include <bits/stdc++.h>
using namespace std;

int XOR(unsigned int a)
{
    if(a%4==0)return a;
    else if(a%4==3)return 0;
    else if(a%4==2)return a+1;
    else return 1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int s,f;
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>s>>f;
        cout<<(XOR(s-1)^XOR(f))<<"\n";
    }
}
