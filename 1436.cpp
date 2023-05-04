#include <bits/stdc++.h>
using namespace std;
int cnt=0,n;
string s;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    
    cin>>n;

    for(int i=666; ;i++)
    {
        s=to_string(i);
        int size=s.length();

        for(int j=0;j<size-2;j++)
        {
            if(s[j]=='6')
            {
                if(s[j+1]=='6'&&s[j+2]=='6')
                {
                    cnt++;
                    break;
                }
            }
        }
        if(cnt==n)break;
    }

    cout<<s<<"\n";
}