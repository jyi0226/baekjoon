#include <iostream>
#include <deque>
using namespace std;
bool isWhat[101010];
int n,val,m;
deque<int> d;
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++)cin>>isWhat[i];
    for(int i=0;i<n;i++){
        cin>>val;
        if(!isWhat[i])d.push_front(val);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>val;
        d.push_back(val);
    }
    for(int i=0;i<m;i++){
        cout<<d.front()<<" ";
        d.pop_front();
    }
}
