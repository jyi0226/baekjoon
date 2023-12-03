#include <iostream>
#include <queue>
using namespace std;
int n,k;
queue<int> q;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)q.push(i);
    cout<<"<";
    while(1){
        if(q.size()==1){
            cout<<q.front()<<">";
            return 0;
        }
        for(int i=1;i<k;i++){
            q.push(q.front());
            q.pop();
        }
        cout<<q.front()<<", ";
        q.pop();
    }
}
