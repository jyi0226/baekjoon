#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    char str[20202];
    int start=20;
    for(int i=0;i<start;i++)str[i]='0';
    int n,k;
    cin>>n>>k;
    int end = start+n;
    for(int i=start;i<end;i++)cin>>str[i];
    for(int i=end;i<start+end;i++)str[i]='0';
    //for(int i=0;i<end+start;i++)cout<<str[i];
    int cnt=0;
    for(int i=start;i<end;i++)
    {
        if(str[i]=='P')
        {
            for(int j=i-k;j<=i+k;j++)
            {
                if(str[j]=='H')
                {
                    str[j]='0';
                    str[i]='0';
                    cnt++;
                    break;
                }
            }
        }
    }
    cout<<cnt;
}
