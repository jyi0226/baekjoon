#include <bits/stdc++.h>
using namespace std;
int n,m;
string name;
map<int,string> pok;
map<string,int> kop;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n>>m;
    
    for(int i=1;i<=n;i++)
    {
        cin>>name;
        pok.insert(make_pair(i,name));
        kop.insert(make_pair(name,i));
    }

    for(int i=0;i<m;i++)
    {
        string ques;
        cin>>ques;
        if(ques[0]<65)
        {
            cout<<pok[stoi(ques)]<<"\n";
        }
        else cout<<kop[ques]<<"\n";
    }
}