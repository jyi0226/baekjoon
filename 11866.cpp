#include <bits/stdc++.h>
using namespace std;
int n,k;
deque<int> deq;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)deq.push_back(i);
    cout<<"<";
    while(deq.size()>1)
    {
        for(int i=1;i<k;i++)
        {
            int num=deq.front();
            deq.pop_front();
            deq.push_back(num);
        }
        cout<<deq.front()<<", ";
        deq.pop_front();
    }
    cout<<deq.front()<<">\n";
}