#include <bits/stdc++.h>
using namespace std;

queue<int> pq,imp;
int s_imp[111];

bool comp(int a, int b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        queue<int> pq,imp;
        int s_imp[111];
        int n,m;
        cin>>n>>m;
        for(int j=0;j<n;j++)
        {
            int num;
            cin>>num;
            pq.push(j);
            imp.push(num);
            s_imp[j]=num;
        }
        sort(s_imp,s_imp+n,comp);
        for(int j=0;j<n;j++)
        {
            while(s_imp[j]!=imp.front())
            {
                int num=pq.front();
                int Imp=imp.front();
                pq.pop();
                imp.pop();
                pq.push(num);
                imp.push(Imp);
            }
            if(pq.front()==m)
            {
                cout<<j+1<<"\n";
                break;
            }
            else
            {
                pq.pop();
                imp.pop();
            }
        }
    }
}