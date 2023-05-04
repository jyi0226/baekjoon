#include <bits/stdc++.h>
using namespace std;
string s[20202];
int n;

int compare(string a, string b)
{
    if(a.length()==b.length()) return a<b;
    else return a.length()<b.length();
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    sort(s,s+n,compare);
    for(int i=0;i<n;i++)
    {   
        if(s[i]==s[i-1])continue;
        else cout<<s[i]<<"\n";
    }
}