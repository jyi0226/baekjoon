#include <bits/stdc++.h>
using namespace std;
int num[3];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    for(int i=0;i<3;i++)cin>>num[i];
    while(num[0]!=0)
    {
        sort(num,num+3);
        if(num[0]*num[0]+num[1]*num[1]==num[2]*num[2])cout<<"right\n";
        else cout<<"wrong\n";
        for(int i=0;i<3;i++)cin>>num[i];
    }
}
